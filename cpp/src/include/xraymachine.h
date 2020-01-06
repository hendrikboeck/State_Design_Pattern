/*************************************************************************/
/* XRay State Machine (C++ Implementation)                               */
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
 * This file defines the class XRayMachine
 */

// FIXME: Include-protection is not correct
#ifndef XRAYMACHINE_H_
#define XRAYMACHINE_H_

#include "xraystate.h"

/**
 * Definition of XRayMachine-class
 */
class XRayMachine
{
public:
    /**
     * constructor of XRayMachine
     */
    XRayMachine();

    /**
     * Destructor of XRayMachine
     */
    ~XRayMachine();

    /**
     * Function: turn_on
     * Usage: m.turn_on()
     * ------------------
     * Turns on the XRayMachine.
     */
    void turn_on();

    /**
     * Function: turn_off
     * Usage: m.turn_off()
     * -------------------
     * Turns off the XRayMachine.
     */
    void turn_off();

    /**
     * Function: cover_tube
     * Usage: m.cover_tube()
     * ---------------------
     * Covers the x-raytube, if not allready covered. 
     */
    void cover_tube();

    /**
     * Function: unconver_tube
     * Usage: m.unconver_tube()
     * ------------------------
     * Uncovers the x-raytube if current state allows it. Otherwise a
     * useful error-message will be created.
     */
    void unconver_tube();

    /**
     * Function: take_picture
     * Usage: m.take_picture()
     * -----------------------
     * Takes a picture if current state allows it. Otherwise a useful
     * error-message will be created.
     */
    void take_picture();

    XRayState *cur_state;
};

#endif // XRAYMACHINE_H_