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
 * File: xraymachine.cpp
 * ---------------------
 * This file implements the class XRayMachine
 */

#include "xraymachine.h"

XRayMachine::XRayMachine() : cur_state(std::make_unique<XRayOff>()) {}

XRayMachine::XRayMachine(XRayMachine &&other) : cur_state(std::move(other.cur_state)) {}

void XRayMachine::turn_on() { cur_state->turn_on(this); }

void XRayMachine::turn_off() { cur_state->turn_off(this); }

void XRayMachine::cover_tube() { cur_state->cover_tube(this); }

void XRayMachine::unconver_tube() { cur_state->uncover_tube(this); }

void XRayMachine::take_picture() { cur_state->take_picture(this); }
