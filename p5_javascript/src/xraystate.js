class XRayState {

    constructor() {}

    turn_on(_m) {
        console.error("Can not turn on X-raymachine. X-raymachine is already turned on.");
    }

    turn_off(_m) {
        console.error("Can not turn off X-raymachine. X-raymachine is already turned off.");
    }

    cover_tube(_m) {
        console.error("Can not cover X-raytube. X-raymachine is currently in wrong state.");
    }

    uncover_tube(_m) {
        console.error("Can not uncover X-raxtube. X-raymachine is currently in wrong state.");
    }

    take_picture(_m) {
        console.error("Can not take X-raypicture. X-raymachine is currently in wrong state.");
    }

}

class XRayOff extends XRayState {

    constructor() {
        super();
    }

    turn_on(_m) {
        console.log("Turned on X-raymachine.");
        _m.cur_state = new XRayIdle();
    }

}

class XRayIdle extends XRayState {

    constructor() {
        super();
    }

    turn_off(_m) {
        console.log("Turned off X-raymachine.");
        _m.cur_state = new XRayOff();
    }

    uncover_tube(_m) {
        console.log("Uncovered X-raytube. Pictures can now be taken.");
        _m.cur_state = new XRayPictureMode();
    }

}

class XRayPictureMode extends XRayState {

    constructor() {
        super();
    }

    turn_off(_m) {
        console.log("Turned off X-raymachine.");
        _m.cur_state = new XRayOff();
    }

    cover_tube(_m) {
        console.log("Covered up X-raytube. No more pictures can be taken.");
        _m.cur_state = new XRayIdle();
    }

    take_picture(_m) {
        console.log("Took a X-raypicture.");
    }

}