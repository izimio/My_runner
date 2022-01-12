/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_infinit_get.c
*/

#include "../../include/my.h"

int get_last_line_f(char *s, t_render *render, int flag)
{
    int i = 0;
    int u = -1;
    int count = -1;
    int def = 0;

    while (s[++u])
        i += (s[u] == '\n' ? 1 : 0);
    u = -1;
    while (s[++u]) {
        def += (s[u] == '\n' ? 1 : 0);
        count += (def == i ? 1 : 0);
        if (def == i && s[u] == 'w' && flag)
            render->x_towin = count;
    }
    return (count);
}

int get_height_f(char *s)
{
    int i = 0;
    int u = -1;

    while (s[++u])
        i += (s[u] == '\n' ? 1 : 0);
    return (i + 1);
}

void create_empty_map_f(t_render *r, char *s)
{
    r->map = malloc(sizeof(t_each_coord *) * get_height_f(s));
    int i = -1;
    int j = -1;

    r->map_x = get_last_line_f(s, r, 1);
    r->map_h = get_height_f(s);
    while (++i < r->map_h)
        r->map[i] = malloc(sizeof(t_each_coord) * r->map_x);
    i = -1;
    while (++i < r->map_h) {
        j = -1;
        while (++j < r->map_x) {
            r->map[i][j].x = 0;
            r->map[i][j].y = 0;
            r->map[i][j].id = '*';
        }
    }
}

void create_the_map_inf(t_render *r, char *s, int i, int j)
{
    r->nb_of_coins = get_coin_nb(s);
    r->mapp = s;
    int u = -1;
    int width = -50;
    int height = 0;

    create_empty_map_f(r, s);
    while (s[++u])
        if (s[u] == '\n') {
            i++;
            j = 0;
            width = -50;
            height += 48;
        } else {
            width += 48;
            r->map[i][j].id = (s[u] != ' ' ? s[u] : '*');
            r->map[i][j].x = width;
            r->map[i][j++].y = height;
        }
}
