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
