/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_smalls_event.c
*/

#include "../include/my.h"

void reload_infin_map(t_render *render)
{
    free(render->map);
    free(render->mapp);
    create_the_map_inf(render, concat_double_tab(), 0, 0);
}

int infinity_handler(t_render *render)
{
    if (render->infinity && render->game != -1) {
        if (get_percent(render) > my_getnbr(render->high)) {
            render->high = my_itoa(get_percent(render));
            write_on_file("save/highscore.txt", render->high, render);
        }
        render->game = -1;
        reload_infin_map(render);
        render->x_coord = 0;
        render->boy->pos.x = 48;
        render->boy->pos.y = 610;
        return 1;
    }
    return (0);
}

void reset_game(t_render *render)
{
    if (render->game != 0) {
        render->volum = 5;
        sfMusic_play(render->msgame);
        sfMusic_stop(render->mshub);
    } else
        render->deaths++;
    if (render->game != 0)
        reset_map(render);
    render->pop_state = 1;
    sfText_setString(render->death_txt, my_itoa(render->deaths));
    if (!infinity_handler(render))
        render->game = 0;
    sfView_reset(render->view, get_rectf(0, 0, 1280, 720));
    sfRenderWindow_setView(render->win, render->view);
    render->x_coord = 0;
    render->boy->pos.x = 48;
    render->boy->pos.y = 610;
    sfSprite_setScale(
    render->boy->sprite, get_posf(render->pop_state, render->pop_state));
}

void reddit(t_render *render, sfText *txt, sfEvent event)
{
    if (is_clicked_txt(render->win, txt)) {
        sfText_setColor(txt, sfRed);
    } else
        sfText_setColor(txt, sfBlack);
}
