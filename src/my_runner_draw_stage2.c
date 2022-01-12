/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_draw_stage2.c
*/

#include "../include/my.h"

void aram(t_render *render)
{
    if (render->boy->pos.x / 48 >= render->map_x - 10) {
        sfView_reset(render->view, get_rectf(0, 0, 1280, 720));
        sfRenderWindow_setView(render->win, render->view);
        render->boy->pos.x = 0;
        render->x_coord = 0;
    }
}

void my_stage2_useles(t_render *render, sfEvent event)
{
    reddit(render, render->replay, event);
    reddit(render, render->home, event);
    clock_sign(render);
    aram(render);
    draw_parralax(render->win, render);
    print_the_map(render, render->win);
    sfRenderWindow_drawSprite(render->win, render->sign, NULL);
    sfSprite_setScale(render->skull, get_pos(2, 2));
    sfText_setScale(render->death_txt, get_pos(2, 2));
    if (render->deaths == 0)
        sfText_setColor(render->death_txt, sfYellow);
}

void reset_all(t_render *render)
{
    render->deaths = 0;
    sfSprite_setScale(render->skull, get_pos(1, 1));
    sfText_setScale(render->death_txt, get_pos(1, 1));
    sfText_setColor(render->death_txt, sfBlack);
    render->game = -1;
    sfView_reset(render->view, get_rectf(0, 0, 1280, 720));
    sfRenderWindow_setView(render->win, render->view);
    render->x_coord = 0;
    render->boy->pos.x = 48;
    render->boy->pos.y = 610;
}

void event_text_bis(t_render *render, sfEvent event)
{
    reddit(render, render->resume, event);
    reddit(render, render->home, event);
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(render->win, render->home)) {
        reset_all(render);
        sfMusic_stop(render->msgame);
        sfMusic_play(render->mshub);
        render->trig = 0;
    }
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(render->win, render->replay)) {
        reset_all(render);
        reset_game(render);
        render->trig = 0;
    }
}

void draw_stage_two(t_render *render, sfEvent event)
{
    if (!render->trig)
        fix_coin_nb(render);
    my_stage2_useles(render, event);
    if (render->pos_sign.y >= -50)
        my_useles_stage_2(render);
    event_text_bis(render, event);
    render->trig = 1;
}
