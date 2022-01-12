/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_run_window.c
*/

#include "../include/my.h"

void draw_window(sfRenderWindow *window, t_render *render, sfEvent event)
{
    sfRenderWindow_clear(window, sfWhite);
    if (render->game == -2)
        draw_stage_mintwo(window, render, event);
    if (render->game == -1)
        draw_stage_mineone(window, render);
    if (render->game == 0 || render->game == 1)
        draw_stage_one(window, render, event);
    if (render->game == 2)
        draw_stage_two(render, event);
    sfRenderWindow_display(window);
}

void run_window(
sfRenderWindow *window, sfEvent event, char **av, t_render *render)
{
    sfMusic_play(render->mshub);
    while (sfRenderWindow_isOpen(window)) {
        clocker(window, render);
        draw_window(window, render, event);
        while (sfRenderWindow_pollEvent(window, &event))
            analyse_events(window, event, render);
    }
    clear_n_leave(render);
}
