/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_draw_sk_stage2.c
*/

#include "../include/my.h"

void reset_map(t_render *render)
{
    int i = -1;
    int j = -1;

    while (++i < render->map_h) {
        j = -1;
        while (++j < render->map_x)
            render->map[i][j].id =
            (render->map[i][j].id == '+' ? '*' : render->map[i][j].id);
    }
}

void oupsy_woopsy(char *s)
{
    int i = -1;

    while (s[++i])
        s[i] = '\0';
}

void fix_coin_nb(t_render *render)
{
    int i = get_coin_nb(render->mapp);
    int nb = i - render->nb_of_coins;
    int len = count_int_len(nb * 2);
    int size = len * 2 + 4;
    char *k = my_itoa(i);
    char *s = my_itoa(nb);
    char *res = malloc(sizeof(char) * size);
    int d = -1;
    int j = 0;

    oupsy_woopsy(res);
    while (s[++d])
        res[j++] = s[d];
    res[j++] = ' ';
    res[j++] = '\\';
    res[j++] = ' ';
    d = -1;
    while (k[++d])
        res[j++] = k[d];
    sfText_setString(render->coins_txt, res);
}

void my_useles_stage_2(t_render *render)
{
    sfSprite_setTextureRect(render->coin, get_rect(0, 0, 50, 48));
    sfText_setPosition(render->replay, get_pos(render->x_coord + 510, 340));
    sfText_setPosition(render->percent, get_pos(render->x_coord + 490, 85));
    sfText_setString(render->percent, "100 %");
    sfText_setColor(render->percent, sfYellow);
    sfText_setCharacterSize(render->percent, 110);
    sfText_setPosition(render->home, get_pos(render->x_coord + 540, 440));
    sfText_setPosition(render->death_txt, get_pos(render->x_coord + 510, 232));
    sfSprite_setPosition(render->skull, get_pos(render->x_coord + 440, 250));
    sfSprite_setPosition(render->coin, get_pos(render->x_coord + 640, 270));
    sfText_setPosition(render->coins_txt, get_pos(render->x_coord + 680, 237));
    sfRenderWindow_drawSprite(render->win, render->skull, NULL);
    sfRenderWindow_drawSprite(render->win, render->coin, NULL);
    sfRenderWindow_drawText(render->win, render->replay, NULL);
    sfRenderWindow_drawText(render->win, render->coins_txt, NULL);
    sfRenderWindow_drawText(render->win, render->replay, NULL);
    sfRenderWindow_drawText(render->win, render->death_txt, NULL);
    sfRenderWindow_drawText(render->win, render->home, NULL);
    sfRenderWindow_drawText(render->win, render->percent, NULL);
}
