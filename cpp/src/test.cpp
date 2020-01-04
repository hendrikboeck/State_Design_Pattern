#include "include/xraymachine.h"
#include "include/xraystate.h"

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
