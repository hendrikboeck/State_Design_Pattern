#include "xraystate.h"

XRayState new_xraystate()
{
    return new_xrayoff();
}

void delete_xraystate(XRayState s)
{
    free(s);
}

XRayState new_xrayoff()
{
    XRayState s;

    s = (XRayState)malloc(sizeof(struct XRayStateCDT));
    s->turn_on = turn_on_xrayoff;
    s->turn_off = turn_off_xrayoff;
    s->cover_tube = cover_tube_xrayoff;
    s->uncover_tube = uncover_tube_xrayoff;
    s->take_picture = take_picture_xrayoff;
    return s;
}

void turn_on_xrayoff(XRayMachine m)
{
    printf("X-raymachine has been turned on.\n");
    delete_xraystate(m->cur_state);
    m->cur_state = new_xrayidle();
}

void turn_off_xrayoff(XRayMachine m)
{
    fprintf(stderr, "Can not turn off X-raymachine. X-raymachine is "
                    " already turned off.\n");
}

void cover_tube_xrayoff(XRayMachine m)
{
    fprintf(stderr, "Can not cover X-raytube. X-raymachine is currently"
                    " turned off.\n");
}

void uncover_tube_xrayoff(XRayMachine m)
{
    fprintf(stderr, "Can not uncover X-raytube. X-raymachine is "
                    "currently turned off.\n");
}

void take_picture_xrayoff(XRayMachine m)
{
    fprintf(stderr, "Can not take picture. X-raymachine is currently"
                    " turned off.\n");
}

XRayState new_xrayidle()
{
    XRayState s;

    s = (XRayState)malloc(sizeof(struct XRayStateCDT));
    s->turn_on = turn_on_xrayidle;
    s->turn_off = turn_off_xrayidle;
    s->cover_tube = cover_tube_xrayoff;
    s->uncover_tube = uncover_tube_xrayidle;
    s->take_picture = take_picture_xrayidle;
    return s;
}

void turn_on_xrayidle(XRayMachine m)
{
    fprintf(stderr, "Can not turn on X-raymachine. X-raymachine is "
                    " already turned on.\n");
}

void turn_off_xrayidle(XRayMachine m)
{
    printf("X-raymachine has been turned off.\n");
    delete_xraystate(m->cur_state);
    m->cur_state = new_xrayoff();
}

void cover_tube_xrayidle(XRayMachine m)
{
    fprintf(stderr, "Can not cover X-raytube. X-raytube is already"
                    " covered.\n");
}

void uncover_tube_xrayidle(XRayMachine m)
{
    printf("Uncovered X-raytube. Pictures can now be taken.\n");
    delete_xraystate(m->cur_state);
    m->cur_state = new_xraypicturemode();
}

void take_picture_xrayidle(XRayMachine m)
{
    fprintf(stderr, "Can not take picture. X-raytube is currently"
                    " covered.\n");
}

XRayState new_xraypicturemode()
{
    XRayState s;

    s = (XRayState)malloc(sizeof(struct XRayStateCDT));
    s->turn_on = turn_on_xraypicturemode;
    s->turn_off = turn_off_xraypicturemode;
    s->cover_tube = cover_tube_xraypicturemode;
    s->uncover_tube = uncover_tube_xraypicturemode;
    s->take_picture = take_picture_xraypicturemode;
    return s;
}

void turn_on_xraypicturemode(XRayMachine m)
{
    fprintf(stderr, "Can not turn on X-raymachine. X-raymachine is "
                    " already turned on.\n");
}

void turn_off_xraypicturemode(XRayMachine m)
{
    printf("X-raymachine has been turned off.\n");
    delete_xraystate(m->cur_state);
    m->cur_state = new_xrayoff();
}

void cover_tube_xraypicturemode(XRayMachine m)
{
    printf("X-raytube is now covered. No more pictures can be taken.\n");
    delete_xraystate(m->cur_state);
    m->cur_state = new_xrayidle();
}

void uncover_tube_xraypicturemode(XRayMachine m)
{
    fprintf(stderr, "Can not remove cover from X-raytube. Cover is "
                    " already been removed.\n");
}

void take_picture_xraypicturemode(XRayMachine m)
{
    printf("A X-raypicture has been taken.\n");
}
