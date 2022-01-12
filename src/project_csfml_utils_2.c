/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** project_csfml_utils_2.c
*/

#include "../include/my.h"

sfFloatRect get_rectf(int left, int top, int width, int height)
{
    sfFloatRect rect;

    rect.height = (float)height;
    rect.width = (float)width;
    rect.left = (float)left;
    rect.top = (float)top;
    return (rect);
}

sfBool is_clicked_txt(sfRenderWindow *window, sfText *txt)
{
    sfVector2i vec = sfMouse_getPositionRenderWindow(window);
    sfFloatRect rec = sfText_getGlobalBounds(txt);
    sfVector2f vee = sfRenderWindow_mapPixelToCoords(window, vec, NULL);

    return (sfFloatRect_contains(&rec, (int)vee.x, (int)vee.y));
}
