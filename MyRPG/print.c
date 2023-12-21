/*
** EPITECH PROJECT, 2022
** print_for_my_rpg
** File description:
** print.c
*/

#include "include/my.h"

void print_game(all_t *all)
{
    if (all->game->status == 0) {
        sfRenderWindow_drawSprite(all->window, all->game->map->backmap, NULL);
        sfRenderWindow_drawSprite(all->window,
        all->game->player->sprite, NULL);
        sfRenderWindow_drawSprite(all->window, all->game->map->frontmap, NULL);
        if (all->game->boll_inv == 1)
            inventaire_e(all);
    } else {
        print_fight(all);
    }
}

void print_pause(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->pause->background, NULL);
    sfRenderWindow_drawSprite(all->window, all->pause->play->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->pause->menu->sprite, NULL);
}

void print_menu(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->menu->background, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->play->sprite, NULL);
    sfRenderWindow_drawSprite(all->window, all->menu->quit->sprite, NULL);
}

void print_all(all_t *all)
{
    sfRenderWindow_clear(all->window, sfWhite);
    if (all->status == 1)
        print_menu(all);
    if (all->status == 2)
        print_game(all);
    if (all->status == 3)
        print_pause(all);
    sfRenderWindow_display(all->window);
}
