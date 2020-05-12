#ifndef _MENUMANAGERH__
#define _MENUMANAGERH__

#include "Menu2D.h"
#include "io/ogg.h"
#include "io/wav.h"

class MenuManager
{
public:
    MenuManager(){};
    ~MenuManager(){};

    /* Lancement Introduction*/
    void Init(void)
    {
        ogg::init();
    };
    void IntroLaunch(void);
    int MenuLaunch(void);
    void Unload(void)
    {
        ogg::shutDown();
    };

    /*Gestion manette*/
    int check_left(void);
    int check_right(void);
    int check_up(void);
    int check_down(void);

    int check_a(void);
    int check_b(void);
    int check_y(void);

private:
    Menu2D monmoteur;
};

#endif
