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
 * File: test.cpp
 * --------------
 * This file tests the functionality of the class XRayMachine and its
 * dependencies.
 */

#include "include/xraymachine.h"

int main(int argc, char **argv)
{
    XRayMachine m{};

    m.turn_on();
    m.cover_tube();
    m.turn_on();
    m.unconver_tube();
    m.take_picture();
    m.turn_off();

    return 0;
}
