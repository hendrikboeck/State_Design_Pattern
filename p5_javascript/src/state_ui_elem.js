class StateUI {

    constructor(state_class, x, y, width = 150, height = 50, round = 10) {
        this.state_class = state_class;
        this.x = x;
        this.y = y;
        this.width = width;
        this.height = height;
        this.round = round;

        this.clr;
    }

    set_color(clr) {
        this.clr = clr;
    }

    paint() {
        let font_size = 16;
        fill(this.clr);
        noStroke();
        rect(this.x, this.y, this.width, this.height, this.round);
        fill(0);
        textSize(font_size);
        textAlign(CENTER, CENTER)
        text(this.state_class, this.x + this.width / 2, this.y + this.height / 2);
    }

}

// class StateUIConnection {
// 
//     constructor(state_ui_1, state_ui_2, pos1, pos2, margin = 20, offset_x1 = 0, offset_y1 = 0, offset_x2 = 0, offset_y2 = 0) {
//         this.state_ui = [state_ui_1, state_ui_2];
//         this.pos = [pos1, pos2];
//         this.margin = margin;
//         this.offset_x = [offset_x1, offset_x2];
//         this.offset_y = [offset_y1, offset_y2];
//     }
// 
//     // TODO: improve function
//     paint() {
//         let waypoints = [];
//         let i = 0
// 
//         for (let j = 0; j < this.pos.length; j++) {
//             if (this.pos[j] == "right") {
//                 waypoints[i++] = [this.state_ui[j].width + this.state_ui[j].x + this.offset_x[j], this.state_ui[j].height / 2 + this.state_ui[j].y + this.offset_y[j]];
//             } else if (this.pos[j] == "left") {
//                 waypoints[i++] = [this.state_ui[j].x + this.offset_x[j], this.state_ui[j].height / 2 + this.state_ui[j].y + this.offset_y[j]];
//             } else if (this.pos[j] = "top") {
//                 if (j == 1)
//                     waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y - this.margin + this.offset_y[j]];
//                 waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y + this.offset_y[j]];
//                 if (j == 0)
//                     waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y - this.margin + this.offset_y[j]];
//             } else if (this.pos[j] == "bottom") {
//                 if (j == 1)
//                     waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y + this.state_ui[j].height + this.margin + this.offset_y[j]];
//                 waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y + this.state_ui[j].height + this.offset_y[j]];
//                 if (j == 0)
//                     waypoints[i++] = [this.state_ui[j].x + this.state_ui[j].width / 2 + this.offset_x[j], this.state_ui[j].y + this.state_ui[j].height + this.margin + this.offset_y[j]];
//             }
//         }
// 
//         for (let i = 0; i < waypoints.length - 1; i++) {
//             line(waypoints[i][0], waypoints[i][1], waypoints[i + 1][0], waypoints[i + 1][1]);
//         }
//     }
// 
// }