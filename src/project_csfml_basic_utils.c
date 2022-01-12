/*
** EPITECH PROJECT, 2021
** project_template
** File description:
** project_csfml_basic_utils.c
*/

#include "../include/my.h"

int my_strlen(char *s, int flag)
{
    int i = 0;

    if (!s)
        return (0);
    while (s[i]) {
        if (s[i] == 'w' && flag)
            return (i);
        i++;
    }
    return (i);
}

void my_putstr(char *str)
{
    int i = -1;

    while (str[++i])
        write(1, &str[i], 1);
}

int count_int_len(int nb)
{
    long nbr = nb;
    int i = 0;

    if (nbr <= 0) {
        i++;
        nbr = -nbr;
    }
    while (nbr > 0) {
        i++;
        nbr = nbr / 10;
    }
    return (i);
}

char *my_itoa(int n)
{
    long nbr = n;
    int i = count_int_len(n);
    char *toa;

    toa = malloc(sizeof(char) * i + 1);
    toa[i] = '\0';
    if (!toa)
        return (NULL);
    toa[0] = '0';
    if (n == 0)
        return (toa);
    if (nbr < 0) {
        toa[0] = '-';
        nbr = -nbr;
    }
    while (nbr > 0) {
        toa[--i] = nbr % 10 + '0';
        nbr /= 10;
    }
    return (toa);
}

int my_getnbr(char *str)
{
    long res = 0;
    int sign = 1;
    int i = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
        i++;
    if (str[i] == '+' || str[i] == '-') {
        if (str[i] == '-')
            sign *= -1;
        i++;
    }
    while (str[i] >= '0' && str[i] <= '9') {
        res = res * 10 + (str[i] - 48);
        i++;
        if (res > 2147483648 || (res == 2147483648 && sign == 1))
            return (0);
    }
    return (res * sign);
}
