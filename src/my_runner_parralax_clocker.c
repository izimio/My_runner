/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_parralax_clocker.c
*/

#include "../include/my.h"

void reset_self_parralax(t_render *render, t_parralax_sprite *p, int addon)
{
    p->rect.left += addon;
    sfSprite_setTextureRect(p->sprite, p->rect);
    sfSprite_setPosition(p->sprite, get_pos(render->x_coord, 0));
}

void clock_all_sprites(t_render *render)
{
    if (sfClock_getElapsedTime(render->par->clouds).microseconds / 100000.0 >=
    0.09) {
        reset_self_parralax(render, render->par->p_clouds, 1);
        sfClock_restart(render->par->clouds);
    }
    if (sfClock_getElapsedTime(render->par->distant).microseconds / 100000.0 >=
    0.006) {
        reset_self_parralax(render, render->par->p_distant, 1);
        sfClock_restart(render->par->distant);
    }
    if (sfClock_getElapsedTime(render->par->front).microseconds / 100000.0 >=
    0.01) {
        reset_self_parralax(render, render->par->p_front, 2);
        sfClock_restart(render->par->front);
    }
    if (sfClock_getElapsedTime(render->par->near).microseconds / 100000.0 >=
    0.0003) {
        reset_self_parralax(render, render->par->p_near, 3);
        sfClock_restart(render->par->near);
    }
}
