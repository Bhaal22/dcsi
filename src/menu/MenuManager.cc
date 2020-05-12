#include "MenuManager.h"

int MenuManager::check_left()
{
    //uint8 c;
    //static cont_cond_t cond;

    maple_device_t *cont;
    cont_state_t *state;

    //c = maple_first_controller();
    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    /*if (cont_get_cond(c, &cond) < 0)
    return 0;*/

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_DPAD_LEFT)) {
    if (!(state->buttons & CONT_DPAD_LEFT))
    {
        menu2d.Setposcadre(menu2d.Getposcadre() - 1);
        if (menu2d.Getposcadre() < 0)
            menu2d.Setposcadre(2);
        menu2d.Setposcadrex((float)menu2d.Getposcadre() * 192.0);
        return 1;
    }

    return 0;
}

int MenuManager::check_right()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();

    //if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_DPAD_RIGHT)) {
    if (!(state->buttons & CONT_DPAD_RIGHT))
    {
        menu2d.Setposcadre((menu2d.Getposcadre() + 1) % 3);
        menu2d.Setposcadrex((float)menu2d.Getposcadre() * 192.0);
        return 1;
    }
    return 0;
}

int MenuManager::check_down()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();
    //  if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_DPAD_DOWN)) {
    if (!(state->buttons & CONT_DPAD_DOWN))
    {
        wav PassageSuivant("/rd/PassageSuivant.wav");
        PassageSuivant.play();
        if (menu2d.Getpos() == 0)
        {
            menu2d.Setpos(1);
            menu2d.Setposy(170.0);
        }
        else if (menu2d.Getpos() == 1)
        {
            menu2d.Setpos(2);
            menu2d.Setposy(245.0);
        }
        if (menu2d.Getpospause() == 0)
            menu2d.Setpospause(1);
        else
            menu2d.Setpospause(0);
        return 1;
    }
    return 0;
}

int MenuManager::check_up()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();

    //if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_DPAD_UP)) {
    if (!(state->buttons & CONT_DPAD_UP))
    {
        wav PassageSuivant("/rd/PassageSuivant.wav");
        PassageSuivant.play();
        if (menu2d.Getpos() == 2)
        {
            menu2d.Setpos(1);
            menu2d.Setposy(170.0);
        }
        else if (menu2d.Getpos() == 1)
        {
            menu2d.Setpos(0);
            menu2d.Setposy(85.0);
        }
        if (menu2d.Getpospause() == 0)
            menu2d.Setpospause(1);
        else
            menu2d.Setpospause(0);
        return 1;
    }
    return 0;
}

int MenuManager::check_a()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();
    //  if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_A)) {
    if (!(state->buttons & CONT_A))
    {
        return 1;
    }
    return 0;
}

int MenuManager::check_b()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();
    //  if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_B)) {
    if (!(state->buttons & CONT_B))
    {
        return 1;
    }
    return 0;
}

int MenuManager::check_y()
{
    //uint8 c;
    //static cont_cond_t cond;
    //c = maple_first_controller();
    //if (cont_get_cond(c, &cond) < 0)
    //  return 0;

    maple_device_t *cont;
    cont_state_t *state;

    cont = maple_enum_type(0, MAPLE_FUNC_CONTROLLER);

    if (cont)
    {
        state = (cont_state_t *)maple_dev_status(cont);

        if (!state)
            return 0;
    }

    //if (!(cond.buttons & CONT_Y)) {
    if (!(state->buttons & CONT_Y))
    {
        menu2d.screenShot();
        return 1;
    }
    return 0;
}

void MenuManager::IntroLaunch(void)
{
    menu2d.draw_intro();
}

int MenuManager::MenuLaunch(void)
{
    int done = 0;
    int done2 = 0;
    int done3 = 0;
    int passe = 0;

    wav SelectionMenuPrecedent("/rd/SelectionMenuPrecedent.wav");
    wav SelectionMenuSuivant("/rd/SelectionMenuSuivant.wav");

    ogg DreamStyle("/rd/DreamStyle.ogg");
    DreamStyle.setVolume(64);
    ogg genEric("/rd/GenEric.ogg");
    genEric.setVolume(128);
    DreamStyle.play(1);

    while (!done)
    {
        done2 = 0;
        check_down();
        check_up();
        menu2d.draw_frame();
        if (check_a() && menu2d.Getpos() == 0)
        {
            SelectionMenuSuivant.play();
            thd_sleep(200);
            while (!done2)
            {
                passe = 0;
                done3 = 0;
                if (check_b())
                {
                    done2 = 1;
                    SelectionMenuPrecedent.play();
                    thd_sleep(100);
                }
                check_left();
                check_right();
                menu2d.draw_perso();
                thd_sleep(110);
                if (check_a())
                {
                    if (passe == 0)
                    {
                        if (menu2d.Getposcadre() == 0)
                        {
                            wav son_carlos("/rd/carlos.wav");
                            son_carlos.play();
                            son_carlos.stop();
                        }
                        if (menu2d.Getposcadre() == 1)
                        {
                            wav son_momo("/rd/momo.wav");
                            son_momo.play();
                            son_momo.stop();
                        }
                        if (menu2d.Getposcadre() == 2)
                        {
                            wav son_noel("/rd/noel.wav");
                            son_noel.play();
                            son_noel.stop();
                        }
                        passe = 1;
                    }

                    thd_sleep(200);
                    while (!done3)
                    {
                        if (check_b())
                        {
                            SelectionMenuPrecedent.play();
                            done3 = 1;
                            thd_sleep(200);
                            DreamStyle.play(1);
                        }
                        if (check_a())
                        {
                            done3 = done2 = done = 1;
                        }
                        menu2d.draw_perso_choisi();
                    }
                }
            }
        }
        if (check_a() && menu2d.Getpos() == 1)
        {
            SelectionMenuSuivant.play();
            menu2d.draw_records();
            SelectionMenuPrecedent.play();
        }
        if (check_a() && menu2d.Getpos() == 2)
        {
            SelectionMenuSuivant.play();
            DreamStyle.stop();
            genEric.play(1);
            for (int ind = 0; ind < 5; ind++)
            {
                menu2d.draw_genEric(ind);
                menu2d.draw_gen_font(ind);
            }
            menu2d.draw_gen_font(5);
            menu2d.draw_gen_font(6);
            menu2d.Resetall();
            genEric.stop();
            SelectionMenuPrecedent.play();
            DreamStyle.play(1);
        }

        thd_sleep(200);
    }
    done = 0;
    DreamStyle.stop();

    menu2d.draw_game();
    return menu2d.Getposcadre();
}
