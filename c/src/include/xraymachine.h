#ifndef XRAYMACHINE_H_
#define XRAYMACHINE_H_

#include "xraystate.h"

// predefining XRayState, because the Files are reciprocally dependent
typedef struct XRayStateCDT *XRayState;

struct XRayMachineCDT
{
    XRayState cur_state;
};

typedef struct XRayMachineCDT *XRayMachine;

XRayMachine new_xraymachine();

void delete_xraymachine(XRayMachine m);

void turn_on_xraymachine(XRayMachine m);

void turn_off_xraymachine(XRayMachine m);

void cover_tube_xraymachine(XRayMachine m);

void uncover_tube_xraymachine(XRayMachine m);

void take_picture_xraymachine(XRayMachine m);

#endif /* XRAYMACHINE_H_ */