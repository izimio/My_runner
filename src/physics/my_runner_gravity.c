/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_get_coord_int_tab.c
*/

#include "../../include/my.h"

void death(t_render *render, int y, int x)
{
    if (render->map[y][x - 1].id == '*' && render->map[y - 1][x].id != '*')
        render->map[y][x - 1].id = '+';
    if (render->map[y][x - 1].id == '*' && render->map[y - 1][x].id == '*') {
        render->map[y - 1][x].id = '+';
    }
}

int is_on_floor(t_render *render)
{
    int x = ((int)render->boy->pos.x + 40) / 48;
    int y = (720 - ((int)render->boy->pos.y) - 20) / 48;
    int real_h = render->map_h - y;

    if (in_charset(render->map[real_h][x].id, "*+c4"))
        return (0);
    return (1);
}

void gravity(t_render *render)
{
    int x = ((int)render->boy->pos.x + 48) / 48;
    int y = (720 - ((int)render->boy->pos.y) - 25) / 48;
    int real_h = render->map_h - y;

    if (y <= 0 || x > render->map_x) {
        render->game++;
        return;
    }
    if (is_on_floor(render) && render->gravity > 0) {
        render->gravity = 1;
        render->boy->jump = 0;
        return;
    }
    render->boy->pos.y += render->gravity;
    render->gravity += 0.3;
}

void coin_collision(t_render *render, int real_h, int x)
{
    if (render->map[real_h][x].id == 'c') {
        render->map[real_h][x].id = '*';
        render->nb_of_coins--;
        sfSound_play(render->mscoin);
    }
}

void collision(t_render *render)
{
    int y = (720 - ((int)render->boy->pos.y) - 30) / 48;
    int real_h = render->map_h - y - 1;
    int x = ((int)render->boy->pos.x + 40) / 48;

    if (x > render->map_x || y <= 0) {
        reset_game(render);
        return;
    }
    coin_collision(render, real_h, x);
    if (!in_charset(render->map[real_h][x].id, "*+wc")) {
        reset_game(render);
        death(render, real_h, x);
        sfSound_play(render->msdeath);
    }
    if (render->map[real_h][x].id == 'w') {
        sfMusic_setVolume(render->msgame, 5);
        sfSound_play(render->mswin);
        render->game = 2;
    }
}
