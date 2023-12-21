/*
** EPITECH PROJECT, 2022
** B-CPE-200-MPL-2-1-lemin-guillaume.lemoine
** File description:
** my_atoi
*/

#include "include/my.h"

int my_atoi(char *str)
{
    int res = 0;
    int i = 0;
    int sign = 1;

    if (str[0] == '-') {
        sign *= -1;
        i += 1;
    }
    while (str[i] != '\0') {
        res *= 10;
        res += str[i] - '0';
        i++;
    }
    return (res * sign);
}
