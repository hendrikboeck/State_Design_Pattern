var m = new XRayMachine();

/*
 * define IO-Buttons for changing states
 */
var turnOn_btn;
var turnOff_btn;
var coverTube_btn;
var uncoverTube_btn;
var takePicture_btn;

/*
 * define IO-States
 */
var state_ui_elem = [];
var connections = []
var buttons;
var possibleConnections = {
  "XRayOff": ["off-idle"],
  "XRayIdle": ["off-idle", "idle-pic"],
  "XRayPictureMode": ["pic-pic", "pic-off", "idle-pic"]
}

function setup() {
  createCanvas(800, 400);
  frameRate(24);

  buttons = new ButtonBar(20, 250, 10);
  buttons.add("turn_on", "Turn on", turn_on);
  buttons.add("turn_off", "Turn off", turn_off);
  buttons.add("cover_tube", "Cover X-raytube", cover_tube);
  buttons.add("uncover_tube", "Uncover X-raytube", uncover_tube);
  buttons.add("take_picture", "Take picture", take_picture);
  buttons.render()

  state_ui_elem = [
    new StateUI("XRayOff", 20, 120),
    new StateUI("XRayIdle", 325, 120),
    new StateUI("XRayPictureMode", 630, 120)
  ];

  connections = new Map();
  connections.set("off-idle", new Connection([[95, 120], [95, 120], [185, 100], [300, 100], [390, 120], [390, 120]]));
  connections.set("idle-pic", new Connection([[390, 120], [390, 120], [480, 100], [615, 100], [705, 120], [705, 120]]));
  connections.set("pic-off", new Connection([[95, 170], [95, 170], [255, 200], [545, 200], [705, 170], [705, 170]]));
  connections.set("pic-pic", new Connection([[745, 120], [745, 120], [760, 100], [788, 100], [795, 125], [780, 145], [780, 145]]));
}

function draw() {
  clear();

  fill(0);
  textSize(32);
  textAlign(LEFT, TOP)
  text('States:', 20, 20)

  for (ui_elem of state_ui_elem) {
    if (ui_elem.state_class == m.cur_state.constructor.name) {
      ui_elem.set_color(color(255, 204, 0));
    }
    else {
      ui_elem.set_color(color(150));
    }
    ui_elem.paint();
  }

  for (const [key, con] of connections) {
    if (possibleConnections[m.cur_state.constructor.name].includes(key))
      con.render("#ffcc00");
    else
      con.render();
  }
}

/*
 * Making Functions public for buttons to use them
 */
function turn_on() {
  m.turn_on();
}

function turn_off() {
  m.turn_off();
}

function cover_tube() {
  m.cover_tube();
}

function uncover_tube() {
  m.uncover_tube();
}

function take_picture() {
  m.take_picture();
}