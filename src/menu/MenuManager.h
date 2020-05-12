#pragma once

#include "Menu2D.h"
#include "io/ogg.h"
#include "io/wav.h"

class MenuManager
{
public:
    MenuManager() {};
    ~MenuManager() {};

    void Init()
    {
        ogg::init();
    };
    void IntroLaunch();
    int MenuLaunch();

    void Unload()
    {
        ogg::shutDown();
    };

private:
    int check_left();
    int check_right();
    int check_up();
    int check_down();

    int check_a();
    int check_b();
    int check_y();

private:
    Menu2D menu2d;
};

