/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_concat_maps.c
*/

#include "../../include/my.h"

void my_memset(char *start, int value)
{
    int i = -1;

    while (start[++i])
        start[i] = (unsigned char)value;
}

t_infinit *init_inf_map(void)
{
    t_infinit *maps = malloc(sizeof(t_infinit));

    maps->m1 = my_split(my_get_map_in_str("maps/random_gen/1.map"), "\n");
    maps->m2 = my_split(my_get_map_in_str("maps/random_gen/2.map"), "\n");
    maps->m3 = my_split(my_get_map_in_str("maps/random_gen/3.map"), "\n");
    maps->m4 = my_split(my_get_map_in_str("maps/random_gen/4.map"), "\n");
    maps->m5 = my_split(my_get_map_in_str("maps/random_gen/5.map"), "\n");
    maps->m6 = my_split(my_get_map_in_str("maps/random_gen/6.map"), "\n");
    maps->m7 = my_split(my_get_map_in_str("maps/random_gen/7.map"), "\n");
    maps->m8 = my_split(my_get_map_in_str("maps/random_gen/8.map"), "\n");
    maps->m9 = my_split(my_get_map_in_str("maps/random_gen/9.map"), "\n");
    maps->m10 = my_split(my_get_map_in_str("maps/random_gen/10.map"), "\n");
    return (maps);
}

void cat_one_line(char **res, char **add)
{
    int i = -1;

    while (++i < 15)
        res[i] = my_strcat(res[i], add[i]);
}

void ret_to_add(int i, t_infinit *maps, char **res)
{
    if (i == 1)
        cat_one_line(res, maps->m1);
    if (i == 2)
        cat_one_line(res, maps->m2);
    if (i == 3)
        cat_one_line(res, maps->m3);
    if (i == 4)
        cat_one_line(res, maps->m4);
    if (i == 5)
        cat_one_line(res, maps->m5);
    if (i == 6)
        cat_one_line(res, maps->m6);
    if (i == 7)
        cat_one_line(res, maps->m7);
    if (i == 8)
        cat_one_line(res, maps->m8);
    if (i == 9)
        cat_one_line(res, maps->m9);
}

char *concat_double_tab(void)
{
    srand(time(NULL));
    char **res = malloc(sizeof(char *) * 16);
    int i = -1;
    t_infinit *maps = init_inf_map();
    unsigned long long seed = rand() + 1111111111111111111;
    int j;

    while (++i < 16) {
        res[i] = malloc(sizeof(char) * (my_strlen(maps->m1[1], 0) * 50));
        my_memset(res[i], 0);
    }
    i = -1;
    while (++i < 50) {
        j = rand() % 9 + 1;
        seed /= j;
        ret_to_add(seed % j, maps, res);
        seed = (seed <= 10000 ? rand() + 1111111111111111111 : seed);
    }
    res[15] = 0;
    return (my_strjoin(15, res, "\n"));
}
