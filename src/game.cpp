#include <kos.h>
#include <math.h>
#include "menu/MenuManager.h"
//#include "menu/Menu2D.h"
#include "Main.h"

#include <iostream>

//MenuManager mainMenu;
extern uint8 romdisk[];

KOS_INIT_FLAGS(INIT_DEFAULT | INIT_MALLOCSTATS);
KOS_INIT_ROMDISK(romdisk);

int main()
{
    int persoChoisi;

    //std::cout << "Starting DCSI ..." << std::endl;
    MenuManager mainMenu;
    //pvr_init_defaults();
    //cdrom_init();
    bool cont = true;

    mainMenu.Init();
    mainMenu.IntroLaunch();
    persoChoisi = mainMenu.MenuLaunch();
    //mainMenu.Unload();
    pvr_shutdown();

    while (cont)
    {
        //cont = DCSI::Init(persoChoisi);
        pvr_shutdown();
        persoChoisi = (persoChoisi + 1) % 3;
    }

    std::cout << "Terminating DCSI ..." << std::endl;
}
