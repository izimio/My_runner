/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_utils.c
*/

#include "../include/my.h"

sfSprite *load_sprite(char *s, int flag)
{
    sfTexture *text = sfTexture_createFromFile(s, NULL);
    sfSprite *sprite = sfSprite_create();

    if (flag == 1)
        sfTexture_setRepeated(text, sfTrue);
    sfSprite_setTexture(sprite, text, sfTrue);
    return (sprite);
}

sfIntRect get_rect(int left, int top, int width, int height)
{
    sfIntRect rect;

    rect.height = height;
    rect.width = width;
    rect.left = left;
    rect.top = top;
    return (rect);
}

sfVector2f get_pos(int x, int y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfVector2f get_posf(float x, float y)
{
    sfVector2f vec;

    vec.x = x;
    vec.y = y;
    return (vec);
}

sfBool is_clicked_sprite(sfRenderWindow *window, sfSprite *sprite)
{
    sfVector2i vec = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rec = sfSprite_getGlobalBounds(sprite);
    sfVector2f vee = sfRenderWindow_mapPixelToCoords(window, vec, NULL);

    return (sfFloatRect_contains(&rec, (int)vee.x, (int)vee.y));
}
