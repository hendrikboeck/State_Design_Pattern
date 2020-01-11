class XRayMachine {

    constructor() {
        this.cur_state = new XRayOff();
    }

    turn_on() {
        this.cur_state.turn_on(this);
    }

    turn_off() {
        this.cur_state.turn_off(this);
    }

    cover_tube() {
        this.cur_state.cover_tube(this);
    }

    uncover_tube() {
        this.cur_state.uncover_tube(this);
    }

    take_picture() {
        this.cur_state.take_picture(this);
    }

}