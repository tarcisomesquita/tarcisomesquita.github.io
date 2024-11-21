// Emacs settings: -*- mode: Fundamental; tab-width: 4; -*-

////////////////////////////////////////////////////////////////////////////
//                                                                        //
// Miscellaneous support functions: adbabMisc.js                          //
//                                                                        //
// Copyright (c) 2004-2016, Andrew Birrell                                //
//                                                                        //
////////////////////////////////////////////////////////////////////////////

// This library implements some miscellaneous Javascript operations.
// 
// This library updates the global "adbab" object (creating it if necessary)
// to add the following functions:
//
//   utf8               ... convert a Unicode string into UTF-8
//   caseSort           ... callback for case-insensitive sorting
//
//   Cache              ... constructor for a simple LRU cache
//
//   htmlspecials       ... add escapes to a string to live in HTML source
//   getCookie          ... extract a cookie by key name
//   setCookie          ... set a cookie
//   deleteCookie       ... delete a cookie
//   getQueryArg        ... extract a query argument from our URL
//
//   initiateXMLHttp    ... execute an AJAX-style asynchronous server call
//
//   showHide           ... show or hide an element with "display: block"
//   showHideInline     ... show or hide an element with "display: inline"
//   xableControl       ... enable or disable a form control element
//   option             ... operations on options of a "SELECT" element
//
//   windowSize         ... return the dimensions of the document's window
//   getElementPos      ... return element's position relative to document
//   getMousePos        ... return mouse position relative to the document
//   getActualStyle     ... return the CSS style in use for the element
//
//   addMouseWheel      ... cross-browser mouse wheel support
//   clickStart         ... implements clickable button-like elements
//
//   Slider             ... constructor for a sliding-screen transition
//
// See the source below for the detailed semantics of the functions.

"use strict";

var adbab; if (typeof adbab == "undefined") adbab = {};


//
// String manipulation
//

adbab.utf8 = function utf8(str) {
	// Return a string whose charCodes are the UTF-8 bytes for the given
	// Unicode string "str".
	//
	return unescape(encodeURIComponent(str));
}

adbab.caseSort = function caseSort(a, b) {
	// case-insensitive sort-order function
	//
	var la = a.toLowerCase();
	var lb = b.toLowerCase();
	return (la < lb ? -1 : (la > lb ? 1 : 0));
}


//
// Key-value cache with LRU replacement
//

adbab.Cache = function Cache(lruSize) {
	// Creates and returns an object with methods for running an LRU cache.
	// The cache retains at least lruSize entries, and at most lruSize * 2.
	//
	// This can be called as "new adbab.Cache(50)" or just "adbab.Cache(50)"
	// with the same effect.
	//
	var recent = {};
	var old = {};
	var count = 0;
	var reads = 0;
	var misses = 0;
	
	function cacheWrite(key, value) {
		// Include given (key,value) in the cache
		//
		if (!recent[key]) count++;
		recent[key] = value;
		if (count >=lruSize) {
			old = recent;
			recent = {};
			count = 0;
		}
	}

	function cacheRead(key) {
		// If key is in the cache, return value, else null
		//
		var value;
		reads++;
		if (value = recent[key]) return value;
		if (value = old[key]) {
			cacheWrite(key, value);
			return value;
		}
		misses++;
		return null;
	}

	function cacheFlush(key) {
		// ensure key is no longer in the cache
		//
		if (recent[key]) {
			recent[key] = null;
			count--;
		}
		if (old[key]) old[key] = null;
	}

	function cacheRate() {
		// Return the cache hit rate, 0 <= rate <= 1 (possibly NaN)
		//
		return 1 - (misses / reads);
	}

	return {
		write: cacheWrite,
		read: cacheRead,
		flush: cacheFlush,
		rate: cacheRate
	}
}


//
// HTTP support: encoding, cookies, query string
//

adbab.htmlspecials = function htmlspecials(str) {
	// Return a string with critical HTML characters escaped
	//
	var res = str.replace(/&/g, '&amp;');
	res = res.replace(/[<]/g, '&lt;');
	res = res.replace(/>/g, '&gt;');
	res = res.replace(/"/g, '&quot;');
	return res;
}

adbab.getCookie = function getCookie(key) {
	// If there's a cookie named "key" return its value, else false
	//
	var regExp = new RegExp("(^|.*; )" + key + "=");
	var value = document.cookie.replace(regExp, "");
	if (value == document.cookie) return null;
	return decodeURIComponent(value.replace(/;.*$/, ""));
}

adbab.setCookie = function setCookie(key, value, expires, path, domain,
			secure) {
	// Set the cookie named "key" to "value"
	//
	document.cookie = key + "=" + encodeURIComponent(value) +
		(expires ? "; expires=" + expires.toGMTString() : "") +
		(path ? "; path=" + path : "") +
		(domain ? "; domain=" + domain : "") +
		(secure ? "; secure" : "");
}

adbab.deleteCookie = function deleteCookie(key, path, domain, secure) {
	// Delete the cookie, by setting an obsolete expiry date
	//
	document.cookie = key + "=xxx" +
		"; expires=Fri, 31 Dec 1999 23:59:59 GMT" +
		(path ? "; path=" + path : "") +
		(domain ? "; domain=" + domain : "") +
		(secure ? "; secure" : "");
}

adbab.getQueryArg = function getQueryArg(key) {
	// If our URL had a search string, and there's a key=value for given
	// key, return unescaped value; else return null
	//
	if (!location.search) return null;
	var regExp = new RegExp("^(\\?|.*&)" + key + "=");
	var value = location.search.replace(regExp, "");
	if (value == location.search) return null;
	return decodeURIComponent(value.replace(/&.*$/, ""));
}


//
// Making xmlhttp requests, asynchronously
//

adbab.initiateXMLHttp = function initiateXMLHttp(callback, url, postData,
										useText) {
	// Initiate an asynchronous request to the given URL, and deal with
	// the response (which is expected to be XML).  The request method is
	// POST if "postdata" is provided, and otherwise is "GET".
	//
	// Calls "callback" eventually, in all cases.  The argument of
	// "callback" is false for failures, and otherwise is the root of the
	// parsed XML DOM tree or the response text (depending on "useText").
	//
	// If you want state passed to the callback, use a function closure.
	//
	var xmlhttp;
	function xmlhttpStateChange() {
		if (xmlhttp.readyState == 4) {
			if (xmlhttp.status === 200 || xmlhttp.status === 1) {
				var responseXML = xmlhttp.responseXML;
				if (!useText && !responseXML) {
					alert("Response is not XML:" + xmlhttp.responseText);
					callback(false);
				} else {
					callback((useText ? xmlhttp.responseText:
											responseXML.documentElement));
				}
			} else {
				alert("HTTP request failed. " + (xmlhttp.status ?
							"Status " + xmlhttp.status : "No status"));
				callback(false);
			}
		}
	};
    if (!window.XMLHttpRequest) {
        if (!initiateXMLHttp.notifiedMissing) {
        	alert("This browser doesn't support \"XMLHttpRequest\"");
        	initiateXMLHttp.notifiedMissing = true;
        }
        callback(false);
    } else {
		xmlhttp = new XMLHttpRequest();
		xmlhttp.onreadystatechange = xmlhttpStateChange;
		xmlhttp.open((postData ? "POST" : "GET"), url, true);
		xmlhttp.setRequestHeader("Cache-control", "no-cache, max-age=0");
		if (postData) xmlhttp.setRequestHeader("Content-type",
							"application/x-www-form-urlencoded");
		xmlhttp.send((postData ? postData : null));
	}
}


//
// Minor DOM manipulations
//

adbab.showHide = function showHide(id, show) {
	// Show or hide the DOM element with given ID (assumed to be a block)
	//
	var elt = document.getElementById(id);
	if (elt) elt.style.display = (show ? "block" : "none");
}

adbab.showHideInline = function showHideInline(id, show) {
	// Show or hide the DOM element with given ID (assumed to be inline)
	//
	var elt = document.getElementById(id);
	if (elt) elt.style.display = (show ? "inline" : "none");
}

adbab.xableControl = function xableControl(id, yes) {
	// Enable or disable a form control element
	//
	var elt = document.getElementById(id);
	elt.disabled = !yes;
}

adbab.option = (function (){

	function getSelection(id) {
		// Return the current selection in a SELECT, or < 0 if none
		//
		var selector = document.getElementById(id);
		return selector.selectedIndex;
	}

	function setSelection(id, n) {
		// Set the current selection of a SELECT, or deselect if < 0
		//
		var selector = document.getElementById(id);
		selector.selectedIndex = n;
	}

	function getPrompt(id) {
		// Return the text of the selected option in given selector
		//
		var selector = document.getElementById(id);
		var selected = selector.selectedIndex;
		if (selected < 0) return null;
		return selector.options[selected].text;
	}

	function getValue(id, andDelete) {
		// Return the value of the selected option in given selector, or
		// null if there's no selection.  Optionally, also delete the
		// selected item.
		//
		var selector = document.getElementById(id);
		var selected = selector.selectedIndex;
		if (selected < 0) return null;
		var value = selector.options[selected].value;
		if (andDelete) selector.options[selected] = null;
		return value;
	}

	function setValue(id, value) {
		// Find the element of given SELECT object with given value,
		// make it the selected index, and return true.  If no such value
		// (including all cases where the argument is null), return false.
		//
		if (value === null) return false;
		var selector = document.getElementById(id);
		var options = selector.options;
		for (var i = 0; i < options.length; i++) {
			if (options[i].value == value) {
				selector.selectedIndex = i;
				return true;
			}
		}
		return false;
	}

	function append(selector, prompt, value) {
		selector.options[selector.options.length] =
			new Option(prompt, value);
	}

	function insert(id, fixed, prompt, value, select) {
		// Insert option in sorted position, ignoring initial fixed area
		//
		var selector = document.getElementById(id);
		var options = selector.options;
		var pos = fixed;
		while (pos < options.length) {
			var old = options[pos].text;
			if (caseSort(old, prompt) > 0) break;
			pos++;
		}
		for (var i = options.length; i > pos; i--) {
			var old = options[i-1];
			options[i] = new Option(old.text, old.value);
		}
		options[pos] = new Option(prompt, value);
		if (select) selector.selectedIndex = pos;
	}

	function remove(id, value) {
		// Remove option with given value from given selector
		//
		var selector = document.getElementById(id);
		var options = selector.options;
		for (var i = 0; i < options.length; i++) {
			if (options[i].value == value) {
				options[i] = null;
				break;
			}
		}
	}

	function truncate(id, count) {
		// Truncate a selector to have this many options
		//
		var selector = document.getElementById(id);
		var options = selector.options;
		while (options.length > count) options[options.length-1] = null;
	}

	return {
		getSelection: getSelection,
		setSelection: setSelection,
		getPrompt: getPrompt,
		getValue: getValue,
		setValue: setValue,
		append: append,
		insert: insert,
		remove: remove,
		truncate: truncate
	};

})();


//
// Size, position, and style calculations
//

adbab.windowSize = function windowSize() {
	// Return {x,y} for the window's width and height.
	//
	var x, y;
	if (self.innerWidth !== undefined) {
		x = self.innerWidth;
		y = self.innerHeight;
	} else if (document.documentElement &&
				document.documentElement.clientWidth !== undefined) {
		x = document.documentElement.clientWidth;
		y = document.documentElement.clientHeight;
	} else if (document.body && document.body.clientWidth !== undefined) {
		x = document.body.clientWidth;
		y = document.body.clientHeight;
	}
	return {x: x, y: y};
}

adbab.getElementPos = function getElementPos(elt) {
	// Return {x,y} for top-left of the element, relative to the document
	//
	var x = 0, y = 0;
	for (var obj = elt; obj.offsetParent; obj = obj.offsetParent) {
		x += obj.offsetLeft;
		y += obj.offsetTop;
	}
	return {x: x, y: y};
}

adbab.getMousePos = function getMousePos(event) {
	// Return (x,y) for mouse coordinates, relative to the document
	//
	var x, y;
	if (event.pageX !== undefined) {
		x = event.pageX;
		y = event.pageY;
	} else if (document.body && document.documentElement) {
		x = event.clientX + document.body.scrollLeft +
			document.documentElement.scrollLeft;
		y = event.clientY + document.body.scrollTop +
			document.documentElement.scrollTop;
	}
	return {x: x, y: y};
}

adbab.getActualStyle = function getActualStyle(elt) {
	// Get the actual style data in use for the element.
	//
	if (window.getComputedStyle) {
		return window.getComputedStyle(elt);
	} else {
		return elt.currentStyle;
	}
}


//
// Event handling
//

adbab.addMouseWheel = function addMouseWheel(id, handler) {
	// Add a mouse wheel event handler to the named element, with backward
	// compatibility for older browsers.  The event also triggers when
	// scrolling on a touchpad.
	//
	// The handler's first two arguments are the wheel movement in the X and
	// Y axes.  In the X axis, "scroll to expose the right side of the
	// document" is positive.  In the Y axis, "scroll to later in the
	// document" is positive.  On older browsers the X axis movement is 0.
	//
	// On modern browsers (using the standards-track "wheel" event), the
	// handler gets a third argument, the delta mode: 0 for pixels, 1 for
	// lines, and 2 for pages.  The third argument is "undefined" on older
	// browsers, but on those we attempt to normalize the delta to pixels.
	//
	// The direction is wrong in Opera 9, because of a bug there.
	//
	var elt = document.getElementById(id);
	var usingWheelEvent = false;
	var myHandler = function(event) {
			if (!event) event = window.event; // IE versus the rest
			var deltaX = (usingWheelEvent ? event.deltaX : 0);
			var deltaY = (usingWheelEvent ? event.deltaY :
				event.wheelDelta !== undefined ? -event.wheelDelta / 40 :
				event.detail);
			if (!handler(deltaX, deltaY, event.deltaMode)) {
				if (event.preventDefault) event.preventDefault();
				return false;
			} else {
				return true;
			}
		};
	if ("onwheel" in document.documentElement) {
		usingWheelEvent = true;
		elt.addEventListener("wheel", myHandler, false);
	} else if (elt.addEventListener) {
		elt.addEventListener("DOMMouseScroll", myHandler, false);
		elt.addEventListener("mousewheel", myHandler, false);
	} else if (elt.attachEvent) {
		elt.attachEvent("onmousewheel", myHandler);
	}
}

adbab.clickStart = function clickStart(elt, action, terminate, held) {
	// To be called in response to a mousedown or touchstart event in a
	// clickable button.  Sets up event handlers such that "action" is
	// called on a completed click, and "terminate" is called on a click
	// that's abandoned (because the mouse or touch moved outside of the
	// original element).  The caller is responsible for UI adjustments,
	// like making the button look "down" or "up".
	//
	// If "held" is provided, and if the button is held down, then the
	// click action is terminated and "held" is called instead.  Exactly
	// one of "action", "terminate", and "held" will be called.
	//
	function clickTerminate(elt) {
		clearTimeout(timer);
		elt.onmouseup = null;
		elt.onmouseleave = null;
		elt.ontouchend = null;
		elt.ontouchmove = null;
	}
	function fa() { clickTerminate(elt); action(); return false; };
	function ft() { clickTerminate(elt); terminate(); return false; };
	function fh() { if (held) {clickTerminate(elt); held(); }; };
	function fm(event) {
		// If touch has moved outside of "elt", terminate the click.
		//
		var touch = event.touches[0];
		var touchElt = document.elementFromPoint(touch.pageX, touch.pageY);
		// That might have delivered a descendant of "elt"
		while (touchElt && touchElt != elt) touchElt = touchElt.parentNode;
		if (!touchElt) ft();
		return false;
	};
	var timer = setTimeout(fh, 300);
	elt.onmouseup = fa;
	elt.onmouseleave = ft;
	elt.ontouchend = fa;
	elt.ontouchmove = fm;
	return false;
	// Prevent bubbling, and prevent default behavior (e.g. conversion
	// of touch events into mousedown, click, etc.)
}


//
// Sliding screen transition
//

adbab.Slider = (function () {
	//
	// This anonymous function creates and returns the "Slider" constructor. 
	// The declarations here are local: the global namespace is not altered.
	//
	// This abstraction implements a sliding screen effect when its "show"
	// method is called.  On browsers that don't support the HTML 5
	// transition and transform machinery, it does a jump-cut instead.
	//
	// The exact nature of the effect differs depending on whether screens
	// have identical or differing z-index values.
	//
	// We don't support the "webkit", "moz", and "o" variants of transform
	// and transition, only the standards-track version.  Older browsers
	// get a jump transition between screens.

	var enabled = null;   // whether the animation is enabled
	var curScreen = null; // the currently displayed screen

	function Slider(id, seq) {
		// Constructor for the "Slider" object, to be called via "new". Each
		// created "Slider" object represents one screen, which is assumed
		// to be implemented by the DOM element id+"Screen".
		//
		// The constructed object has one method "show".  "Slider" itself
		// has a static method "goBack" and a static property "screens". 
		// Each constructed object is assigned as a property named "id" in
		// the "Slider.screens" object.
		//
		// "seq" controls the left-right behavior for the sliding screen
		// animations, and the target for "goBack".  The animations use
		// the full value, and "goBack" uses floor(seq).
		//
		// Assumes that the first created instance is in the "show" state.
		//
		if (enabled === null) {
			enabled = ("ontransitionend" in document.documentElement);
		}
		this.id = id;
		this.elt = document.getElementById(id + "Screen");
		this.seq = seq;
		this.floorSeq = Math.floor(seq);
		if (curScreen === null) curScreen = this;
		var myself = this;
		var thisStyle = this.elt.style;
		function transitionEnd(event) {
			if (myself != curScreen) thisStyle.display = "none";
		};
		if (enabled) {
			thisStyle.transitionProperty = "transform";
			this.elt.addEventListener("transitionend", transitionEnd);
		}
		Slider.screens[id] = this;
	}

	Slider.prototype.show = function ssShow() {
		// Replace current screen with this screen
		//
		var cur = curScreen;
		var thisStyle = this.elt.style;
		var curStyle = cur.elt.style;
		var thisZ = 0;
		var curZ = 0;
		var windowWidth = document.documentElement.clientWidth;
		var delta = (this.seq < cur.seq ? 1 : -1) * windowWidth;
		function doTransition() {
			var duration = "500ms";
			curStyle.transitionDuration = duration;
			if (thisZ <= curZ) {
				curStyle.transform = "translateX(" + delta + "px)";
			} else {
				curStyle.transform = "translateX(0px)";
			}
			thisStyle.transitionDuration = duration;
			thisStyle.transform = "";
		};
		if (window.getComputedStyle) {
			thisZ = window.getComputedStyle(this.elt).zIndex;
			curZ = window.getComputedStyle(cur.elt).zIndex;
			if (thisZ == "auto") thisZ = 0;
			if (curZ == "auto") curZ = 0;
		}
		if (cur != this) {
			if (enabled && this.seq != cur.seq) {
				thisStyle.display = "block";
				thisStyle.transitionDuration = "0";
				if (thisZ >= curZ) {
					thisStyle.transform = "translateX(" + (-delta)+"px)";
				} else {
					thisStyle.transform = "translateX(0px)";
				}
				setTimeout(doTransition, 20);
			} else {
				thisStyle.display = "block";
				if (enabled) {
					thisStyle.transitionDuration = "0";
					thisStyle.transform = "";
				}
				curStyle.display = "none";
			}
			if (cur.floorSeq < this.floorSeq) {
				this.prev = cur;
			} else if (cur.floorSeq == this.floorSeq) {
				this.prev = cur.prev;
			} 
			curScreen = this;
		}
	}

	Slider.goBack = function ssBack() {
		// Go to previous lower-sequenced screen
		//
		if (curScreen.prev) curScreen.prev.show();
		return false;
	}

	Slider.screens = {};

	return Slider;

})(); // End of the anonymous function call
