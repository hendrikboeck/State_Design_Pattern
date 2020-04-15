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

import xraystate

##
# definition of XRayMachine-class
#


class XRayMachine:

    cur_state=None

    ##
    # Function:     __init__
    # Usage:        m = XRayMachine()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Constructor of XRayMachine.
    #
    def __init__(self):
        self.cur_state = xraystate.XRayOff()

    ##
    # Function:     turn_on
    # Usage:        m.turn_on()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Turns on the XRayMachine.
    #
    def turn_on(self):
        self.cur_state.turn_on(self)

    ##
    # Function:     turn_off
    # Usage:        m.turn_off()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Turns off the XRayMachine.
    #
    def turn_off(self):
        self.cur_state.turn_off(self)

    ##
    # Function:     cover_tube
    # Usage:        m.cover_tube()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Covers the X-raytube, if tube is not already covered.
    #
    def cover_tube(self):
        self.cur_state.cover_tube(self)

    ##
    # Function:     uncover_tube
    # Usage:        m.uncover_tube()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Uncovers the X-raytube, if current state allows it.
    #               Otherwise a useful error-message will be given.
    #
    def uncover_tube(self):
        self.cur_state.uncover_tube(self)

    ##
    # Function:     take_picture
    # Usage:        m.take_picture()
    # Parameters:
    #   self (XRayMachine): Gets a reference  to itself. Will be automaticly
    #               handed over by Python.
    # Description:  Takes a picture, if current state allows it. Otherwise a
    #               useful error-message will be given.
    #
    def take_picture(self):
        self.cur_state.take_picture(self)
