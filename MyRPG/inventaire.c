/*
** EPITECH PROJECT, 2022
** B-MUL-200-MPL-2-1-myrpg-guillaume.lemoine
** File description:
** inventaire
*/

#include "include/my.h"

void inventaire_e(all_t *all)
{
    sfRenderWindow_drawSprite(all->window,
    all->game->inventory->sprite, NULL);
    if (my_atoi(all->game->fight->vita->str[0]) >= 120) {
        sfRenderWindow_drawSprite(all->window,
        all->game->inventory->item1, NULL);
    }
    if (my_atoi(all->game->fight->vita->str[0]) >= 140) {
        sfRenderWindow_drawSprite(all->window,
        all->game->inventory->item2, NULL);
    }
    if (my_atoi(all->game->fight->vita->str[0]) >= 200) {
        sfRenderWindow_drawSprite(all->window,
        all->game->inventory->item3, NULL);
    }
}