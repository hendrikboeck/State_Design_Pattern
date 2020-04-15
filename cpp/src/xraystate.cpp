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
 * File: xraystate.cpp
 * -------------------
 * This file implements the interface XRayState and all its subclasses
 */

#include "xraystate.h"

XRayState::~XRayState() = default;

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

void XRayOff::turn_off(XRayMachine *m)
{
    std::cerr << "Can not turn off machine. Machine is already turned";
    std::cerr << " off." << std::endl;
}

void XRayOff::cover_tube(XRayMachine *m)
{
    std::cerr << "Can not cover up X-raytube. X-raymachine is currently";
    std::cerr << " turned off." << std::endl;
}

void XRayOff::uncover_tube(XRayMachine *m)
{
    std::cerr << "Can not uncover X-raytube. X-raymachine is currently";
    std::cerr << " turned off." << std::endl;
}

void XRayOff::take_picture(XRayMachine *m)
{
    std::cerr << "Can not take picture. X-raymachine is currently turned";
    std::cerr << " off." << std::endl;
}

/**
 * Implementation of class XRayIdle
 */

XRayIdle::XRayIdle() = default;

XRayIdle::~XRayIdle() = default;

void XRayIdle::turn_on(XRayMachine *m)
{
    std::cerr << "Can not turn on machine. Machine is already turned";
    std::cerr << " on." << std::endl;
}

void XRayIdle::turn_off(XRayMachine *m)
{
    std::cout << "XRayMachine has been turned off." << std::endl;
    m->cur_state = new XRayOff();
    delete this;
}

void XRayIdle::cover_tube(XRayMachine *m)
{
    std::cerr << "Can not cover up X-raytube. X-raytube is already";
    std::cerr << " covered." << std::endl;
}

void XRayIdle::uncover_tube(XRayMachine *m)
{
    std::cout << "XRayMachine's X-ray-tube-cover has been removed.";
    std::cout << std::endl;
    m->cur_state = new XRayPictureMode();
    delete this;
}

void XRayIdle::take_picture(XRayMachine *m)
{
    std::cerr << "Can not take picture. X-raymachine is currently running";
    std::cerr << " in idle." << std::endl;
}

/**
 * Implementation of class XRayPictureMode
 */

XRayPictureMode::XRayPictureMode() = default;

XRayPictureMode::~XRayPictureMode() = default;

void XRayPictureMode::turn_on(XRayMachine *m)
{
    std::cerr << "Can not turn on machine. Machine is already turned";
    std::cerr << " on." << std::endl;
}

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

void XRayPictureMode::uncover_tube(XRayMachine *m)
{
    std::cerr << "Can not uncover X-raytube. X-raytube is already";
    std::cerr << " uncovered." << std::endl;
}

void XRayPictureMode::take_picture(XRayMachine *m)
{
    std::cout << "A X-ray-picture has been taken." << std::endl;
}
