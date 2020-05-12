#include "MenuManager.h"

extern uint8 romdisk[];
KOS_INIT_ROMDISK(romdisk);

int main(void)
{
    MenuManager menu;

    menu.Init();
    menu.IntroLaunch();
    menu.MenuLaunch();
    menu.Unload();
    return 0;
}
