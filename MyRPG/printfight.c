/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void check_sacha(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->game->fight->clock);

    if (time.microseconds > 1000000) {

            sfClock_restart(all->game->fight->clock);
        }
}
void moove_sacha(all_t *all)
{
    all->game->fight->pokemon = 1;
    for (int i = 1000; i != 42; i++) {
        i -= 2;
        check_sacha(all);
        if (all->game->fight->ps_sacha.x > 40)
            sfSprite_move(all->game->fight->sprite[3],
            (sfVector2f) {-0.1, 0});
        else
            break;
    }

}
void print_mypoke(all_t *all)
{
    if (all->game->fight->savepoke == 0) {
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[7],
        NULL);
    }
    else if (all->game->fight->savepoke == 1)
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[8],
        NULL);
    else if (all->game->fight->savepoke == 2)
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[9],
        NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[10],
    NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[11],
    NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[12],
    NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[13],
    NULL);
    printpokead(all);
}

void printmyvita(all_t *all)
{
    sfRenderWindow_drawText(all->window, all->game->fight->vita->text[0],
    NULL);
    sfRenderWindow_drawText(all->window, all->game->fight->vita->text[1],
    NULL);
    if (all->game->boss == false) {
        sfRenderWindow_drawText(all->window, all->game->fight->vita->text[2],
        NULL);
        sfRenderWindow_drawText(all->window, all->game->fight->vita->text[3],
        NULL);
    }
    if (all->game->boss == true) {
        sfRenderWindow_drawText(all->window, all->game->fight->vita->text[4],
        NULL);
        sfRenderWindow_drawText(all->window, all->game->fight->vita->text[5],
        NULL);
    }
}

void printpokead(all_t *all)
{
    if (all->game->boss == false) {
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[14],
        NULL);
    }
    if (all->game->boss == true) {
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[15],
        NULL);
    }
}
