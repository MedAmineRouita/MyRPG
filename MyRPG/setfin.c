/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void vita_up(all_t *all)
{
    char la[4];
    int a = 0;
    char *temp = malloc(sizeof(char) * 100);
    int x = 0;
    int z = 2;

    for (int i = 2; all->game->fight->vita->str[1][i] != '\0'; i++) {
        la[x] = all->game->fight->vita->str[1][i];
        x++;
    }
    la[x] = '\0';
    a = my_atoi(la) + 20;
    all->game->savevie = my_itoa(a);
    temp[0] = '/';
    temp[1] = ' ';
    for (int i = 0; all->game->savevie[i] != '\0'; i++) {
        temp[z] = all->game->savevie[i];
        z++;
    }
    temp[z] = '\0';
    all->game->savevie1 = temp;
}