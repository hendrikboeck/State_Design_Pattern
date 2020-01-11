var m = new XRayMachine();

/**
 * define IO-Buttons for changing states
 */
var turnOn_btn;
var turnOff_btn;
var coverTube_btn;
var uncoverTube_btn;
var takePicture_btn;

/**
 * define IO-States
 */
var state_ui_elem = [];
// var connections = [];

function setup() {
    createCanvas(800, 400);

    // Initialize buttons
    turnOn_btn = createButton('Turn on');
    turnOff_btn = createButton('Turn off');
    coverTube_btn = createButton('Cover X-raytube');
    uncoverTube_btn = createButton('Uncover X-raytube');
    takePicture_btn = createButton('Take picture');

    // Events for Buttons
    turnOn_btn.mousePressed(turn_on);
    turnOff_btn.mousePressed(turn_off);
    coverTube_btn.mousePressed(cover_tube);
    uncoverTube_btn.mousePressed(uncover_tube);
    takePicture_btn.mousePressed(take_picture);

    // Position of Buttons
    turnOn_btn.position(20, 150);
    turnOff_btn.position(100, 150);
    coverTube_btn.position(185, 150);
    uncoverTube_btn.position(315, 150);
    takePicture_btn.position(450, 150);

    state_ui_elem = [
        new StateUI("XRayOff", 20, 70),
        new StateUI("XRayIdle", 325, 70),
        new StateUI("XRayPictureMode", 630, 70)
    ];

    textSize(32);
    textAlign(LEFT, TOP)
    text('States:', 20, 20)

    // connections = [
    //     new StateUIConnection(state_ui_elem[0], state_ui_elem[1], "right", "left"),
    //     new StateUIConnection(state_ui_elem[1], state_ui_elem[2], "right", "left"),
    //     new StateUIConnection(state_ui_elem[1], state_ui_elem[0], "top", "top", 20, -10, 0, 10, 0),
    //     new StateUIConnection(state_ui_elem[2], state_ui_elem[0], "top", "top", 60, 10, 0, -10, 0),
    //     new StateUIConnection(state_ui_elem[2], state_ui_elem[1], "top", "top", 20, -10, 0, 10, 0),
    //     new StateUIConnection(state_ui_elem[2], state_ui_elem[2], "bottom", "bottom")
    // ];
}

function draw() {
    for (let i = 0; i < state_ui_elem.length; i++) {
        if (state_ui_elem[i].state_class == m.cur_state.constructor.name)
            state_ui_elem[i].set_color(color(255, 204, 0));
        else
            state_ui_elem[i].set_color(color(150));
        state_ui_elem[i].paint();
    }

    // for (let i = 0; i < connections.length; i++) {
    //     connections[i].paint();
    // }

}

// Declare Functions for buttons

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