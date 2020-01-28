###############################################################################
# XRay State Machine (Python 3.6 Implementation)                              #
# Copyright (C) 2020 by Hendrik Boeck                                         #
#                                                                             #
# This program is free software: you can redistribute it and/or modify it     #
# under the terms of the GNU General Public License as published by the Free  #
# Software Foundation, either version 3 of the License, or (at your option)   #
# any later version.                                                          #
#                                                                             #
# This program is distributed in the hope that it will be useful, but WITHOUT #
# ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or       #
# FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License for   #
# more details.                                                               #
#                                                                             #
# You should have received a copy of the GNU General Public License along     #
# with this program.  If not, see <http://www.gnu.org/licenses/>.             #
###############################################################################

import sys


##
# definition of __XRayState-class
#


class __XRayState:

    ##
    # Function:     turn_on
    # Usage:        s.turn_on(m)
    # Parameters:
    #   m (XRayMachine): Gets the reference to the XRayMachine which should be
    #               turned on.
    # Description:  Turns on the XRayMachine and changes the state of m from
    #               OFF to IDLE. If the machine is currently in another state
    #               than OFF, an adequate error will be given.
    #
    def turn_on(self, m):
        print("Can not turn on the X-raymachine. X-raymachine is already "
              "turned on.", file=sys.stderr)

    ##
    # Function:     turn_off
    # Usage:        s.turn_off(m)
    # Parameters:
    #   self (XRayState): Gets a reference to itself. Will be automaticly
    #               handed over by Python.
    #   m (XRayMachine): Gets the reference to the XRayMachine which should be
    #               turned on.
    # Description:  Turns off the XRayMachine and changes the state of m from
    #               any STATE, besides OFF, to OFF. If the machine is currently
    #               in the state OFF, an adequate error-message is given.
    #
    def turn_off(self, m):
        print("Can not turn off the X-raymachine. X-raymachine is already "
              "turned off.", file=sys.stderr)

    ##
    # Function:     cover_tube
    # Usage:        s.cover_tube(m)
    # Parameters:
    #   self (XRayState): Gets a reference to itself. Will be automaticly
    #               handed over by Python.
    #   m (XRayMachine): Gets the reference to the XRayMachine which should be
    #               turned on.
    # Description:  Covers up the X-ray-tube of the XRayMachine an changes the
    #               state of m from PICTURE_MODE to IDLE. If the machine is
    #               currently in another state than PICTURE_MODE, an adequate
    #               error-message is given.
    #
    def cover_tube(self, m):
        print("Can not cover up X-raytube. X-raymachine is currently in wrong"
              " state.", file=sys.stderr)

    ##
    # Function:     uncover_tube
    # Usage:        s.uncover_tube(m)
    # Parameters:
    #   self (XRayState): Gets a reference to itself. Will be automaticly
    #               handed over by Python.
    #   m (XRayMachine): Gets the reference to the XRayMachine which should be
    #               turned on.
    # Description:  Uncovers up the X-ray-tube of the XRayMachine an changes
    #               the state of m from IDLE to PICTURE_MODE. If the machine is
    #               currently in another state than IDLE, an adequate error-
    #               message is given.
    #
    def uncover_tube(self, m):
        print("Can not uncover X-raytube. X-raymachine is currently in wrong "
              "state.", file=sys.stderr)

    ##
    # Function:     take_picture
    # Usage:        s.take_picture(m)
    # Parameters:
    #   self (XRayState): Gets a reference to itself. Will be automaticly
    #               handed over by Python.
    #   m (XRayMachine): Gets the reference to the XRayMachine which should be
    #               turned on.
    # Description:  Takes a X-ray-picture with the XRayMachine an does not
    #               change the state of m. If the machine is currently in
    #               another state than PICTURE_MODE, an adequate error-message
    #               is given.
    #
    def take_picture(self, m):
        print("Can not take a X-raypicture. X-raymachine is currently in "
              "wrong state.", file=sys.stderr)


##
# definition of XRayOff-class
#


class XRayOff(__XRayState):

    def turn_on(self, m):
        print("X-raymachine has been turned on.")
        m.cur_state = XRayIdle()


##
# definition of XRayOff-class
#


class XRayIdle(__XRayState):

    def turn_off(self, m):
        print("X-raymachine has been turned off.")
        m.cur_state = XRayOff()

    def uncover_tube(self, m):
        print("Uncovered X-raytube. Pictures can now be taken.")
        m.cur_state = XRayPictureMode()


##
# definition of XRayOff-class
#


class XRayPictureMode(__XRayState):

    def turn_off(self, m):
        print("X-raymachine has been turned off.")
        m.cur_state = XRayOff()

    def cover_tube(self, m):
        print("Covered up X-raytube. No more pictures can be taken.")
        m.cur_state = XRayIdle()

    def take_picture(self, m):
        print("A X-raypicture has been taken.")
