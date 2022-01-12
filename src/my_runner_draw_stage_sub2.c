/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_draw_stage_sub2.c
*/

#include "../include/my.h"

void load(t_render *render, int self)
{
    if (self == 0)
        render->boy->sprite = load_sprite("assets/sprite_sheet_blob.png", 0);
    if (self == 1)
        render->boy->sprite = load_sprite("assets/sprite_sheet_granny.png", 0);
    if (self == 2)
        render->boy->sprite = load_sprite("assets/sprite_sheet_steve.png", 0);
    if (self == 3)
        render->boy->sprite = load_sprite("assets/sprite_sheet_meat.png", 0);
}

void my_useles_sub2(t_render *render)
{
    sfRenderWindow_drawText(render->win, render->back, NULL);
    sfSprite_setPosition(
    render->skin_steve, get_pos(render->x_coord + 500, 280));
    sfSprite_setPosition(
    render->skin_blob, get_pos(render->x_coord + 760, 280));
    sfSprite_setPosition(
    render->skin_granny, get_pos(render->x_coord + 500, 440));
    sfSprite_setPosition(
    render->skin_meat, get_pos(render->x_coord + 760, 440));
    sfSprite_setTextureRect(render->boy->sprite, render->boy->rect);
}

void run_template(t_render *render, sfSprite *sprite, int self, sfEvent event)
{
    if (is_clicked_sprite(render->win, sprite)) {
        sfSprite_setTextureRect(sprite, render->skin_rec);
        render->skin_rec.left += 80;
        if (render->skin_rec.left >= 660)
            render->skin_rec.left = 10;
    }
    if (event.type == sfEvtMouseButtonPressed &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_sprite(render->win, sprite))
        load(render, self);
}

void clock_run(t_render *render, sfEvent event)
{
    if (sfClock_getElapsedTime(render->clocker->jump).microseconds / 10000 >=
    7) {
        run_template(render, render->skin_blob, 0, event);
        run_template(render, render->skin_granny, 1, event);
        run_template(render, render->skin_steve, 2, event);
        run_template(render, render->skin_meat, 3, event);
        sfClock_restart(render->clocker->jump);
    }
}

void draw_stage_mintwo(sfRenderWindow *window, t_render *render, sfEvent event)
{
    draw_parralax(window, render);
    draw_ground(render);
    sfText_setPosition(render->back, get_pos(render->x_coord + 1100, 620));
    my_useles_sub2(render);
    sfRenderWindow_drawSprite(window, render->boy->sprite, NULL);
    if (!render->changing_state) {
        clock_sign(render);
        clock_pop(render);
    } else {
        clock_reverse_sign(render);
        clock_pop_reverse(render);
    }
    sfRenderWindow_drawSprite(render->win, render->sign, NULL);
    if (render->pos_sign.y >= -50 || render->pop_state > 0) {
        sfRenderWindow_drawSprite(window, render->skin_steve, NULL);
        sfRenderWindow_drawSprite(window, render->skin_granny, NULL);
        sfRenderWindow_drawSprite(window, render->skin_blob, NULL);
        sfRenderWindow_drawSprite(window, render->skin_meat, NULL);
    }
    clock_run(render, event);
}
