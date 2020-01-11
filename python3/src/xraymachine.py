from xraystate import XRayOff, XRayIdle, XRayPictureMode

class XRayMachine:

    def __init__(self):
        self.cur_state = new XRayState()
        pass