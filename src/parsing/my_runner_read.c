/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** my_runner_read.c
*/

#include "../../include/my.h"

int my_calc_buff_size(char *str)
{
    int fd = open(str, O_RDONLY);
    int i = 0;
    char buff[2048];
    int sd = 1;

    buff[2047] = '\0';
    if (fd < 0)
        return (-1);
    while (sd > 0) {
        sd = read(fd, buff, 2048);
        if (sd < 0)
            return (0);
        i += sd;
    }
    close(fd);
    return (i);
}

char *my_get_map_in_str(char *str)
{
    int fd;
    int len = my_calc_buff_size(str);
    char *res;
    int s = 0;

    if (!str)
        return (NULL);
    s++;
    if (len == -1)
        return (0);
    res = malloc(sizeof(char) * (len + 1));
    fd = open(str, O_RDONLY);
    if (!res || !fd)
        return (NULL);
    s--;
    s = read(fd, res, len);
    res[len] = '\0';
    close(fd);
    return (res);
}

int get_coin_nb(char *s)
{
    int i = -1;
    int count = 0;

    while (s[++i])
        if (s[i] == 'c')
            count++;
    return (count);
}
