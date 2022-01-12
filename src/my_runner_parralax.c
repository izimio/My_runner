/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_parralax.c
*/

#include "../include/my.h"

t_parralax_sprite *create_each_p(t_render *render, char *str, int width)
{
    t_parralax_sprite *p = malloc(sizeof(t_parralax_sprite));

    p->rect = get_rect(0, 0, width, 800);
    p->width = width;
    p->sprite = load_sprite(str, 1);
    sfSprite_setScale(p->sprite, get_posf(1.3, 1));
    return (p);
}

t_parralax *init_parralax_big(t_render *render)
{
    t_parralax *p = malloc(sizeof(t_parralax));

    p->clouds = sfClock_create();
    p->distant = sfClock_create();
    p->front = sfClock_create();
    p->near = sfClock_create();
    p->p_clouds = create_each_p(render, "assets/parralax/p_clouds.png", 2048);
    p->p_distant =
    create_each_p(render, "assets/parralax/p_distant.png", 1023);
    p->p_front = create_each_p(render, "assets/parralax/p_front.png", 1023);
    p->p_near = create_each_p(render, "assets/parralax/p_near.png", 1023);
    return (p);
}

void draw_parralax(sfRenderWindow *window, t_render *render)
{
    sfRenderWindow_drawSprite(window, render->par->p_clouds->sprite, NULL);
    sfRenderWindow_drawSprite(window, render->par->p_distant->sprite, NULL);
    sfRenderWindow_drawSprite(window, render->par->p_front->sprite, NULL);
    sfRenderWindow_drawSprite(window, render->par->p_near->sprite, NULL);
}
