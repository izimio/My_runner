/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** project_csfml_basic_utils_2.c
*/

#include "../include/my.h"

int my_strcmp(char *s1, char *s2)
{
    int i = 0;

    while (s1[i] == s2[i] && s1[i] && s2[i])
        i++;
    return (s1[i] - s2[i]);
}

char *my_strdup(char *src)
{
    int i = 0;
    char *cpy;

    i = 0;
    if (!(cpy = malloc(sizeof(char) * my_strlen(src, 0) + 1)))
        return (NULL);
    while (src[i]) {
        cpy[i] = src[i];
        i++;
    }
    cpy[i] = '\0';
    return (cpy);
}

char *my_strcat(char *dest, char *src)
{
    int i = 0;
    int j = 0;

    while (dest[i])
        i++;
    while (src[j])
        dest[i++] = src[j++];
    dest[i] = '\0';
    return (dest);
}
