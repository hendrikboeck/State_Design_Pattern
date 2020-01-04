#include "include/xraymachine.h"

XRayMachine::XRayMachine()
{
    cur_state = new XRayOff{};
}

XRayMachine::~XRayMachine()
{
    delete cur_state;
}

void XRayMachine::turn_on()
{
    cur_state->turn_on(this);
}

void XRayMachine::turn_off()
{
    cur_state->turn_off(this);
}

void XRayMachine::cover_tube()
{
    cur_state->cover_tube(this);
}

void XRayMachine::unconver_tube()
{
    cur_state->uncover_tube(this);
}

void XRayMachine::take_picture()
{
    cur_state->take_picture(this);
}