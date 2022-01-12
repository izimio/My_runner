/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_strjoin.c
*/

#include "../../include/my.h"

int cacl_db_size(char **res)
{
    int i = 0;

    while (res[i])
        i++;
    return (i);
}

char *my_strjoin(int size, char **strs, char *sep)
{
    char *tab;
    int n = 0;
    int a = 0;
    int b = 0;
    int count = 1;

    while (a < size)
        count += my_strlen(strs[a++], 0) + my_strlen(sep, 0), 0;
    tab = malloc(sizeof(char *) * count);
    a = -1;
    while (++a < size) {
        while (strs[a][b])
            tab[n++] = strs[a][b++];
        b = 0;
        while (sep[b] && a < size - 1)
            tab[n++] = sep[b++];
        b = 0;
    }
    tab[n] = '\0';
    return (tab);
}
