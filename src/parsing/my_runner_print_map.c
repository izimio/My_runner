/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_print_map.c
*/

#include "../../include/my.h"

void print_template(int x, int y, t_render *render, sfSprite *sprite)
{
    sfSprite_setPosition(sprite, get_pos(x, y));
    sfRenderWindow_drawSprite(render->win, sprite, NULL);
}

void print_coin(t_render *render, int x, int y)
{
    if (render->game != 0)
        return;
    sfSprite_setPosition(
    render->coin, get_pos(x + render->coin_rec.left % 1, y + 15));
    sfRenderWindow_drawSprite(render->win, render->coin, NULL);
    if (sfClock_getElapsedTime(render->clocker->coin).microseconds / 10000 >=
    12) {
        sfSprite_setTextureRect(render->coin, render->coin_rec);
        render->coin_rec.left += 54;
        if (render->coin_rec.left >= 310)
            render->coin_rec.left = 0;
        sfClock_restart(render->clocker->coin);
    }
}

void print_each(int i, int j, t_render *render)
{
    int x = render->map[i][j].x;
    int y = render->map[i][j].y;

    if (render->map[i][j].id == '1')
        print_template(x, y, render, render->text->grass);
    if (render->map[i][j].id == '2')
        print_template(x, y, render, render->text->grass1);
    if (render->map[i][j].id == '3')
        print_template(x, y, render, render->text->stone);
    if (render->map[i][j].id == '4')
        print_template(x, y, render, render->text->rock);
    if (render->map[i][j].id == '5')
        print_template(x, y, render, render->text->wood);
    if (render->map[i][j].id == 'c')
        print_coin(render, x, y);
    if (render->map[i][j].id == '+')
        print_template(x, y, render, render->grave);
}

void print_the_map(t_render *render, sfRenderWindow *win)
{
    int i = -1;
    int j = ((int)render->boy->pos.x - 150) / 48;
    int y = j + 40;

    if (y >= render->map_x)
        y = render->map_x;
    while (++i < render->map_h) {
        while (++j < y)
            print_each(i, j, render);
        j = ((int)render->boy->pos.x - 150) / 48;
    }
}
