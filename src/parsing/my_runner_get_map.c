/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_get_map.c
*/

#include "../../include/my.h"

int get_last_line(char *s, t_render *render, int flag)
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

int get_height(char *s)
{
    int i = 0;
    int u = -1;

    while (s[++u])
        i += (s[u] == '\n' ? 1 : 0);
    return (i + 1);
}

void create_empty_map(t_render *r, char *file)
{
    char *s = my_get_map_in_str(file);
    r->map = malloc(sizeof(t_each_coord *) * get_height(s));
    int i = -1;
    int j = -1;

    r->map_x = get_last_line(s, r, 1);
    r->map_h = get_height(s);
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

int check_map(char *s, char *name, t_render *render)
{
    char **res = my_split(s, "\n");
    int c = get_last_line(s, NULL, 0);
    int h = get_height(s);
    int i = -1;
    int len = my_strlen(name, 0);

    if (h != 15)
        return (0);
    render->x_towin = my_strlen(res[13], 1);
    while (res[++i])
        if (my_strlen(res[i], 0) > c)
            return (0);
    if (name[len - 1] == 'p' && name[len - 2] == 'a' && name[len - 3] == 'm' &&
    name[len - 4] == '.')
        return (1);
    return (0);
}

void create_the_map(t_render *r, char *file, int i, int j)
{
    char *s = my_get_map_in_str(file);
    r->nb_of_coins = get_coin_nb(s);
    r->mapp = s;
    int u = -1;
    int width = -50;
    int height = 0;

    create_empty_map(r, file);
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
