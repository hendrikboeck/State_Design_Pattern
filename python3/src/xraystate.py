from xraymachine import XRayMachine


class __XRayState:

    def turn_on(self, m):

    def turn_off(self, m):

    def cover_tube(self, m):

    def uncover_tube(self, m):

    def take_picture(self, m):


class XRayOff(__XRayState):

    def turn_on(self, m):


class XRayIdle(__XRayState):

    def turn_off(self, m):

    def uncover_tube(self, m):


class XRayPictureMode(__XRayState):

    def turn_off(self, m):

    def cover_tube(self, m):

    def take_picture(self, m):
