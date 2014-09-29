#include<kos.h> 
#include<math.h>
#include "MenuManager.h"
#include "Main.h"


#include <iostream>

//MenuManager mainMenu;


int main()
{
  int persoChoisi;

  std::cout << "Starting DCSI ..." << std::endl;
  MenuManager mainMenu;
  //pvr_init_defaults();
  //cdrom_init();
  bool cont = true;
  
  mainMenu.Init();
  mainMenu.IntroLaunch();
  persoChoisi = mainMenu.MenuLaunch();
  //mainMenu.Unload();
  pvr_shutdown();
  
  while (cont) {
	cont = myWorld::Init(persoChoisi);
	pvr_shutdown();
	persoChoisi = (persoChoisi + 1)%3;
	}

  std::cout << "Terminating DCSI ..." << std::endl;
}
