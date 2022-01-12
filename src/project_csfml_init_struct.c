/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_init_struct.c
*/

#include "../include/my.h"

t_boy *init_meat_boy(t_render *render, int fast)
{
    t_boy *boy = malloc(sizeof(t_boy));

    boy->alive = 1;
    boy->fast = fast;
    boy->pos = get_pos(50, 610);
    boy->rect = get_rect(90, 0, 70, 75);
    boy->jump = 0;
    boy->trig = 1;
    boy->sprite = load_sprite("assets/sprite_sheet_meat.png", 0);
    sfSprite_setPosition(boy->sprite, boy->pos);
    sfSprite_setTextureRect(boy->sprite, boy->rect);
    return (boy);
}

t_clocks *init_clocks(t_render *render)
{
    t_clocks *clocker = malloc(sizeof(t_clocks));

    clocker->sprite_rec = sfClock_create();
    clocker->sprite_mouv = sfClock_create();
    clocker->jump = sfClock_create();
    clocker->window_mov = sfClock_create();
    clocker->transition = sfClock_create();
    clocker->animations = sfClock_create();
    clocker->music = sfClock_create();
    clocker->coin = sfClock_create();
    return (clocker);
}

void init_sprite(t_render *render)
{
    render->skin_blob = load_sprite("assets/sprite_sheet_blob.png", 0);
    render->skin_granny = load_sprite("assets/sprite_sheet_granny.png", 0);
    render->skin_steve = load_sprite("assets/sprite_sheet_steve.png", 0);
    render->skin_meat = load_sprite("assets/sprite_sheet_meat.png", 0);
    render->sign = load_sprite("assets/sign.png", 0);
    render->grave = load_sprite("assets/grave.png", 0);
    render->skull = load_sprite("assets/skull.png", 0);
    sfSprite_setScale(render->sign, get_posf(1.3, 1.2));
    sfSprite_setTextureRect(render->skin_blob, get_rect(90, 0, 70, 75));
    sfSprite_setTextureRect(render->skin_granny, get_rect(90, 0, 70, 75));
    sfSprite_setTextureRect(render->skin_steve, get_rect(90, 0, 70, 75));
    sfSprite_setTextureRect(render->skin_meat, get_rect(90, 0, 70, 75));
    render->skin_rec = get_rect(90, 0, 70, 75);
}

void init_basics(t_render *render, char **argv)
{
    render->game = -1;
    render->fast = 2;
    render->trans_sign = 0;
    render->gravity = 1;
    render->x_coord = 0;
    render->changing_state = 0;
    render->volum = 0;
    render->trig = 0;
    render->deaths = 0;
    init_music(render);
}

t_render *init_render(sfRenderWindow *window, char **argv, t_render *render)
{
    render->clocker = init_clocks(render);
    render->boy = init_meat_boy(render, 20);
    render->screen = sfRenderWindow_getSize(window);
    render->coin = load_sprite("assets/coin.png", 0);
    render->coin_rec = get_rect(0, 0, 53, 48);
    init_sprite(render);
    render->view = sfView_createFromRect(get_rectf(0, 0, 1280, 720));
    init_basics(render, argv);
    render->win = window;
    render->par = init_parralax_big(render);
    if (!render->infinity)
        create_the_map(render, argv[1], 0, 0);
    else
        create_the_map_inf(render, concat_double_tab(), 0, 0);
    init_txt(render);
    render->percent = sfText_create();
    init_txt_template(render, 50, "0", render->percent);
    render->polecho = sfText_create();
    fix_origin(render);
    init_txt_template(render, 50, " %", render->polecho);
}
