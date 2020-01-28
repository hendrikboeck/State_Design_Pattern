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

import xraymachine


def main():
    m = xraymachine.XRayMachine()
    m.turn_off()
    m.turn_on()
    m.uncover_tube()
    m.take_picture()
    m.cover_tube()
    m.take_picture()
    m.turn_off()


##
# MAIN-FUNCTION (call of program)
#

if __name__ == "__main__":
    main()
