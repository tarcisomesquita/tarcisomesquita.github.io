// Emacs settings: -*- mode: Fundamental; tab-width: 4; -*-

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Sokoban in Javascript                                                  //
//                                                                        //
// Copyright (c) 2009-2016, Andrew Birrell                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////



//
// Global state
//

var levelsTxt = "";     // text description of current collection
var levelsName = "";    // name of current collection
var levels = null;      // current set of levels, as line arrays
var levelsDone = null;  // levels completed in current collection
var curLevel = -1;      // index into "levels"
var savedlevel = -1;    // level with state saved in a cookie
var width = 0;          // total columns in current level
var height = 0;         // total rows in current level
var scale = 1;          // pixels per square
var targets = null;     // square numbers of target squares
var initBoxes = null;   // square numbers of initial box positions
var initMan = -1;       // square number of initial man position
var floorState = null;  // what's in each floor square
var floorWall = "wall";
var floorFree = "passage";
var floorTarget = "target";
var floorWater = "water";
var thingState = null;  // what's on floor squares, not including the man
var thingWall = "#";    // also used when floorState is floorWater
var thingFree = "-";
var thingBox = "$";
var manElt = null;      // DOM element for the man who's doing the work
var manSq = -1;         // square number for the man who's doing the work
var selectedBox = -1;   // square with box that we want to move
var moves = 0;
var pushes = 0;
var neighbourCache = null; // optimizes "findPath" a lot

// Configuration options, initialized from the HTML in "init"
var speed = 9999;       // animation delay in msec

// Constants to optimize the choice of image tiles
var modulus = 5;        // textures repeat after "modulus" rows or columns
var granularity = 8;    // scale factor is multiple of "granularity"
var maxScale = 48;      // max pixels per square
var minScale = 16;      // min pixels per square

//
// Graphics
//

function thingUrl(sq) {
	// Return the URL for image at the given square,
	// assuming square is passage or target.
	//
	if (sq == selectedBox) return "img/selectedBox.jpg";
	if (thingState[sq] == thingBox) return "img/box.jpg";
	else return "img/blank.jpg";
}

function updateBoxImg(sq) {
	// Place image in "things" layer: box, selected box, or blank
	//
	document.getElementById("things" + sq).src = thingUrl(sq);
}

function selectBox(sq) {
	// flag this as the box we want to move, or -1 to deselect
	//
	var wasSelected = selectedBox;
	selectedBox = sq;
	if (wasSelected >= 0) updateBoxImg(wasSelected);
	if (selectedBox >= 0) updateBoxImg(selectedBox);
}

function moveBox(a, b) {
	// Jump the box at "a" to "b".
	//
	if (b == manSq) alert("Bug: moveBox, trampling man");
	if (thingState[a] != thingBox) alert("Bug: moveBox, not there");
	if (a != b) {
		if (thingState[b] != thingFree) alert("Bug: moveBox, occupied");
		thingState[a] = thingFree;
		thingState[b] = thingBox;
		updateBoxImg(a);
		updateBoxImg(b);
	}
}

function moveMan(sq) {
	// Jump the man to the given square, assumed to be vacant. Use -1 to
	// make man disappear.
	//
	if (!manElt) alert("No man DOM element");
	if (sq < 0) {
		if (manElt.style.display != "none") manElt.style.display = "none";
	} else {
		if (manElt.style.display == "none") {
			manElt.style.display = "inline-block";
		}
		manElt.style.top = "" + (Math.floor(sq / width) * scale) + "px";
		manElt.style.left = "" + (sq % width) * scale + "px";		
	}
	manSq = sq;
}

function floorStyle(sq, row, col) {
	// Return the CSS style for given floor square, based on floorState.
	//
	var sqState = floorState[sq];
	var sizing = "width: " + scale + "px; height: " + scale + "px";
	if (sqState == floorWater) {
		return sizing;
	} else {
		var color = (sqState == floorWall ? "#d0aea0" :
			(sqState == floorFree ? "#c18456" : "#402d1f"));
		var parity =
			(Math.floor(col / modulus) + Math.floor(row / modulus)) % 2;
		return sizing +
			"; background-color: " + color +
			"; background-image: url(img/" + sqState +
				"_w" + maxScale * modulus +
				"_h" + maxScale * modulus +
				"_x" + (parity == 0 ? 0 : maxScale * modulus) +
				"_y0_r" + (parity == 0 ? 0 : 90) +
			".jpg); background-position: -" +
				((col % modulus) * scale) + "px" +
				" -" + ((row % modulus) * scale) + "px";
	}
}

function highlightUrl(sq, row, col) {
	// Return the URL for highlight on given square.
	//
	// Server-side, this is done by compositing corners to create an
	// entire square's highlights.  There are 47 different composites.
	//
	// Each corner is specified by [0..4], indicating:
	//    0 ... both adjacent squares are empty
	//    1, 3, or 4 ... square ccw from corner is occupied
	//    2, 3, or 4 ... square cw from corner is occupied
	// In cases 0, 1 and 2, the diagonally adjacent square is
	// unspecified.  In 3 it's empty, producing an inside corner, and
	// in 4 it's occupied, producing a flat corner.
	//
	// To minimize the number of distinct images, we always create a
	// 128x128 highlight, and let the browser do the scaling (unlike the
	// other images, there's no texture scaling to worry about).
	//
	var tl = false;
	var tr = false;
	var bl = false;
	var br = false;
	var above = false;
	var left = false;
	var below = false;
	var right = false;
	if (row > 0) {
		above = (floorState[sq-width] == floorWall);
		if (above) {
			if (col > 0) tl = (floorState[sq-width-1] == floorWall);
			if (col < width-1) tr = (floorState[sq-width+1] == floorWall);
		}
	}
	if (row < height-1) {
		below = (floorState[sq+width] == floorWall);
		if (below) {
			if (col > 0) bl = (floorState[sq+width-1] == floorWall);
			if (col < width-1) br = (floorState[sq+width+1] == floorWall);
		}
	}
	if (col > 0) left = (floorState[sq-1] == floorWall);
	if (col < width-1) right = (floorState[sq+1] == floorWall);
	var tln = 0;
	var trn = 0;
	var bln = 0;
	var brn = 0;
	if (above) {
		tln += 2;
		trn += 1;
	}
	if (left) {
		tln += 1;
		bln += 2;
	}
	if (below) {
		bln += 1;
		brn += 2;
	}
	if (right) {
		trn += 2;
		brn += 1;
	}
	if (tln == 3 && tl) tln += 1;
	if (trn == 3 && tr) trn += 1;
	if (bln == 3 && bl) bln += 1;
	if (brn == 3 && br) brn += 1;
	return "img/highlights" + 
		"_tl" + tln +
		"_tr" + trn +
		"_bl" + bln +
		"_br" + brn + ".jpg";
}

function createImages() {
	// Create the grid of images for the playing area, appropriately scaled,
	// and apply to DIV.scene.
	//
	var scene = "<IMG SRC=\"img/man.jpg\"" +
		" STYLE=\"width: " + scale + "px; height: " + scale + "px\"" +
		" ID=man>";
	for (var row = 0; row < height; row++) {
		if (row > 0) scene += "<BR>";
		for (var col = 0; col < width; col++) {
			var sq = row * width + col;
			var sqState = floorState[sq];
			scene += "<IMG STYLE=\"" + floorStyle(sq, row, col) + "\"" +
				" SRC=\"" +
					(sqState == floorWall ? highlightUrl(sq, row, col) :
						thingUrl(sq)) + "\"" +
					" ID=things" + (row * width + col) +
					">";
		}
	}
	var sceneElt = document.getElementById("scene");
	sceneElt.innerHTML = scene;
	sceneElt.style.width = "" + (width * scale) + "px";
	adbab.xableControl("magnify", scale < maxScale);
	adbab.xableControl("shrink", scale > minScale);
	manElt = document.getElementById("man");
	moveMan(manSq);
}

function boundScale(targetScale) {
	// Return scale bounded by [minScale, maxScale]
	//
	return Math.min(maxScale, Math.max(minScale, targetScale));
}

function scaleFromWindow() {
	// Return scale based on current window size.
	//
	var wSize = adbab.windowSize();
	var board = document.getElementById("board");
	var boardPos = adbab.getElementPos(board)
	var maxWidth = board.clientWidth;
	var maxHeight = wSize.y - boardPos.y - 16; // "16" is body bottom-margin
	var xScale =
		granularity * Math.floor(maxWidth / (granularity * width));
	var yScale =
		granularity * Math.floor(maxHeight / (granularity * height));
	return boundScale(Math.min(xScale, yScale));
}

function doResize() {
	var newScale = scaleFromWindow();
	if (newScale != scale) {
		scale = newScale;
		createImages();
	}
}

function changeScale(delta) {
	// Change current scale by delta increments/decrements of "granularity".
	// Assumes "maxScale" is multiple of "granularity", but not "minScale".
	//
	scale = boundScale(
		(Math.floor(scale/granularity) + delta) * granularity);
	createImages();
	return false;
}

function showScore() {
	// Display the current score
	//
	document.getElementById("score").innerHTML =
		"Moves: " + moves + ",&nbsp;&nbsp;pushes: " + pushes;
}

function setSokoCookie(key, value) {
	// Set a persistent cookie
	//
	var date = new Date();
	date.setTime(date.getTime() + (365.25*24*60*60*1000));
	adbab.deleteCookie(key); // delete archaic path-less cookie, if any
	adbab.setCookie(key, value, date, window.location.pathname);
}

function deleteSokoCookie(key) {
	// Delete a cookie
	//
	adbab.deleteCookie(key); // delete archaic path-less cookie, if any
	adbab.deleteCookie(key, window.location.pathname);
}

function saveState() {
	// Save current board state in a cookie.
	//
	if (levelsName && curLevel >= 0) {
		var boxState = [];
		for (var i = 0; i < width * height; i++) {
			if (thingState[i] == thingBox) boxState.push(i);
		}
		var undoState = [];
		for (var i = 0; i < undoList.length; i++) {
			var u = undoList[i];
			if (u.a != u.b) {
				undoState.push(u.a + " " + u.b + " " + u.manSq +
							" " + u.moves + " " + u.pushes);
			}
		}
		for (var i = 0; i < redoList.length; i++) {
			var u = redoList[i];
			if (u.a != u.b) {
				undoState.push(u.a + " " + u.b + " " + u.manSq +
							" " + u.moves + " " + u.pushes);
			}
		}
		var parts = [];
		parts.push(manSq);
		parts.push(boxState.join(","));
		parts.push(moves);
		parts.push(pushes);
		parts.push(undoList.length);
		parts.push(undoState.join(","));
		parts.push(curLevel);
		var savedState =  parts.join("/");
		setSokoCookie("sokoState-" + levelsName, savedState);
		savedLevel = curLevel;
	}
}

function saveDone() {
	// Save levelsDone into a cookie
	//
	if (levelsName) {
		var doneList = [];
		for (var i = 0; i < levelsDone.length; i++) {
			if (levelsDone[i]) {
				var start = i;
				while (levelsDone[i+1]) i++;
				doneList.push(i == start ? i : "" + start + "-" + i);
			}
		}
		if (doneList.length == 0) {
			deleteSokoCookie("sokoDone-" + levelsName);
		} else {
			setSokoCookie("sokoDone-" + levelsName, doneList.join(","));
		}
	}
}

function placeBoxes(boxList) {
	// Place boxes in thingState according to "boxList". Assumes there are
	// no existing boxes in thingState.
	//
	for (var i = 0; i < boxList.length; i++) {
		thingState[boxList[i]] = thingBox;
	}
}

function terminateLevel() {
	// Dispose of state related to existing level, if any.
	//
	selectBox(-1);
	manCurRoute = null;
	boxCurRoute = null;
	eraseUndo();
	pushes = 0;
	moves = 0;
	showScore();
}

function startLevel(level) {
	// Start given level of current collection
	//
	if (level < 0 || level >= levels.length) return false;
	terminateLevel();
	curLevel = level;
	adbab.option.setValue("levels", curLevel);
	adbab.xableControl("nextLevel", curLevel+1 < levels.length);
	adbab.xableControl("prevLevel", curLevel > 0);
	adbab.xableControl("nextUnfinished", false);
	for (var i = curLevel+1; i < levels.length; i++) {
		if (!levelsDone[i]) {
			adbab.xableControl("nextUnfinished", true);
			break;
		}
	}
	if (levelsName) {
		setSokoCookie("sokoCollection", levelsName);
		setSokoCookie("sokoLevel-" + levelsName, "" + curLevel);
	}
	
	// Create floorState, initBoxes and initMan from level description
	// Set thingState to thingFree or thingWall as appropriate
	var levelLines = levels[level];
	width = 1;
	for (var row = 0; row < levelLines.length; row++) {
		width = Math.max(width, levelLines[row].length);
	}
	height = Math.max(1, levelLines.length);
	initBoxes = [];
	floorState = [];
	thingState = [];
	neighbourCache = [];
	targets = [];
	for (var row = 0; row < levelLines.length; row++) {
		var line = levelLines[row];
		var col;
		for (col = 0; col < line.length; col++) {
			var sq = row * width + col;
			var c = line.charAt(col);
			thingState[sq] = thingFree;
			if (c == "-" || c == " " || c == "_") {
				floorState[sq] = floorFree;
			} else if (c == "#") {
				floorState[sq] = floorWall;
				thingState[sq] = thingWall;
			} else if (c == "." || c == "o") {
				floorState[sq] = floorTarget;
				targets.push(sq);
			} else if (c == "$" || c == "b") {
				floorState[sq] = floorFree;
				initBoxes.push(sq);
			} else if (c == "*" || c == "B") {
				floorState[sq] = floorTarget;
				initBoxes.push(sq);
				targets.push(sq);
			} else if (c == "@" || c == "p") {
				floorState[sq] = floorFree;
				initMan = sq;
			} else if (c == "+" || c == "P") {
				floorState[sq] = floorTarget;
				targets.push(sq);
				initMan = sq;
			}
		}
		for (j = col; j < width; j++) {
			var sq = row * width + j;
			floorState[sq] = floorFree;
			thingState[sq] = thingFree;
		}
	}

	// Turn external non-wall squares into water, using a flood-fill
	// algorithm (of course).  Also floods the passages if the external
	// walls have a leak.

	var wTouch = []; // squares that we've already looked at
	var wQueue = []; // queue of squares we need to look at
	
	// Initialise the queue with the perimeter squares
	for (var row = 1; row < height-1; row++) {
		var left = row * width;
		wQueue.push(left);
		wQueue.push(left+width-1);
	}
	var botLeft = (levelLines.length-1) * width;
	for (var col = 0; col < width; col++) {
		wQueue.push(col);
		wQueue.push(botLeft + col);
	}

	// Perform the flood
	while (wQueue.length > 0) {
		var sq = wQueue.shift();
		if (!wTouch[sq]) {
			wTouch[sq] = true;
			if (floorState[sq] != floorWall) {
				floorState[sq] = floorWater;
				thingState[sq] = thingWall;
			}
			if (floorState[sq] == floorWater) {
				var n = neighbours(sq);
				for (var i = 0; i < 4; i++) {
					if (n[i] >= 0) wQueue.push(n[i]);
				}
			}
		}
	}

	// Set thingState for non-walls, and manSq, from one of:
	//    saved state, done position, initial state
	var savedState = adbab.getCookie("sokoState-" + levelsName);
	var savedParts;
	if (savedState) {
		savedParts = savedState.split("/");
		savedLevel = parseInt(savedParts.pop());
	}
	if (savedState && savedLevel == curLevel) {
		var undoStateStr = savedParts.pop();
		var undoState = (undoStateStr == "" ? [] :
												undoStateStr.split(","));
		var undoLength = parseInt(savedParts.pop());
		pushes = parseInt(savedParts.pop());
		moves = parseInt(savedParts.pop());
		placeBoxes(savedParts.pop().split(","));
		manSq = parseInt(savedParts.pop());
		for (var i = 0; i < undoState.length; i++) {
			var undoParts = undoState[i].split(" ");
			var action = new UndoState(
							parseInt(undoParts[0]), parseInt(undoParts[1]));
			action.manSq = parseInt(undoParts[2]);
			action.moves = parseInt(undoParts[3]);
			action.pushes = parseInt(undoParts[4]);
			if (i < undoLength) {
				undoList.push(action);
			} else {
				redoList.push(action);
			}
		}
		if (!levelsDone[curLevel] && allTargetsDone()) {
			levelsDone[curLevel] = true;
			saveDone();
			// ... presumably we crashed before calling saveDone
		}
		if (levelsDone[curLevel]) {
			if (redoList.length > 0) alert("Bug: excess redoList");
		}
		showScore();
		adbab.xableControl("restart", undoList.length > 0);
		adbab.xableControl("undo", undoList.length > 0);
		adbab.xableControl("redo", redoList.length > 0);
	} else if (levelsDone[curLevel]) {
		placeBoxes(targets);
		manSq = -1;
		adbab.xableControl("restart", true);
	} else {
		placeBoxes(initBoxes);
		manSq = initMan;
	}
	
	// Update the display
	scale = scaleFromWindow();
	createImages();
	return false;
}

function selectLevel() {
	// Action in the "levels" selector
	//
	var levelNum = parseInt(adbab.option.getValue("levels"));
	return (levelNum != curLevel && startLevel(levelNum));
}

function nextUnfinished() {
	// Go to the next unfinished level, if any
	//
	for (var i = curLevel+1; i < levels.length; i++) {
		if (!levelsDone[i]) {
			startLevel(i);
			break;
		}
	}
}

function neighbours(sq) {
	// Returns an array containing the neighbouring squares of "sq",
	// excluding walls.
	//
	// There are 4 entries, one for each side.  Entry is >= 0 if there
	// is an in-bounds neighbouring square there.  (The flood-fill code in
	// "startLevel" relies on the "in-bounds" condition.)
	//
	// Index 3-i is the neighbour opposite to index i.
	//
	var c = neighbourCache[sq];
	if (c) return c;
	var n = [];
	var row = Math.floor(sq/width);
	var col = sq - row * width;
	n[0] = (row > 0 ? sq-width : -1);
	n[3] = (row < height-1 ? sq+width : -1);
	n[1] = (col > 0 ? sq-1 : -1);
	n[2] = (col < width-1 ? sq+1 : -1);
	for (var i = 0; i < 4; i++) {
		if (floorState[n[i]] == floorWall) n[i] = -1;
	}
	neighbourCache[sq] = n;
	return n;
}


//
// Interaction
//

function allTargetsDone() {
	// Return true iff there are no empty target squares.  In an incorrect
	// level design, there might nevertheless be boxes not on targets: we
	// silently ignore that.
	//
	if (targets) {
		for (var i = 0; i < targets.length; i++) {
			if (thingState[targets[i]] == thingFree) return false;
		}
	}
	return true;
}

function findPath(a, b, justChecking) {
	// Find shortest legal path for a man at "a" moving to "b", b!=a.
	// Says nothing about the contents of "a" or "b".
	//
	// If "justChecking", returns length of the path, or 0; otherwise
	// returns an array containing the path (with "b" but not "a"), or null.
	//
	// This uses a simple expanding search on a graph. The graph nodes are
	// possible positions of the man, and there's an arc to another node iff
	// the other node is empty and adjacent.
	//
	// At the start of generation N of the search (N is initially 1), the
	// object "srce" has properties named by each of the nodes whose
	// distance from "a" is less than N; the array "thisGen" contains the
	// nodes whose distance from "a" is exactly N-1; and the array "nextGen"
	// is empty.
	//
	// For each node in "thisGen" we consider its neighbours. If the
	// neighbour is "b" we're done. If the neighbour is already a property
	// name in "srce" then we already have a shorter (or equal) path to the
	// neighbour and we can ignore it. Otherwise the neighbour's shortest
	// path from "a" is length N, and we add the neighbour as a property
	// name of "srce" and as an element of "nextGen".
	//
	// When we've examined everything in "thisGen" then this generation is
	// finished. If "nextGen" is empty, then there's no path from "a" to
	// "b". Otherwise we move on to the next generation, using "nextGen" as
	// the new "thisGen" and setting up a new empty "nextGen".
	//
	// The value of "srce[X]" is the node one closer on the shortest path
	// to X from "a". This allows us to enumerate the final shortest path by
	// iterating over "srce" starting at the node whose neighbour is "b".
	//
	var srce = {};
	var thisGen = [];
	var nextGen = [];
	if (a >= 0) {
		srce[a] = "origin";
		thisGen.push(a);
	}
	while (true) {
		if (thisGen.length == 0) {
			// no more nodes at this distance: move to the next generation
			if (nextGen.length > 0) {
				var temp = thisGen;
				thisGen = nextGen;
				nextGen = temp;
			} else {
				return (justChecking ? 0 : null);
			}
		}
		var sPos = thisGen.pop();
		var n = neighbours(sPos);
		for (var i = 0; i < 4; i++) {
			var neighbour = n[i];
			if (neighbour < 0 || neighbour in srce) {
				// out of bounds or we already have a shorter or equal path
			} else if (neighbour == b) {
				// success: build the route and exit.
				var route = [neighbour];
				var pos = sPos;
				while (pos != a) {
					route.push(pos);
					pos = srce[pos];
				}
				return (justChecking ? route.length : route.reverse());
			} else if (thingState[neighbour] == thingFree) {
				srce[neighbour] = sPos;
				nextGen.push(neighbour);
			}
		}
	}
}

function oppositeNeighbour(sq, neighbour) {
	// If "neighbour" is adjacent to "sq", return square on the opposite
	// side of "sq"; else return -1.  Doesn't do bounds checking: there's a
	// perimeter wall, and thingState[sq] is "undefined" if sq is out of
	// bounds.
	//
	return (neighbour == sq - 1 ? sq + 1 :
				(neighbour == sq + 1 ? sq - 1 :
					(neighbour == sq-width ? sq + width :
						(neighbour == sq+width ? sq - width : -1))));
}

function findBoxPath(a, b) {
	// Find the shortest path to push a box from "a" to "b", from "manSq".
	// Assumes there's a box at "a", and fails if there's one already at "b"
	//
	// This uses the same graph search algorithm as "findPath", but the
	// graph is rather different.  The nodes are a box position combined
	// with a man position.  There's an arc to another node iff one of:
	//   a) the other node is the same box position, with a man position
	//      that's reachable from this node's man position (i.e. we can
	//      move the man to it), or
	//   b) this node's man is adjacent to this node's box, and the other
	//      node's box position is adjacent to this node's box position and
	//      opposite to this node's man position (i.e. we can push to it).
	//
	// This supports paths where we must push a box through a narrow
	// passage then back again in order to get the man around to the other
	// side of the box.  The simpler notion of a graph of merely box
	// positions doesn't handle that case.
	//
	// "srceMoves" has properties named by node, whose value is the number
	// of man moves to reach the node.  This lets us choose among the
	// shortest paths the one with the least number of man moves.
	//
	var srce = {};
	var srcePushes = {};
	var srceMoves = {};
	var pushes = -1;
	var thisGen = [];
	var nextGen = [];
	var posExp = /^([^-]*)-.*$/;
	var manExp = /^[^-]*-(.*)$/;
	var startNode = "" + a + "-" + manSq;
	var finalNode = null;
	srce[startNode] = "origin";
	srcePushes[startNode] = 0;
	srceMoves[startNode] = 0;
	nextGen.push(startNode);
	// During the algorithm, we pretend our box is at the current node,
	// not at "a".  This gets undone before returning.
	thingState[a] = thingFree;
	while (true) {
		if (thisGen.length == 0) {
			// no more nodes at this distance
			if (finalNode) {
				// success: construct and return the route
				var route = [];
				route.push(b);
				var node = finalNode;
				while (true) {
					var nodePos = parseInt(node.replace(posExp, "$1"));
					if (nodePos != route[route.length-1]) {
						route.push(nodePos);
					}
					if (node == startNode) break;
					node = srce[node];
				}
				// Remove "a" from the route
				route.pop();
				thingState[a] = thingBox;
				return route.reverse();
			} else if (nextGen.length == 0) {
				// failure
				thingState[a] = thingBox;
				return null;
			}
			var temp = thisGen;
			thisGen = nextGen;
			nextGen = temp;
			pushes++;
			// Before considering any of thisGen, add on adjacent squares
			// reachable by the man.
			var genLen = thisGen.length; // thisGen changes during the loop
			for (var i = 0; i < genLen; i++) {
				var xNode = thisGen[i];
				var xPos = parseInt(xNode.replace(posExp, "$1"));
				var xMan = parseInt(xNode.replace(manExp, "$1"));
				var xLen = srceMoves[xNode];
				thingState[xPos] = thingBox;
				var n = neighbours(xPos);
				for (var j = 0; j < 4; j++) {
					var neighbour = n[j];

					if (neighbour >= 0 && neighbour != xMan &&
									thingState[neighbour] == thingFree) {
						var oppSq = n[3-j];
						if (oppSq >= 0 && thingState[oppSq] == thingFree) {
							var nNode = "" + xPos + "-" + neighbour;
							var nextLen = findPath(xMan, neighbour, true);
							var len = xLen + nextLen;
							var missing = (srce[nNode] === undefined);
							if (nextLen > 0 && (missing ||
									(pushes == srcePushes[nNode] &&
										len < srceMoves[nNode]))) {
								if (missing) {
									thisGen.push(nNode);
									srcePushes[nNode] = pushes;
								}
								srce[nNode] = xNode;
								srceMoves[nNode] = len;
							}

						}
					}
				}
				thingState[xPos] = thingFree;
			}

		}
		var thisNode = thisGen.pop();
		var thisPos = parseInt(thisNode.replace(posExp, "$1"));
		var thisMan = parseInt(thisNode.replace(manExp, "$1"));
		var pushDest = oppositeNeighbour(thisPos, thisMan);
		if (thingState[pushDest] == thingFree) {
			var destNode = "" + pushDest + "-" + thisPos;
			var len = srceMoves[thisNode] + 1;
			if (pushDest == b) {
				// Got there; but we need to finish this generation in case
				// there's a path with fewer man moves.
				// Note that since we're not going to do another generation,
				// finalNode, if any, necessarily has the same number of
				// pushes as us.
				if (!finalNode || len < srceMoves[finalNode]) {
					finalNode = destNode;
					srce[destNode] = thisNode;
					srceMoves[destNode] = len;
				}
			} else {
				var missing = !(destNode in srce);
				if (missing || ((pushes+1) == srcePushes[destNode] &&
											len < srceMoves[destNode])) {
					if (missing) {
						nextGen.push(destNode);
						srcePushes[destNode] = pushes + 1;
					}
					srce[destNode] = thisNode;
					srceMoves[destNode] = len;
				}
			}
		}
	}
	alert("Bug: findBoxPath drop through");
}

var manCurRoute = null; // route for man-move animation
var boxCurRoute = null; // route for box-move animation
var boxCurSq = -1;      // box location for next animation move

function routeMan() {
	// If speed == 0, jump man to the end of manCurRoute, and do the score
	// accounting.  Doesn't schedule anything else in this case.
	//
	// If speed != 0, move man one step along boxCurRoute. If there's more
	// route, schedule next step; otherwise schedule a call of routeBox.
	//
	if (manCurRoute) {
		if (manCurRoute.length == 0) alert("Bug: empty man route");
		if (manCurRoute[0] == -1) moves--; // move to -1 is free
		if (speed == 0) {
			moves += manCurRoute.length;
			moveMan(manCurRoute.pop());
			manCurRoute = null;
		} else {
			moves++;
			moveMan(manCurRoute.shift());
			if (manCurRoute.length > 0) {
				setTimeout(routeMan, speed);
			} else {
				manCurRoute = null;
				if (boxCurRoute) setTimeout(routeBox, speed);
			}
		}
		showScore();
	}
}

function routeBox() {
	// If speed == 0, move box from boxCurSq to end of boxCurRoute, and man
	// to the appropriate final position, doing all the score accounting.
	//
	// If speed != 0, initiate a step in moving from boxCurSq along
	// boxCurRoute; this might move the box, or just route the man to the
	// appropriate pushing spot (in which case routeMan will schedule
	// another call of routeBox when the man arrives).
	//
	// The outer "while" handles iteration when speed==0, as well as
	// abandoning a deferred task if boxCurRoute gets cancelled (by undo,
	// etc).
	//
	var startNext = (function() {
		var fromCollection = levels;
		var fromLevel = curLevel;
		return function() {
			if (levels == fromCollection && curLevel == fromLevel &&
					redoList.length == 0) {
				startLevel(curLevel+1);
			}
		};
	})();
	while (boxCurRoute) {
		if (boxCurRoute.length == 0) {
			alert("Bug: empty box route");
			boxCurRoute = null;
		}
		var pos = boxCurRoute[0];
		var opposite = oppositeNeighbour(boxCurSq, pos);
		if (opposite < 0) {
			alert("Bug: next pos not adjacent in routeBox");
			boxCurRoute = null;
		} else if (opposite == manSq) {
			boxCurRoute.shift();
			selectBox(-1);
			moveBox(boxCurSq, pos);
			moveMan(boxCurSq);
			boxCurSq = pos;
			pushes++;
			moves++;
			showScore();
			if (boxCurRoute.length > 0) {
				if (speed != 0) {
					setTimeout(routeBox, speed);
					break;
				} // else iterate around our outer loop
			} else {
				saveState();
				boxCurRoute = null; // also terminates our outer loop
				if (allTargetsDone()) {
					levelsDone[curLevel] = true;
					saveDone();
					if (curLevel+1 < levels.length) {
						setTimeout(startNext, 500);
					}
				}
				adbab.xableControl("redo", redoList.length > 0);
			}
		} else {
			manCurRoute = findPath(manSq, opposite, false);
			if (!manCurRoute) {
				alert("Bug: no route for man from " + manSq +
						" to " + opposite);
				boxCurRoute = null;
			} else {
				routeMan();
			}
			if (speed != 0) break; // else iterate for next box move
		}
	}
}

function sqClick(event) {
	// Respond to mouse click in a square
	//
	if (!event) event = window.event; // IE versus the rest
	var eltPos = adbab.getElementPos(document.getElementById("scene"));
	var mouse = adbab.getMousePos(event);
	var x = mouse.x - eltPos.x;
	var y = mouse.y - eltPos.y;
	var row = Math.floor(y / scale);
	var col = Math.floor(x / scale);
	if (row >= 0 && row < height && col >= 0 && col < width) {
		var sq = row * width + col;
		var thing = thingState[sq];
		if (manCurRoute || boxCurRoute) {
			// Ignore clicks during the animation
		} else if (thing == thingBox) {
			if (selectedBox < 0 && savedLevel >= 0 &&
						savedLevel != curLevel && !levelsDone[savedLevel]) {
				alert("Warning: if you make a move in this level, you " +
					"will abandon the game in progress at level " +
					(savedLevel+1));
			}
			selectBox(sq == selectedBox ? -1 : sq);
		} else if (selectedBox >= 0) {
			if (thing == thingFree) {
				boxCurRoute = findBoxPath(selectedBox, sq);
				boxCurSq = selectedBox;
				if (boxCurRoute) {
					record(selectedBox, sq);
					routeBox();
				} else {
					selectBox(-1);
				}
			} else {
				selectBox(-1);
			}
		} else if (manSq != sq && thing == thingFree) {
			manCurRoute = findPath(manSq, sq, false);
			if (manCurRoute) {
				record(sq, sq);
				routeMan();
			}
		}
	}
	return false;
}

function showHideDlog(id, show) {
	// Show or hide a dialog (e.g. help or design)
	//
	adbab.showHide("normalControls", !show);
	adbab.showHide("scene", !show);
	if (manSq >= 0) adbab.showHideInline("man", !show);
	adbab.showHide(id, show);
}

function showHideDesign(show) {
	showHideDlog("design", show);
	adbab.showHide("designControls1", show);
}

function startDesign() {
	// From playing, go to design edit dialog
	//
	showHideDesign(true);
	document.getElementById("designContents").value =
										levels[curLevel].join("\n");
	return false;
}

function playDesign() {
	// From design edit dialog, start play
	//
	showHideDesign(false); // display board before calling "adoptCollection"
	adbab.showHideInline("designControls2", true);
	adbab.showHideInline("collections", false);
	adoptCollection(document.getElementById("designContents").value);
	return false;
}

function perhapsAbandonDesignEdit() {
	// From design edit, ask for confirmation
	//
	adbab.showHide("designControls1", false);
	adbab.showHide("designControls4", true);
	return false;
}

function dontAbandonDesignEdit() {
	// Confirmation denied, return to design edit
	//
	adbab.showHide("designControls1", true);
	adbab.showHide("designControls4", false);
	return false;
}

function perhapsAbandonDesign() {
	// From design play, ask for confirmation
	//
	adbab.showHideInline("designControls2", false);
	adbab.showHideInline("designControls3", true);
	return false;
}

function dontAbandonDesign() {
	// Confirmation denied, return to design play
	//
	adbab.showHideInline("designControls2", true);
	adbab.showHideInline("designControls3", false);
	return false;
}

function abandonDesign() {
	// Resume normal service. Works from normal design play, or from
	// confirmation state, or from design edit state.
	//
	showHideDesign(false);
	adbab.showHideInline("designControls2", false);
	adbab.showHideInline("designControls3", false);
	adbab.showHide("designControls4", false);
	adbab.showHideInline("collections", true);
	initSelCollection();
	return false;
}

function showHideHelp(show) {
	showHideDlog("help", show);
	adbab.showHide("helpControls", show);
	return false;
}

function changeSpeed() {
	// change in the "speeds" menu
	//
	var newS = parseInt(adbab.option.getValue("speeds"));
	if (newS != speed) {
		speed = newS;
		setSokoCookie("sokoSpeed", "" + speed);
	}
	return false;
}

function showHideHistory(show) {
	// Show or hide history dialog
	//
	showHideDlog("history", show);
	adbab.showHide("historyControls", show);
}

function computeHistory() {
	// Return text describing the current history.  Omits records that move
	// only the man.
	//
	var undoState = [];
	for (var i = 0; i < undoList.length; i++) {
		var u = undoList[i];
		if (u.a != u.b) undoState.push("" + u.a + "-" + u.b);
	}
	if (redoList.length > 0) {
		undoState.push("Redo");
		for (var i = redoList.length-1; i >= 0; i--) {
			var u = redoList[i];
			if (u.a != u.b) undoState.push("" + u.a + "-" + u.b);
		}
	}
	return undoState.join("\n");
}

function startHistory() {
	document.getElementById("historyContents").value = computeHistory();
	showHideHistory(true);
	return false;
}

function doneHistory() {
	// Exit from history dialog
	//
	showHideHistory(false); // display board before calling "restart"
	var s = document.getElementById("historyContents").value;
	s = s.replace(/\r\n/g, "\n");
	s = s.replace(/\r/g, "\n");
	if (s != computeHistory()) {
		undoList.length = 0;
		redoList.length = 0;
		var moves = s.split("\n");
		for (var i = moves.length-1; i >= 0; i--) {
			var move = moves[i];
			if (move.match(/^\s*[0-9]+\s*-\s*[0-9]+\s*$/)) {
				var ab = move.split("-");
				redoList.push(
					new UndoState(parseInt(ab[0]), parseInt(ab[1])));
			} else if (move != "Redo" && move != "") {
				alert("Syntax error in the history list");
				return false;
			}
		}
		restart();
	}
	return false;
}

function showCookies() {
	// Mostly a debugging aid.
	//
	var cc = document.cookie.split(";").sort();
	var s = "" + cc.length + " cookies, " +
				document.cookie.length + " chars\n";
	s += "level: " + adbab.getCookie("sokoLevel-" + levelsName) + "\n";
	var done = adbab.getCookie("sokoDone-" + levelsName);
	if (done) {
		s += "done: " + done + "\n";
	} else {
		s += "no levels done\n";
	}
	var state = adbab.getCookie("sokoState-" + levelsName);
	if (state) {
		var stateParts = state.split("/");
		s += "saved level: " + stateParts.pop();
		var undoState = stateParts.pop();
		if (undoState) {
			s += ", " + undoState.split(",").length + " moves";
		}
		s += "\n";
	} else {
		s += "no saved state\n";
	}
	for (var i = 0; i < cc.length; i++) {
		var kv = cc[i].split("=");
		var key = kv[0].replace(/^\s*(.*)$/, "$1");
		var value = adbab.getCookie(key);
		s += key + "=" + value.substr(0, 20) +
			(value.length > 20 ? "..." : "") + "\n";
	}
	alert(s);
	return false;
}


//
// Undo/redo
//

var undoList = [];
var redoList = [];

function UndoState(a, b) {
	// Constructor to undo moving box from "a" to "b", or moving man to "b"
	// (in which case "a" equals "b").
	//
	this.a = a;
	this.b = b;
	this.manSq = manSq;
	this.moves = moves;
	this.pushes = pushes;
}

function record(a, b) {
	// Record action in undo state
	//
	undoList.push(new UndoState(a, b));
	redoList.length = 0;
	adbab.xableControl("restart", true);
	adbab.xableControl("undo", true);
	adbab.xableControl("redo", false);
}

function eraseUndo() {
	// Erase undo state at start or end of a level
	//
	undoList.length = 0;
	redoList.length = 0;
	adbab.xableControl("restart", false);
	adbab.xableControl("undo", false);
	adbab.xableControl("redo", false);
}

function restart() {
	// Restart the current level
	//
	while (undoList.length > 0) redoList.push(undoList.pop());
	var myRedo = redoList;
	redoList = []; // keep terminateLevel out of myRedo
	terminateLevel();
	if (levelsDone[curLevel]) {
		levelsDone[curLevel] = false;
		saveDone();
	}
	for (var sq = 0; sq < width * height; sq++) {
		if (thingState[sq] == thingBox) {
			thingState[sq] = thingFree;
			updateBoxImg(sq);
		}
	}
	moveMan(-1)
	// Now set up the initial position, plus our saved redo list
	placeBoxes(initBoxes);
	for (var i = 0; i < initBoxes.length; i++) {
		updateBoxImg(initBoxes[i]);
	}
	moveMan(initMan);
	if (myRedo.length > 0) {
		// Note: this might implicitly abandon another saved level. That
		// happens only in response to editting a history in a non-saved
		// level.
		redoList = myRedo;
		saveState();
	} else if (savedLevel == curLevel) {
		deleteSokoCookie("sokoState-" + levelsName);
		savedLevel = -1;
	}
	adbab.xableControl("redo", redoList.length > 0);
	return false;
}

function undo() {
	// Undo most recent box or man move (no animation)
	//
	if (undoList.length > 0) {
		var action = undoList.pop();
		redoList.push(action);
		adbab.xableControl("redo", true);
		if (undoList.length == 0) {
			adbab.xableControl("restart", false);
			adbab.xableControl("undo", false);
		}
		if (levelsDone[curLevel]) {
			levelsDone[curLevel] = false;
			saveDone();
		}
		if (action.a != action.b) {
			selectBox(-1);
			if (manSq == action.a) moveMan(-1); // don't trample him
			moveBox((boxCurRoute ? boxCurSq : action.b), action.a);
		}
		moveMan(action.manSq);
		manCurRoute = null;
		boxCurRoute = null;
		moves = action.moves;
		pushes = action.pushes;
		showScore();
		saveState();
	}
	return false;
}

function redo() {
	// Redo an undone box move, with animation
	//
	if (redoList.length > 0) {
		var action = redoList.pop();
		var savedSpeed = speed;
		speed = 0;
		boxCurRoute = null;
		manCurRoute = null;
		if (action.a == action.b) {
			// moving man only, not a box; destination is action.b
			if (thingState[action.b] != thingFree ||
				!(manCurRoute = findPath(manSq, action.b))) {
				alert("Incorrect redo entry moving man to " + action.b);
				redoList.push(action);
			} else {
				undoList.push(new UndoState(action.a, action.b));
				adbab.xableControl("restart", true);
				adbab.xableControl("undo", true);
				adbab.xableControl("redo", redoList.length > 0);
				routeMan();
			}
		} else if (thingState[action.a] != thingBox ||
				thingState[action.b] != thingFree ||
				action.a == action.b ||
				!(boxCurRoute = findBoxPath(action.a, action.b))) {
			alert("Incorrect redo entry " + action.a + " to " +
					action.b);
			redoList.push(action);
		} else {
			undoList.push(new UndoState(action.a, action.b));
			adbab.xableControl("restart", true);
			adbab.xableControl("undo", true);
			// adbab.xableControl("redo", redoList.length > 0);
			adbab.xableControl("redo", false); // during routeBox
			selectBox(action.a);
			boxCurSq = action.a;
			routeBox(); // also saves the state
		}
		speed = savedSpeed;
	}
	return false;
}

function wheelMove(deltaX, deltaY, deltaMode) {
	// Respond to Y-axis mouse wheel action with undo/redo
	//
	if (deltaY < 0) {
		undo();
	} else if (deltaY > 0 && !manCurRoute && !boxCurRoute) {
		redo();
	}
	return false;
}


//
// Keyboard control
//

function moveManOneSquare(delta) {
	// If man is visible, and we're not running an animation, attempt to
	// move the man by the given delta (assumed to be one square
	// in some direction).  We rely on the existence of the perimeter
	// wall, and "undefined" when out of bounds in "thingState", instead of
	// explicit bounds checking.
	//
	var dest = manSq + delta;
	if (manCurRoute || boxCurRoute || manSq < 0) {
		// animation in progress, or man is invisible: do nothing
	} else if (thingState[dest] == thingBox) {
		var boxDest = oppositeNeighbour(dest, manSq);
		if (thingState[boxDest] == thingFree) {
			boxCurSq = dest;
			boxCurRoute = [boxDest];
			record(dest, boxDest);
			routeBox();
		}
	} else if (thingState[dest] == thingFree) {
		manCurRoute = [dest];
		record(dest, dest);
		routeMan();
	}
	return false;
}

function keydown(event) {
	// Called on a keydown event in the document
	//
	var key = (event.code ? event.code : event.keyCode);
	if (document.getElementById("scene").style.display == "none") {
		return true;
	} else if (event.altKey || event.ctrlKey || event.metaKey) {
		return true;
	} else if (key === "KeyA" || key === 65 || key === 81 ||
				key === "ArrowLeft" || key === 37) {
		return moveManOneSquare(-1);
	} else if (key === "KeyW" || key === 87 || key === 90 ||
				key === "ArrowUp" || key === 38) {
		return moveManOneSquare(-width);
	} else if (key === "KeyD" || key === 68 ||
				key === "ArrowRight" || key === 39) {
		return moveManOneSquare(1);
	} else if (key === "KeyS" || key === 83 ||
				key === "ArrowDown" || key === 40) {
		return moveManOneSquare(width);
	} else if (key === "KeyX" || key === 88) {
		return restart();
	} else if (key === "Comma" || key === 188) {
		return undo();
	} else if (key === "Period" || key === 190) {
		return redo();
	}
	return true;
}


//
// Initialization
//

function getLevelRequest(collection) {
	// Read a level set via initiateXMLHttp
	//
	function gotLevel(text) {
		if (!text) {
			alert("Failed to read levels for \"" + collection + "\"");
		} else {
			adoptCollection(text);
			window.onresize = doResize;
		}
	}

	adbab.initiateXMLHttp(gotLevel, "levels/" + collection + ".txt",
		false, true);
}

function adoptCollection(s) {
	s = s.replace(/\r\n/g, "\n");
	s = s.replace(/\r/g, "\n");
	levelsTxt = s.replace(/\|/g, "\n");
	var lines = levelsTxt.split("\n");
	var i = 0;
	levels = [];
	while (i < lines.length) {
		while (i < lines.length && !lines[i].match(/^ *#/)) i++;
		if (i < lines.length) {
			var levelLines = [];
			while (i < lines.length && lines[i].match(/^ *#/)) {
				levelLines[levelLines.length] = lines[i];
				i++;
			}
			levels[levels.length] = levelLines;
		}
	}
	adbab.option.truncate("levels", 0);
	var lSelect = document.getElementById("levels");
	for (i = 0; i < levels.length; i++) {
		adbab.option.append(lSelect, "Level " + (i+1), i);
	}
	lSelect.disabled = (levels.length <= 1);
	levelsDone = new Array(levels.length);
	curLevel = -1;
	savedLevel = -1;
	if (levelsName) {
		var oldDone = adbab.getCookie("sokoDone-" + levelsName);
		if (oldDone) {
			var doneList = oldDone.split(",");
			for (var i = 0; i < doneList.length; i++) {
				var ab = doneList[i].split("-");
				if (ab.length == 1) ab[1] = ab[0];
				ab[0] = parseInt(ab[0]);
				ab[1] = parseInt(ab[1]);
				for (var j = ab[0]; j <= ab[1]; j++) levelsDone[j] = true;
			}
		}
		var oldLevel = adbab.getCookie("sokoLevel-" + levelsName);
		if (oldLevel && adbab.option.setValue("levels", oldLevel)) {
			startLevel(parseInt(oldLevel));
		} else {
			startLevel(0);
		}
	} else {
		startLevel(0);
	}
}

function selCollection() {
	// Switch to a collection based on the current value of the selector
	//
	var collectionName = adbab.option.getValue("collections");
	if (collectionName == levelsName) {
	} else if (collectionName == "design") {
		levelsName = null;
		startDesign();
	} else {
		window.onresize = null;
		levelsName = collectionName;
		getLevelRequest(collectionName);
	}
	return false;
}

function initSelCollection() {
	// Switch to a collection based on a cookie, or force 0
	//
	var oldC = adbab.getCookie("sokoCollection");
	if (oldC) {
		adbab.option.setValue("collections", oldC);
	} else {
		adbab.option.setSelection("collections", 0);
	}
	selCollection();
}

function init() {
	// "load" event handler
	//
	adbab.addMouseWheel("board", wheelMove);
	var oldS = adbab.getCookie("sokoSpeed");
	if (oldS) adbab.option.setValue("speeds", oldS);
	speed = parseInt(adbab.option.getValue("speeds"));
	initSelCollection();
	document.onkeydown = keydown;
}

