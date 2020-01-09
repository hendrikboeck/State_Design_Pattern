#include "include/xraymachine.h"

XRayMachine new_xraymachine()
{
    XRayMachine m;

    m = (XRayMachine)malloc(sizeof(struct XRayMachineCDT));
    m->cur_state = new_xraystate();
    return m;
}

void delete_xraymachine(XRayMachine m)
{
    free(m->cur_state);
    free(m);
}

void turn_on_xraymachine(XRayMachine m)
{
    m->cur_state->turn_on(m);
}

void turn_off_xraymachine(XRayMachine m)
{
    m->cur_state->turn_off(m);
}

void cover_tube_xraymachine(XRayMachine m)
{
    m->cur_state->cover_tube(m);
}

void uncover_tube_xraymachine(XRayMachine m)
{
    m->cur_state->uncover_tube(m);
}

void take_picture_xraymachine(XRayMachine m)
{
    m->cur_state->take_picture(m);
}