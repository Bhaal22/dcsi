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
        monmoteur.Setposcadre(monmoteur.Getposcadre() - 1);
        if (monmoteur.Getposcadre() < 0)
            monmoteur.Setposcadre(2);
        monmoteur.Setposcadrex((float)monmoteur.Getposcadre() * 192.0);
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
        monmoteur.Setposcadre((monmoteur.Getposcadre() + 1) % 3);
        monmoteur.Setposcadrex((float)monmoteur.Getposcadre() * 192.0);
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
        if (monmoteur.Getpos() == 0)
        {
            monmoteur.Setpos(1);
            monmoteur.Setposy(170.0);
        }
        else if (monmoteur.Getpos() == 1)
        {
            monmoteur.Setpos(2);
            monmoteur.Setposy(245.0);
        }
        if (monmoteur.Getpospause() == 0)
            monmoteur.Setpospause(1);
        else
            monmoteur.Setpospause(0);
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
        if (monmoteur.Getpos() == 2)
        {
            monmoteur.Setpos(1);
            monmoteur.Setposy(170.0);
        }
        else if (monmoteur.Getpos() == 1)
        {
            monmoteur.Setpos(0);
            monmoteur.Setposy(85.0);
        }
        if (monmoteur.Getpospause() == 0)
            monmoteur.Setpospause(1);
        else
            monmoteur.Setpospause(0);
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
        monmoteur.screenShot();
        return 1;
    }
    return 0;
}

void MenuManager::IntroLaunch(void)
{
    monmoteur.draw_intro();
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
        monmoteur.draw_frame();
        if (check_a() && monmoteur.Getpos() == 0)
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
                monmoteur.draw_perso();
                thd_sleep(110);
                if (check_a())
                {
                    if (passe == 0)
                    {
                        if (monmoteur.Getposcadre() == 0)
                        {
                            wav son_carlos("/rd/carlos.wav");
                            son_carlos.play();
                            son_carlos.stop();
                        }
                        if (monmoteur.Getposcadre() == 1)
                        {
                            wav son_momo("/rd/momo.wav");
                            son_momo.play();
                            son_momo.stop();
                        }
                        if (monmoteur.Getposcadre() == 2)
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
                        monmoteur.draw_perso_choisi();
                    }
                }
            }
        }
        if (check_a() && monmoteur.Getpos() == 1)
        {
            SelectionMenuSuivant.play();
            monmoteur.draw_record();
            SelectionMenuPrecedent.play();
        }
        if (check_a() && monmoteur.Getpos() == 2)
        {
            SelectionMenuSuivant.play();
            DreamStyle.stop();
            genEric.play(1);
            for (int ind = 0; ind < 5; ind++)
            {
                monmoteur.draw_genEric(ind);
                monmoteur.draw_gen_font(ind);
            }
            monmoteur.draw_gen_font(5);
            monmoteur.draw_gen_font(6);
            monmoteur.Resetall();
            genEric.stop();
            SelectionMenuPrecedent.play();
            DreamStyle.play(1);
        }

        thd_sleep(200);
    }
    done = 0;
    DreamStyle.stop();

    monmoteur.draw_game();
    return monmoteur.Getposcadre();
}
