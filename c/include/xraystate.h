#ifndef XRAYSTATE_H_
#define XRAYSTATE_H_

#include <stdio.h>
#include <stdlib.h>
#include "xraymachine.h"

// predefining XRayState, because the Files are reciprocally dependent
typedef struct XRayMachineCDT *XRayMachine;

struct XRayStateCDT
{
    void (*turn_on)(XRayMachine m);
    void (*turn_off)(XRayMachine m);
    void (*cover_tube)(XRayMachine m);
    void (*uncover_tube)(XRayMachine m);
    void (*take_picture)(XRayMachine m);
};

typedef struct XRayStateCDT *XRayState;

XRayState new_xraystate();
void delete_xraystate(XRayState s);

// STATE: OFF
XRayState new_xrayoff();
void turn_on_xrayoff(XRayMachine m);
void turn_off_xrayoff(XRayMachine m);
void cover_tube_xrayoff(XRayMachine m);
void uncover_tube_xrayoff(XRayMachine m);
void take_picture_xrayoff(XRayMachine m);

// STATE: IDLE
XRayState new_xrayidle();
void turn_on_xrayidle(XRayMachine m);
void turn_off_xrayidle(XRayMachine m);
void cover_tube_xrayidle(XRayMachine m);
void uncover_tube_xrayidle(XRayMachine m);
void take_picture_xrayidle(XRayMachine m);

// STATE: PICTURE_MODE
XRayState new_xraypicturemode();
void turn_on_xraypicturemode(XRayMachine m);
void turn_off_xraypicturemode(XRayMachine m);
void cover_tube_xraypicturemode(XRayMachine m);
void uncover_tube_xraypicturemode(XRayMachine m);
void take_picture_xraypicturemode(XRayMachine m);

#endif /* XRAYSTATE_H_ */