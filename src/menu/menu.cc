#include "MenuManager.h"

extern uint8 romdisk[];
KOS_INIT_ROMDISK(romdisk);

int main(void)
{

    MenuManager lemenu;

    lemenu.Init();
    lemenu.IntroLaunch();
    lemenu.MenuLaunch();
    lemenu.Unload();
    return 0;
}
