/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_draw_stage.c
*/

#include "../include/my.h"

int get_percent(t_render *render)
{
    if (render->infinity) {
        sfText_setString(render->polecho, "pts");
        return ((int)render->boy->pos.x / 800);
    }
    int x = ((int)render->boy->pos.x + 20) / 48;

    return (x * 100 / render->x_towin);
}

void event_text(t_render *render, sfEvent event)
{
    reddit(render, render->resume, event);
    reddit(render, render->home, event);
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(render->win, render->home)) {
        render->game = -1;
        render->deaths = 0;
        sfMusic_stop(render->msgame);
        sfMusic_play(render->mshub);
        sfView_reset(render->view, get_rectf(0, 0, 1280, 720));
        sfRenderWindow_setView(render->win, render->view);
        render->x_coord = 0;
        render->boy->pos.x = 48;
        render->boy->pos.y = 610;
    }
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(render->win, render->resume))
        render->changing_state = 1;
}

void draw_p_text(t_render *render, sfEvent event)
{
    event_text(render, event);
    sfText_setPosition(render->pause, get_pos(render->x_coord + 440, 200));
    sfText_setPosition(render->resume, get_pos(render->x_coord + 510, 340));
    sfText_setPosition(render->home, get_pos(render->x_coord + 550, 440));
    sfRenderWindow_drawText(render->win, render->pause, NULL);
    sfRenderWindow_drawText(render->win, render->resume, NULL);
    sfRenderWindow_drawText(render->win, render->home, NULL);
}

void draw_pause(t_render *render, sfEvent event)
{
    if (render->game == 1) {
        if (!render->changing_state && render->game == 1)
            clock_sign(render);
        sfRenderWindow_drawSprite(render->win, render->sign, NULL);
        if (!render->changing_state && render->pos_sign.y >= -50) {
            draw_p_text(render, event);
        }
        if (render->changing_state && render->game == 1)
            clock_reverse_sign(render);
    }
}

void draw_stage_one(sfRenderWindow *window, t_render *render, sfEvent event)
{
    sfText_setColor(render->percent, sfBlack);
    sfText_setCharacterSize(render->percent, 50);
    sfText_setPosition(render->death_txt, get_pos(render->x_coord + 60, 9));
    sfSprite_setPosition(render->skull, get_pos(render->x_coord + 15, 20));
    sfText_setPosition(render->percent, get_pos(render->x_coord + 1070, 10));
    sfText_setPosition(render->polecho, get_pos(render->x_coord + 1150, 10));
    sfText_setPosition(render->highscore, get_pos(render->x_coord + 60, 9));
    draw_parralax(window, render);
    print_the_map(render, window);
    sfRenderWindow_drawSprite(window, render->boy->sprite, NULL);
    if (!render->infinity) {
        sfRenderWindow_drawSprite(render->win, render->skull, NULL);
        sfRenderWindow_drawText(render->win, render->death_txt, NULL);
    }
    infinit_handler(render);
    sfText_setString(render->percent, my_itoa(get_percent(render)));
    sfRenderWindow_drawText(render->win, render->percent, NULL);
    sfRenderWindow_drawText(render->win, render->polecho, NULL);
    draw_pause(render, event);
}
