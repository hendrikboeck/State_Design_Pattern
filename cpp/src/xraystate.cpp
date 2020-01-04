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
 * File: xraystate.cpp
 * -------------------
 * This file implements the interface XRayState and all its subclasses
 */

#include "include/xraystate.h"

/**
 * Implementation of interface XRayState
 */

void XRayState::turn_on(XRayMachine *m)
{
    std::cerr << "unexpected error: <turn_on> failed to execute; machine"
              << "is in wrong state." << std::endl;
}

void XRayState::turn_off(XRayMachine *m)
{
    std::cerr << "unexpected error: <turn_off> failed to execute; machine"
              << "is in wrong state." << std::endl;
}

void XRayState::cover_tube(XRayMachine *m)
{
    std::cerr << "unexpected error: <cover_tube> failed to execute; "
              << "machine is in wrong state." << std::endl;
}

void XRayState::uncover_tube(XRayMachine *m)
{
    std::cerr << "unexpected error: <uncover_tube> failed to execute; "
              << "machine is in wrong state." << std::endl;
}

void XRayState::take_picture(XRayMachine *m)
{
    std::cerr << "unexpected error: <take_picture> failed to execute; "
              << "machine is in wrong state." << std::endl;
}

/**
 * Implementation of class XRayOff
 */

XRayOff::XRayOff() = default;

XRayOff::~XRayOff() = default;

void XRayOff::turn_on(XRayMachine *m)
{
    std::cout << "XRayMachine has been turned on." << std::endl;
    m->cur_state = new XRayIdle();
    delete this;
}

/**
 * Implementation of class XRayIdle
 */

XRayIdle::XRayIdle() = default;

XRayIdle::~XRayIdle() = default;

void XRayIdle::turn_off(XRayMachine *m)
{
    std::cout << "XRayMachine has been turned off." << std::endl;
    m->cur_state = new XRayOff();
    delete this;
}

void XRayIdle::uncover_tube(XRayMachine *m)
{
    std::cout << "XRayMachine's X-ray-tube-cover has been removed.";
    std::cout << std::endl;
    m->cur_state = new XRayPictureMode();
    delete this;
}

/**
 * Implementation of class XRayPictureMode
 */

XRayPictureMode::XRayPictureMode() = default;

XRayPictureMode::~XRayPictureMode() = default;

void XRayPictureMode::turn_off(XRayMachine *m)
{
    std::cout << "XRayMachine has been turned off." << std::endl;
    m->cur_state = new XRayOff();
    delete this;
}

void XRayPictureMode::cover_tube(XRayMachine *m)
{
    std::cout << "XRayMachine's X-ray-tube-cover has been put in place.";
    std::cout << std::endl;
    m->cur_state = new XRayIdle();
    delete this;
}

void XRayPictureMode::take_picture(XRayMachine *m)
{
    std::cout << "A X-ray-picture has been taken." << std::endl;
}
