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
 * File: test.c
 * ------------
 * This file tests the functionality of the class XRayMachine and its
 * dependencies.
 */

#include "include/xraymachine.h"

int main(int argc, char **argv)
{
    XRayMachine m = new_xraymachine();

    turn_on_xraymachine(m);
    cover_tube_xraymachine(m);
    turn_on_xraymachine(m);
    uncover_tube_xraymachine(m);
    take_picture_xraymachine(m);
    turn_off_xraymachine(m);

    delete_xraymachine(m);
    return 0;
}
