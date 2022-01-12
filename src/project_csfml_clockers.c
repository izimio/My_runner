/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_clokers.c
*/

#include "../include/my.h"

void clock_boy_sprite(t_render *render, sfMusic *music)
{
    if (sfClock_getElapsedTime(render->clocker->sprite_rec).microseconds /
    10000 >=
    7) {
        if (render->volum < 30) {
            render->volum += 0.2;
            sfMusic_setVolume(music, render->volum);
        }
        if (render->boy->jump && render->game == 0) {
            render->boy->rect.left = 90;
            sfSprite_setTextureRect(
            render->boy->sprite, get_rect(650, 240, 70, 75));
            return;
        }

        sfSprite_setTextureRect(render->boy->sprite, render->boy->rect);
        render->boy->rect.left += 80;
        if (render->boy->rect.left >= 660)
            render->boy->rect.left = 10;
        sfClock_restart(render->clocker->sprite_rec);
    }
}

void clock_boy_mov(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->sprite_mouv).microseconds >=
    0.0000000000001) {
        render->boy->pos.x += render->fast;
        sfSprite_setPosition(render->boy->sprite, render->boy->pos);
        sfClock_restart(render->clocker->sprite_mouv);
    }
}

void clock_boy_jump(t_render *render)
{
    if (sfClock_getElapsedTime(render->clocker->jump).microseconds / 10000 >=
    0.5 &&
    render->game == 0) {
        gravity(render);
        sfClock_restart(render->clocker->jump);
    }
}

void clock_mov_window(sfRenderWindow *window, t_render *render, int add)
{
    if (sfClock_getElapsedTime(render->clocker->window_mov).microseconds) {
        render->x_coord += add;
        sfView_move(render->view, get_pos(add, 0));
        sfRenderWindow_setView(window, render->view);
        sfClock_restart(render->clocker->window_mov);
    }
}

void clocker(sfRenderWindow *window, t_render *render)
{
    if (render->boy->alive)
        clock_boy_jump(render);
    if (render->game != 1)
        clock_all_sprites(render);
    if (render->game == -1 || render->game == -2 && render->boy->alive)
        clock_boy_sprite(render, render->mshub);
    if (render->game == 0 && render->boy->alive)
        clock_boy_sprite(render, render->msgame);
    if (render->game != 1 && render->boy->alive) {
        clock_mov_window(window, render, render->fast);
        clock_boy_mov(render);
    }
    if (render->game == 0)
        collision(render);
}
