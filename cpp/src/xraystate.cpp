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

XRayState::~XRayState() {}

/**
 * Implementation of class XRayOff
 */

void XRayOff::turn_on(XRayMachine *m) {
  std::cout << "XRayMachine has been turned on." << std::endl;
  m->cur_state = std::make_unique<XRayIdle>();
}

void XRayOff::turn_off(XRayMachine *m) {
  std::cerr << "Can not turn off machine. Machine is already turned off."
            << std::endl;
}

void XRayOff::cover_tube(XRayMachine *m) {
  std::cerr
      << "Can not cover up X-raytube. X-raymachine is currently turned off."
      << std::endl;
}

void XRayOff::uncover_tube(XRayMachine *m) {
  std::cerr
      << "Can not uncover X-raytube. X-raymachine is currently turned off."
      << std::endl;
}

void XRayOff::take_picture(XRayMachine *m) {
  std::cerr << "Can not take picture. X-raymachine is currently turned off."
            << std::endl;
}

/**
 * Implementation of class XRayIdle
 */

void XRayIdle::turn_on(XRayMachine *m) {
  std::cerr << "Can not turn on machine. Machine is already turned on."
            << std::endl;
}

void XRayIdle::turn_off(XRayMachine *m) {
  std::cout << "XRayMachine has been turned off." << std::endl;
  m->cur_state = std::make_unique<XRayOff>();
}

void XRayIdle::cover_tube(XRayMachine *m) {
  std::cerr << "Can not cover up X-raytube. X-raytube is already covered."
            << std::endl;
}

void XRayIdle::uncover_tube(XRayMachine *m) {
  std::cout << "XRayMachine's X-ray-tube-cover has been removed." << std::endl;
  m->cur_state = std::make_unique<XRayPictureMode>();
}

void XRayIdle::take_picture(XRayMachine *m) {
  std::cerr
      << "Can not take picture. X-raymachine is currently running in idle."
      << std::endl;
}

/**
 * Implementation of class XRayPictureMode
 */

void XRayPictureMode::turn_on(XRayMachine *m) {
  std::cerr << "Can not turn on machine. Machine is already turned on."
            << std::endl;
}

void XRayPictureMode::turn_off(XRayMachine *m) {
  std::cout << "XRayMachine has been turned off." << std::endl;
  m->cur_state = std::make_unique<XRayOff>();
}

void XRayPictureMode::cover_tube(XRayMachine *m) {
  std::cout << "XRayMachine's X-ray-tube-cover has been put in place."
            << std::endl;
  m->cur_state = std::make_unique<XRayIdle>();
}

void XRayPictureMode::uncover_tube(XRayMachine *m) {
  std::cerr << "Can not uncover X-raytube. X-raytube is already uncovered."
            << std::endl;
}

void XRayPictureMode::take_picture(XRayMachine *m) {
  std::cout << "A X-ray-picture has been taken." << std::endl;
}
