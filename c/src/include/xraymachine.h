/*************************************************************************/
/* XRay State Machine (C Implementation)                                 */
/* Copyright (C) 2020 by Hendrik Boeck                                   */
/*                                                                       */
/* This program is free software: you can redistribute it and/or modify  */
/* it under the terms of the GNU General Public License as published by  */
/* the Free Software Foundation, either version 3 of the License, or     */
/* (at your option) any later version.                                   */
/*                                                                       */
/* This program is distributed in the hope that it will be useful,       */
/* but WITHOUT ANY WARRANTY; without even the implied warranty of        */
/* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the         */
/* GNU General Public License for more details.                          */
/*                                                                       */
/* You should have received a copy of the GNU General Public License     */
/* along with this program.  If not, see <http://www.gnu.org/licenses/>. */
/*************************************************************************/

/*
 * File: xraymachine.h
 * -------------------
 * This file defines the interface of XRayMachine
 */

#ifndef XRAYMACHINE_H_
#define XRAYMACHINE_H_

#include "xraystate.h"

// predefining XRayState, because the Files are reciprocally dependent
typedef struct XRayStateCDT *XRayState;

/**
 * Definition: XRayMachineCDT
 * --------------------------
 * Definition of struct XRayMachineCDT. Holds one attribute, to dertermine
 * its current actionrange, based on its state.
 */
struct XRayMachineCDT
{
    XRayState cur_state;
};

/**
 * Defintion: XRayMachine
 * ----------------------
 * Defines a pointer on struct XRayMachineCDT
 */
typedef struct XRayMachineCDT *XRayMachine;

/**
 * Function: new_xraymachine
 * Usage: m = new_xraymachine();
 * -----------------------------
 * Creates a new object of struct XRayMachineCDT and assigns it intial 
 * values. At the end, the function returns a pointer to newly created 
 * object. 
 */
XRayMachine new_xraymachine();

/**
 * Function: delete_xraymachine
 * Usage: delete_xraymachine(m);
 * -----------------------------
 * Frees the spaces, allocated to XRayMachine and its Attributes, such
 * as XRayState.
 */
void delete_xraymachine(XRayMachine m);

/**
 * Function: turn_on
 * Usage: turn_on(m);
 * ------------------
 * Turns on the XRayMachine. If XRayMachine can not be turned on at 
 * current point in time, an adequate error-message is given. 
 */
void turn_on_xraymachine(XRayMachine m);

/**
 * Function: turn_off
 * Usage: turn_off(m);
 * -------------------
 * Turns off the XRayMachine. If XRayMachine can not be turned off at
 * current point in time, an adequate error-message is given.
 */
void turn_off_xraymachine(XRayMachine m);

/**
 * Function: cover_tube
 * Usage: cover_tube(m);
 * ---------------------
 * Covers up the X-raytube of XRayMachine. If X-raytube can not be covered
 * up at current poit in time, an adequate error-message is given.
 */
void cover_tube_xraymachine(XRayMachine m);

/**
 * Function: uncover_tube
 * Usage: uncover_tube(m);
 * -----------------------
 * 
 */
void uncover_tube_xraymachine(XRayMachine m);

void take_picture_xraymachine(XRayMachine m);

#endif /* XRAYMACHINE_H_ */