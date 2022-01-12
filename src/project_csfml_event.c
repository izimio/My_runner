/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_event.c
*/

#include "../include/my.h"

void basic_event(sfRenderWindow *window, sfEvent event, t_render *render)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeySpace &&
    render->game == 0) {
        if (render->boy->jump == 0 && is_on_floor(render)) {
            render->boy->jump = 1;
            render->gravity = -10;
        }
    }
    if (event.type == sfEvtKeyReleased && event.key.code == sfKeySpace &&
    render->game == -1) {
        reset_game(render);
    }
    if (event.type == sfEvtClosed) {
        sfRenderWindow_close(window);
        return;
    }
    if (event.type == sfResize)
        render->screen = sfRenderWindow_getSize(window);
}

void menue_event(sfRenderWindow *window, t_render *render, sfEvent event)
{
    reddit(render, render->play, event);
    reddit(render, render->customize, event);
    reddit(render, render->quit, event);
    reddit(render, render->back, event);
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(window, render->play))
        reset_game(render);
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(window, render->customize))
        render->game = -2;
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(window, render->quit) && render->game == -1)
        sfRenderWindow_close(window);
    if (event.type == sfEvtMouseButtonReleased &&
    event.mouseButton.button == sfMouseLeft &&
    is_clicked_txt(window, render->back))
        render->changing_state = 1;
}

void event_in_game(t_render *render, sfEvent event)
{
    if (event.type == sfEvtKeyPressed && event.key.code == sfKeyH &&
    (render->game == 0 || render->game == 1)) {
        if (render->game == 1)
            render->changing_state = 1;
        else {
            render->changing_state = 0;
            render->game = 1;
            render->pop_state = 0;
        }
    }
}

void analyse_events(sfRenderWindow *window, sfEvent event, t_render *render)
{
    basic_event(window, event, render);
    menue_event(window, render, event);
    event_in_game(render, event);
}
