/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void print_mybarre(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[10],
    NULL);
}

float degatmyattak(char *str, int z)
{
    float result = 0;
    char la[4];
    int x = 0;

    for (int i = 2; str[i] != '\0'; i++) {
        la[x] = str[i];
        x++;
    }
    la[x] = '\0';
    result = (z * my_atoi(la)) / 100;
    return result;
}
float pourcentattak(char *str1, char *str, int z)
{
    char la[4];
    float a = 0;
    int x = 0;
    float attaque = 0;
    float pourc = degatmyattak(str1, z);

    for (int i = 2; str[i] != '\0'; i++) {
        la[x] = str[i];
        x++;
    }
    la[x] = '\0';
    attaque = (pourc / my_atoi(la)) * 100;
    a = (32.5 * attaque) / 100;
    return a;
}
int who(all_t *all)
{
    if (all->game->boss == false)
        return 2;
    else
        return 4;
}
void attaque(all_t *all)
{
    int a = 0;
    float x = degatmyattak(all->game->fight->vita->str[1], 20);
    int la =  who(all);
    float z = pourcentattak(all->game->fight->vita->str[1],
    all->game->fight->vita->str[la + 1], 20);

    if (z > all->game->fight->barremax) {
        x = (all->game->fight->barremax * 100) / 32.5;
        z = all->game->fight->barremax;
    }
    if (all->game->fight->barremax >= 0 && all->game->fight->mybarre > 0) {
        a = my_atoi(all->game->fight->vita->str[la]);
        a -= x;
        all->game->fight->vita->str[la] = my_itoa(a);
        sfText_setString(all->game->fight->vita->text[la],
        all->game->fight->vita->str[la]);
        all->game->fight->ps_black2.x -= z * 10;
        all->game->fight->scale1.x += z;
        sfSprite_setPosition(all->game->fight->sprite[13],
        all->game->fight->ps_black2);
        sfSprite_setScale(all->game->fight->sprite[13],
        all->game->fight->scale1);
    }
    all->game->fight->barremax -= z;
    if (a > 0)
        adattack(all);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[13],
    NULL);
    all->game->fight->attaque += 1;
}

void adattack(all_t *all)
{
    int a = 0;
    float z = 0;
    float x = 0;

    if (all->game->boss == false) {
        z = pourcentattak(all->game->fight->vita->str[3],
        all->game->fight->vita->str[1], 15);
        x = degatmyattak(all->game->fight->vita->str[3], 15);
    }
    if (all->game->boss == true) {
        z = pourcentattak(all->game->fight->vita->str[5],
        all->game->fight->vita->str[1], 20);
        x = degatmyattak(all->game->fight->vita->str[5], 20);
    }
    if (z > all->game->fight->mybarre){
        x = (all->game->fight->mybarre * 100) / 32.5;
        z = all->game->fight->mybarre;
    }
    if (all->game->fight->mybarre >= 0) {
        a = my_atoi(all->game->fight->vita->str[0]);
        a -= x;
        all->game->fight->vita->str[0] = my_itoa(a);
        sfText_setString(all->game->fight->vita->text[0],
        all->game->fight->vita->str[0]);
        all->game->fight->ps_black1.x -= z * 10;
        all->game->fight->scale2.x += z;
        sfSprite_setPosition(all->game->fight->sprite[12],
        all->game->fight->ps_black1);
        sfSprite_setScale(all->game->fight->sprite[12],
        all->game->fight->scale2);
    }
    all->game->fight->mybarre -= z;
}
