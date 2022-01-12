/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** ny_runner_customize_character.c
*/

#include "../include/my.h"

void customize_chara(t_render *render, char *str)
{
    if (!str) {
        render->boy->sprite = load_sprite("assets/sprite_sheet_meat.png", 0);
        return;
    }
    if (render->boy->sprite)
        sfSprite_destroy(render->boy->sprite);
    if (!my_strcmp("meat", str))
        render->boy->sprite = load_sprite("assets/sprite_sheet_meat.png", 0);
    if (!my_strcmp("steve", str))
        render->boy->sprite = load_sprite("assets/sprite_sheet_steve.png", 0);
    if (!my_strcmp("granny", str))
        render->boy->sprite = load_sprite("assets/sprite_sheet_granny.png", 0);
    if (!my_strcmp("blob", str))
        render->boy->sprite = load_sprite("assets/sprite_sheet_blob.png", 0);
}
