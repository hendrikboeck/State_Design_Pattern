/*************************************************************************/
/* State Design Pattern (C++ Implementation)                             */
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
 * File: xraystate.h
 * -----------------
 * This file defines the interface XRayState and all its subclasses
 */

// FIXME: Include-protection is not correct
#ifndef XRAYSTATE_H_
#define XRAYSTATE_H_

#include <iostream>
#include "xraymachine.h"

/**
 * Definition of interface XRayState
 */
class XRayState
{
public:
    /**
     * Make class XRayState fullvirtual
     */
    virtual ~XRayState() = 0;

    /**
     * Function: turn_on
     * Usage: OFF.turn_on(m);
     * ----------------------
     * Turns on the XRayMachine and changes the state of m from OFF to 
     * IDLE. If the machine is currently in another state than OFF, an 
     * adequate error-message is given.
     */
    virtual void turn_on(XRayMachine *m);

    /**
     * Function: turn_off
     * Usage: STATE.turn_off(m);
     * -------------------------
     * Turns off the XRayMachine and changes the state of m from any STATE,
     * besides OFF, to OFF. If the machine is currently in the state OFF,
     * an adequate error-message is given.
     */
    virtual void turn_off(XRayMachine *m);

    /**
     * Function: cover_tube
     * Usage: PICTURE_MODE.cover_tube(m);
     * ----------------------------------
     * Covers up the X-ray-tube of the XRayMachine an changes the state of
     * m from PICTURE_MODE to IDLE. If the machine is currently in another
     * state than PICTURE_MODE, an adequate error-message is given.  
     */
    virtual void cover_tube(XRayMachine *m);

    /**
     * Function: uncover_tube
     * Usage: IDLE.uncover_tube(m);
     * ----------------------------
     * Uncovers up the X-ray-tube of the XRayMachine an changes the state 
     * of m from IDLE to PICTURE_MODE. If the machine is currently in 
     * another state than IDLE, an adequate error-message is given.
     */
    virtual void uncover_tube(XRayMachine *m);

    /**
     * Function: take_picture
     * Usage: PICTURE_MODE.take_picture(m);
     * ------------------------------------
     * Takes a X-ray-picture with the XRayMachine an does not change the
     * state of m. If the machine is currently in another state than 
     * PICTURE_MODE, an adequate error-message is given.
     */
    virtual void take_picture(XRayMachine *m);
};

/**
 * Definition of STATE-classes
 */

// State: OFF
class XRayOff : public XRayState
{
public:
    XRayOff();
    ~XRayOff();
    void turn_on(XRayMachine *m);
};

// State: IDLE
class XRayIdle : public XRayState
{
public:
    XRayIdle();
    ~XRayIdle();
    void turn_off(XRayMachine *m);
    void uncover_tube(XRayMachine *m);
};

// State: PICTURE_MODE
class XRayPictureMode : public XRayState
{
public:
    XRayPictureMode();
    ~XRayPictureMode();
    void turn_off(XRayMachine *m);
    void cover_tube(XRayMachine *m);
    void take_picture(XRayMachine *m);
};

#endif