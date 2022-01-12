/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_draw_stage2.c
*/

#include "../include/my.h"

void draw_ground(t_render *render)
{
    static int more = 25;
    int i = render->x_coord / 48 - 1;

    while (++i < more) {
        sfSprite_setPosition(render->text->grass, get_pos(i * 48, 672));
        sfRenderWindow_drawSprite(render->win, render->text->grass, NULL);
    }
    more++;
}

void draw_stage_mineone(sfRenderWindow *window, t_render *render)
{
    draw_parralax(window, render);
    draw_ground(render);
    sfText_setPosition(render->play, get_pos(render->x_coord + 910, 150));
    sfText_setPosition(render->customize, get_pos(render->x_coord + 910, 250));
    sfText_setPosition(render->quit, get_pos(render->x_coord + 910, 300));
    sfRenderWindow_drawText(render->win, render->play, NULL);
    sfRenderWindow_drawText(render->win, render->customize, NULL);
    sfRenderWindow_drawText(render->win, render->quit, NULL);
    sfRenderWindow_drawSprite(window, render->boy->sprite, NULL);
    render->pos_sign = get_pos(-80000, -700);
    render->changing_state = 0;
    render->pop_state = 0;
    render->pop_anim = 1;
}
