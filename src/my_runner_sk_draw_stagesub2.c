/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_sk_draw_stagesub2.c
*/

#include "../include/my.h"

void clock_sign(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->transition).microseconds) {
        render->pos_sign.x = render->x_coord + 310;
        if (render->pos_sign.y <= -50)
            render->pos_sign.y += 3;
        sfSprite_setPosition(render->sign, render->pos_sign);
        sfClock_restart(render->clocker->transition);
    }
}

void clock_reverse_sign(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->transition).microseconds) {
        render->pos_sign.x = render->x_coord + 310;
        if (render->pos_sign.y >= -700 && render->pop_state <= 0)
            render->pos_sign.y -= 3;
        if (render->pos_sign.y <= -700)
            render->game = render->game == -2 ? -1 : 0;
        sfSprite_setPosition(render->sign, render->pos_sign);
        sfClock_restart(render->clocker->transition);
    }
}

void clock_pop(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->animations).microseconds) {
        if (render->pos_sign.y >= -50 && render->pop_state < 1.4) {
            sfSprite_setScale(render->skin_steve,
            get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(render->skin_granny,
            get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(
            render->skin_meat, get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(
            render->skin_blob, get_posf(render->pop_state, render->pop_state));
            render->pop_state += 0.04;
        }
        sfClock_restart(render->clocker->animations);
    }
}

void clock_pop_reverse(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->animations).microseconds) {
        if (render->pop_state > 0) {
            sfSprite_setScale(render->skin_steve,
            get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(render->skin_granny,
            get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(
            render->skin_meat, get_posf(render->pop_state, render->pop_state));
            sfSprite_setScale(
            render->skin_blob, get_posf(render->pop_state, render->pop_state));
            render->pop_state -= 0.04;
        } else
            render->pop_anim = 0;
        sfClock_restart(render->clocker->animations);
    }
}
