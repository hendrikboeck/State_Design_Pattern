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

class ButtonBar {

  constructor(x, y, padding_x) {
    this.x = x;
    this.y = y;
    this.padding_x = padding_x;
    this.buttons = new Map()
  }

  add(id, txt, func = null) {
    this.buttons.set(id, createButton(txt));
    if (func) this.buttons.get(id).mousePressed(func);
  }

  render() {
    let i = 0;
    let prev_btn;

    for (const [key, btn] of this.buttons.entries()) {
      if (i == 0)
        btn.position(this.x, this.y);
      else
        btn.position(prev_btn.x + prev_btn.width + this.padding_x, this.y);

      i++;
      prev_btn = btn;
    }
  }

  get(id) {
    return tgus.buttons.get(id)
  }

}

class Connection {

  constructor(points) {
    this.points = points;
  }

  render(color = 0) {
    stroke(color)
    strokeWeight(1);
    noFill();
    beginShape();

    for(const tpl of this.points) {
      curveVertex(tpl[0], tpl[1]);
    }

    endShape();
  }

}