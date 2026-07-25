// Game Gold Tower Defence on Samsung TV controlled via laptop

// I access in Chrome: https://192.168.0.211:8002/api/v2/

// Ctrl+Shft+i
// Paste the code below into the console:

const TOKEN = '';
const socket = new WebSocket('wss://192.168.0.211:8002/api/v2/channels/samsung.remote.control?name=AutomacaoGamer&token=' + TOKEN);

socket.onopen = () => { console.log("Click ALLOW in the pop-up on the TV."); }

socket.onmessage = (event) => {
  const data = JSON.parse(event.data);
  console.log("Message received from TV:", data);
  
  if (data.event === "ms.channel.connect") {
    if (data.data && data.data.token) console.warn("TOKEN RECEIVED! Save this number:", data.data.token);
  }
}

socket.onerror = (error) => { console.error("Connection error:", error); }

function sendKey(key) {
  const command = {
    method: "ms.remote.control",
    params: {
      Cmd: "Click", // It can be "Press" and, after a while, "Release".
      DataOfCmd: key,
      Option: "false",
      TypeOfRemote: "SendRemoteKey"
    }
  };
  
  socket.send(JSON.stringify(command));
}

const wait = (ms) => new Promise(resolve => setTimeout(resolve, ms)); // ms is the number of milliseconds to wait

async function send(key, delay = 10) {
  sendKey(key);
  await wait(delay);
}

// send('KEY_RIGHT');

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

let sequence;
async function executeSequence() {
  for (const key of sequence) await send(key);
}
// Example: sequence = ["KEY_UP", "KEY_UP"]; executeSequence();
/*
KEY_0, KEY_1, KEY_2, KEY_3, KEY_4, KEY_5, KEY_6, KEY_7, KEY_8, KEY_9
KEY_ENTER, KEY_RETURN
KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
KEY_HOME, KEY_MENU
KEY_VOLUP, KEY_VOLDOWN, KEY_MUTE
*/

// = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = = =

const Cursor = {
  line:   4, // initial y position
  column: 5, // initial x position
  
  async setPosition(line, column) {
    this.line  = line;
    this.column = column;
  },
  
  async goToPosition(newLine, newCol) {
    const difCol  = newCol - this.column;
    const difLine = newLine - this.line;
    
    // horizontal movement 
    if (difCol > 0) {
      for (let i = 0; i < difCol; i++) await send("KEY_RIGHT");
    }
    else if (difCol < 0) {
      for (let i = 0; i < Math.abs(difCol); i++) await send("KEY_LEFT");
    }
    
    // vertical movement 
    if (difLine > 0) {
      for (let i = 0; i < difLine; i++) await send("KEY_DOWN");
    }
    else if (difLine < 0) {
      for (let i = 0; i < Math.abs(difLine); i++) await send("KEY_UP");
    }
    
    // Updates the current position
    this.column = newCol;
    this.line = newLine;
  }
};

const mapTerrainType = {
  BLOCKED: 0, // Scenery where you cannot walk or build
  PATH: 1,    // Monster route / hero movement
  TOWER: 2,   // Building slots
  SPAWN: 3,   // Where monsters spawn
  FLAG: 4     // Objective flags
};

const stage = {
  30: {
    map: [
    // 0  1  2  3  4  5  6  7  8  9 10 11 column
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], // line 0
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0], // line 1
      [1, 1, 0, 0, 0, 3, 0, 0, 0, 0, 1, 1], // line 2
      [2, 1, 2, 0, 0, 0, 0, 0, 0, 2, 1, 2], // line 3
      [0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0], // line 4
      [0, 2, 1, 2, 2, 1, 2, 2, 1, 2, 0, 0], // line 5
      [0, 0, 1, 1, 2, 1, 2, 1, 1, 0, 0, 0], // line 6
      [0, 0, 0, 1, 2, 1, 2, 1, 0, 0, 0, 0], // line 7
      [0, 0, 0, 1, 0, 4, 0, 1, 0, 0, 0, 0]  // line 8
    ],
    easy: {
      life: 10,
      wave: 7,
      mineral: 800,
      monsters: [
        {name: 'Mantis', AP: 37, HP: 480}, 
        {name: 'Mud', AP: 41, HP: 600}, 
        {name: 'Diona', AP: 25, HP: 350}, 
        {name: 'Oak', AP: 33, HP: 430}, 
        {name: 'Modified Small Bee', AP: 53, HP: 700} 
      ]
    }, 
    normal: {}, 
    hard: {
      monsters: [
        {AP: 111, HP: 1700, attribute: '', name: 'Mantis'}, 
        {AP: 123, HP: 2100, attribute: '', name: 'Mud'}, 
        {AP:  75, HP: 1200, attribute: '', name: 'Diona'}, 
        {AP:  99, HP: 1500, attribute: '', name: 'Oak'}, 
        {AP: 159, HP: 2500, attribute: '', name: 'Modified Small Bee'} 
      ]
    } 
  },
  149: {
    map: [
    // 0  1  2  3  4  5  6  7  8  9 10 11 column
      [0, 0, 0, 0, 0, 3, 3, 0, 0, 3, 0, 0], // line 0
      [0, 0, 3, 2, 0, 1, 1, 2, 0, 1, 0, 0], // line 1
      [0, 0, 1, 1, 2, 1, 1, 2, 1, 1, 2, 0], // line 2
      [2, 2, 2, 1, 1, 1, 1, 1, 1, 2, 0, 0], // line 3
      [3, 1, 1, 1, 1, 4, 4, 1, 1, 1, 1, 3], // line 4
      [0, 2, 0, 2, 1, 1, 1, 1, 2, 2, 0, 0], // line 5
      [0, 0, 3, 1, 1, 1, 1, 1, 1, 2, 0, 0], // line 6
      [0, 0, 0, 2, 2, 1, 1, 2, 1, 1, 3, 0], // line 7
      [0, 0, 0, 0, 2, 3, 3, 2, 0, 0, 0, 0]  // line 8
    ],
    easy: {
      life: 10,
      wave: 6,
      mineral: 8000,
      monsters: [
        {AP:    0, HC:      60, attribute:     'rock', name: 'Hand of the Past Hero'}, 
        {AP:    0, HC:      60, attribute: 'scissors', name: 'Hand of the Past Hero'}, 
        {AP: 5000, HP:  850000, attribute: 'scissors', name: 'Follower of Gullveig'}, 
        {AP:    0, HP: 1900000, attribute:    'paper', name: 'Freezing boar'}, 
        {AP:  650, HC:      80, attribute: 'scissors', name: 'Ice Golem'} 
      ]
    }
  },
  153: {
    map: [
    // 0  1  2  3  4  5  6  7  8  9 10 11 column
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0], // line 0
      [1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 1, 3], // line 1
      [0, 2, 1, 1, 2, 0, 0, 0, 0, 0, 1, 2], // line 2
      [0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 0], // line 3
      [0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 1, 2], // line 4
      [0, 0, 0, 0, 2, 1, 1, 2, 0, 2, 1, 0], // line 5
      [0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 1, 2], // line 6
      [0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 1, 0], // line 7
      [0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 0]  // line 8
    ],
    hard: {
      life: 1,
      wave: 5,
      mineral: 4500,
      monsters: [
        {AP:      0, HC:     210, attribute: 'paper', name: 'Hand of the Past Hero'}, 
        {AP:     30, HC:      87, attribute: 'paper', name: 'E. Blaze'}, 
        {AP:      0, HP: 6500000, attribute: 'paper', name: 'Freezing boar'}, 
        {AP: 300000, HP: 3500000, attribute: 'paper', name: 'Jack-o-hunter'}, 
        {AP: 300000, HC:     350, attribute: 'paper', name: 'Ice Giant'} 
      ]
    }
  } 
};

const towerType = ['Only ground', 'Ground + Airborne', 'Only airborne'];
const attribute = ['scissors', 'rock', 'paper'];
let autoATK = true;
/*
Scissors vs. Rock = -40% attack damage
Rock vs. Rock = unchanged attack damage
Paper vs. Rock = +40% attack damage
*/

const myTowers = [
  {
    name: 'Bat', attribute: 'rock', type: 'Ground + Airborne', level: 1, card: 1, 
    attack: 'wide', AP: 2900, range: 700, mineral: 440, HP: '-', period: 1
  },
  {
    name: 'Bat', attribute: 'scissors', type: 'Ground + Airborne', level: 1, card: 1, 
    attack: 'wide', AP: 2900, range: 700, mineral: 440, HP: '-', period: 1
  },
  {
    name: 'Wolf', attribute: 'rock', type: 'Only ground', level: 1, card: 1, 
    attack: 'wide', AP: 10120, range: 250, mineral: 2920, HP: '-', period: 1
  },
  {
    name: 'Nun', attribute: 'rock', type: '', level: 2, card: 0, 
    attack: 'none', heal: '31%', range: 190, mineral: 3360, HP: '-', cicle: 3
  },
  {
    name: 'Cannon', attribute: 'paper', type: 'Ground + Airborne', level: 1, card: 1, 
    attack: 'wide', AP: 165000, range: 1300, mineral: 0, HP: '-', period: 1.5
  },
  {
    name: 'Cannon', attribute: 'rock', type: 'Ground + Airborne', level: 2, card: 0, 
    attack: 'wide', AP: 265000, range: 1300, mineral: 0, HP: '-', period: 1.5
  },
  {
    name: 'Thorns', attribute: 'paper', type: 'Only ground', level: 2, card: 0, 
    attack: 'wide', AP: 20350, range: 180, mineral: 4000, HP: '-', period: 1.5
  },
  {
    name: 'Thorns', attribute: 'rock', type: 'Only ground', level: 1, card: 1, 
    attack: 'wide', AP: 7150, range: 180, mineral: 2000, HP: '-', period: 1.5
  },
  {
    name: 'Thorns', attribute: 'scissors', type: 'Only ground', level: 1, card: 1, 
    attack: 'wide', AP: 7150, range: 180, mineral: 2000, HP: '-', period: 1.5
  },
  {
    name: 'Lightning', attribute: 'scissors', type: 'Only airborn', level: 1, card: 1, 
    attack: 'wide', AP: 27500, range: 200, mineral: 12000, HP: '-', period: 1
  },
  {
    name: 'Barrack', attribute: 'rock', type: 'Only ground', level: 1, card: 1, 
    attack: 'single', AP: 33000, range: 150, mineral: 1600, HC: 24, period: 0.7
  },
  {
    name: 'Assassin', attribute: 'rock', type: 'Only ground', level: 1, card: 1, 
    attack: 'single', AP: 18000, range: 150, mineral: 1600, HC: 3, period: 0.7
  },
  {
    name: 'Magic', attribute: 'paper', type: 'Ground + Airborne', level: 2, card: 0, 
    attack: 'wide', AP: 48050, range: 1300, mineral: 0, HP: '-', period: 1.3
  },
  {
    name: 'Ice Arrow', attribute: 'paper', type: 'Ground + Airborne', level: 1, card: 1, 
    attack: 'single', AP: 650, range: 900, mineral: 1600, HP: '-', period: 0.5
  },
  {
    name: 'Ice Arrow', attribute: 'rock', type: 'Ground + Airborne', level: 1, card: 1, 
    attack: 'single', AP: 650, range: 900, mineral: 1600, HP: '-', period: 0.5
  },
  {
    name: 'Ice Arrow', attribute: 'scissors', type: 'Ground + Airborne', level: 2, card: 0, 
    attack: 'single', AP: 1850, range: 900, mineral: 1600, HP: '-', period: 0.5
  },
  {
    name: 'Shuriken', attribute: 'scissors', type: 'Ground + Airborne', level: 3, card: 0, 
    attack: 'wide', AP: 122000, range: 800, mineral: 6240, HP: '-', period: 0.6
  }
];

async function buildTower(tower, position) {
  await Cursor.goToPosition(position.line, position.column);
  
  await send('KEY_ENTER'); // open menu of towers
  
  let selectedTowerIndex;
  for (let [index, selectedTower] of selectedTowers.entries()) {
    if (selectedTower.name !== tower.name || selectedTower.attribute !== tower.attribute) continue;
    selectedTowerIndex = index;
  }
  
  if (selectedTowerIndex === undefined) {
    console.log(`NOT FOUND tower "${tower.name}" "${tower.attribute}"`);
    return;
  }
  
  // change to menu 2
  if (selectedTowerIndex > 4) {
    await send('KEY_LEFT');
    await send('KEY_ENTER');
    await send('KEY_RIGHT'); 
    selectedTowerIndex -= 5;
  }
  
  for (let i=0; i < selectedTowerIndex; i++) send('KEY_RIGHT'); // move cursor to tower
  
  await send('KEY_ENTER'); // build tower
}

// buildTower({name: 'Thorns', attribute: 'paper'}, {line: 3, column: 0});

async function upgradeTower(position) {
  await Cursor.goToPosition(position.line, position.column);
  
  await send('KEY_ENTER'); // open menu of towers
  await send('KEY_ENTER'); // upgrade of tower
} 

const selectedTowers = [
  {name: 'Thorns', attribute: 'paper'},
  {name: 'Thorns', attribute: 'rock'}, 
  {name: 'Thorns', attribute: 'scissors'},
  {name: 'Bat', attribute: 'scissors'},
  {name: 'Bat', attribute: 'rock'},
  {name: 'Cannon', attribute: 'rock'}, 
  {name: 'Magic', attribute: 'paper'},
  {name: 'Ice Arrow', attribute: 'rock'}, 
  {name: 'Ice Arrow', attribute: 'scissors'}, 
  {name: 'Shuriken', attribute: 'scissors'}
];

const selectedHeros = [
  {name: 'Loki', attribute: 'paper'},
  {name: 'Hell Knight', attribute: 'paper'},
  {name: 'Robin', attribute: 'scissors'},
  {name: 'Robin', attribute: 'rock'},
  {name: 'Robin', attribute: 'paper'}
];

let heroPosition = 0;

async function moveHero(hero, position) {
  await Cursor.goToPosition(position.line, position.column);
  
  let selectedHeroIndex;
  for (let [index, selectedHero] of selectedHeros.entries()) {
    if (selectedHero.name !== hero.name || selectedHero.attribute !== hero.attribute) continue;
    selectedHeroIndex = index;
  }
  
  if (selectedHeroIndex === undefined) {
    console.log(`NOT FOUND hero "${hero.name}" "${hero.attribute}"`);
    return;
  }
  
  await send('KEY_3');
  if (selectedHeroIndex < heroPosition) heroPosition = 5 - heroPosition + selectedHeroIndex;
  else heroPosition = 5 - heroPosition + selectedHeroIndex;
  
  for (let i = 0; i < heroPosition; i++) await send('KEY_3');
  
  await send('KEY_ENTER');
  heroPosition = selectedHeroIndex;
}

/*
    // 0  1  2  3  4  5  6  7  8  9 10 11 column
      [0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 4, 0], // line 0
      [1, 1, 1, 2, 0, 0, 0, 0, 0, 0, 1, 3], // line 1
      [0, 2, 1, 1, 2, 0, 0, 0, 0, 0, 1, 2], // line 2
      [0, 0, 2, 1, 1, 2, 0, 0, 0, 2, 1, 0], // line 3
      [0, 0, 0, 2, 1, 1, 2, 0, 0, 0, 1, 2], // line 4
      [0, 0, 0, 0, 2, 1, 1, 2, 0, 2, 1, 0], // line 5
      [0, 0, 0, 0, 0, 2, 1, 1, 2, 0, 1, 2], // line 6
      [0, 0, 0, 0, 0, 0, 2, 1, 1, 2, 1, 0], // line 7
      [0, 0, 0, 0, 0, 0, 0, 2, 1, 1, 1, 0]  // line 8
*/

// fase 153 hard
async function stage153hard() {
  await Cursor.setPosition(4, 5);
  heroPosition = 0;
  await send('KEY_OK');
  await wait(3500);
  
  await buildTower({name: 'Thorns', attribute: 'scissors'}, {line: 2, column: 4});
  
  await buildTower({name: 'Bat', attribute: 'scissors'}, {line: 4, column: 6});
  await upgradeTower({line: 4, column: 6});
  
  await buildTower({name: 'Bat', attribute: 'rock'}, {line: 5, column: 7});
  await upgradeTower({line: 5, column: 7});

  await wait(500);
  moveHero({name: 'Robin', attribute: 'scissors'}, {line: 3, column: 4})
  await wait(500);
  moveHero({name: 'Loki', attribute: 'paper'}, {line: 5, column: 5})
  await wait(500);
  moveHero({name: 'Robin', attribute: 'rock'}, {line: 8, column: 9})
  await wait(500);
  moveHero({name: 'Hell Knight', attribute: 'paper'}, {line: 5, column: 6})
  
  await wait(500);
  await upgradeTower({line: 4, column: 6});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 6, column: 11});
  await upgradeTower({line: 6, column: 11});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 4, column: 11});
  await upgradeTower({line: 4, column: 11});
  
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 1, column: 3});
  await upgradeTower({line: 1, column: 3});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 2, column: 1});
  await upgradeTower({line: 2, column: 1});
}
stage153hard();
  
/*
  await buildTower({name: 'Cannon', attribute: 'rock'}, {line: 7, column: 9});
  await upgradeTower({line: 7, column: 9});
  
  await buildTower({name: 'Cannon', attribute: 'rock'}, {line: 5, column: 9});
  await upgradeTower({line: 5, column: 9});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 6, column: 11});
  await upgradeTower({line: 6, column: 11});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 4, column: 11});
  await upgradeTower({line: 4, column: 11});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 6, column: 8});
  await upgradeTower({line: 6, column: 8});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 7, column: 6});
  await upgradeTower({line: 7, column: 6});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 6, column: 5});
  await upgradeTower({line: 6, column: 5});
  
  await buildTower({name: 'Cannon', attribute: 'rock'}, {line: 8, column: 7});
  await upgradeTower({line: 8, column: 7});
  
  await wait(500);
  await upgradeTower({line: 7, column: 9});
  await upgradeTower({line: 5, column: 9});
  await upgradeTower({line: 6, column: 11});
  await upgradeTower({line: 4, column: 11});
  await upgradeTower({line: 6, column: 8});
  await upgradeTower({line: 7, column: 6});
  await upgradeTower({line: 6, column: 5});
  await upgradeTower({line: 8, column: 7});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 1, column: 3});
  await upgradeTower({line: 1, column: 3});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 2, column: 1});
  await upgradeTower({line: 2, column: 1});
  
  await buildTower({name: 'Magic', attribute: 'paper'}, {line: 3, column: 2});
  await upgradeTower({line: 3, column: 2});
  
  await upgradeTower({line: 4, column: 6});
  
  await wait(500);
  await upgradeTower({line: 1, column: 3});
  await upgradeTower({line: 2, column: 1});
  await upgradeTower({line: 3, column: 2});
*/

/*
ffmpeg -y -i video_input.mp4 -vf \
"drawtext=fontfile=/usr/share/fonts/truetype/dejavu/DejaVuSans.ttf:text='%{eif\:trunc(t/60)\:d\:2}\:%{eif\:mod(t\,60)\:d\:2}.%{eif\:mod(t*1000\,1000)\:d\:3}':x=10:y=10:fontsize=24:fontcolor=white:box=1:boxcolor=black@0.5" \
-c:a copy video_output.mp4
*/
