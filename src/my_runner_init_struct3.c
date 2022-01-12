/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_init_struct3.c
*/

#include "../include/my.h"

void more_inits(t_render *render)
{
    render->coins_txt = sfText_create();
    init_txt_template(render, 50, "0", render->coins_txt);
    render->highscore = sfText_create();
    init_txt_template(render, 50, "0", render->highscore);
    if (render->infinity)
        render->high = my_get_map_in_str("save/highscore.txt");
}

void infinit_handler(t_render *render)
{
    if (render->infinity) {
        sfText_setPosition(render->highscore, get_pos(render->x_coord + 9, 9));
        sfText_setString(render->highscore, render->high);
        sfText_setColor(render->highscore, sfRed);
        sfRenderWindow_drawText(render->win, render->highscore, NULL);
    }
}
