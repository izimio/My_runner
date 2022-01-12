/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_highscore.c
*/

#include "../../include/my.h"

void my_free_char(char **res)
{
    int i = -1;

    while (res[++i])
        free(res[i]);
    free(res);
}

void my_sort_int_array(int *array, int size)
{
    int i = -1;
    int tmp;

    size--;
    while (++i < size) {
        if (array[i + 1] < array[i]) {
            tmp = array[i];
            array[i] = array[i + 1];
            array[i + 1] = tmp;
            i = -1;
        }
    }
}

int *split_to_int(char **res)
{
    int i = -1;
    int len = 0;
    int *tab;

    while (res[++i])
        len++;
    tab = malloc(sizeof(int) * len);
    i = -1;
    while (res[++i])
        tab[i] = my_getnbr(res[i]);
    my_sort_int_array(tab, len);
    return (tab);
}

char *write_on_file(char *str, char *score, t_render *render)
{
    char *s = my_get_map_in_str(str);
    int len = my_strlen(s, 0);
    char **res = my_split(s, "\n");
    int *tab = split_to_int(res);
    int i = -1;
    int fd = open(str, O_WRONLY);

    while (res[++i])
        ;
    if (score != NULL) {
        write(fd, score, my_strlen(score, 0));
        write(fd, "\n", 1);
    }
    close(fd);
    free(s);
    my_free_char(res);
    return (my_itoa(tab[i - 1]));
}
