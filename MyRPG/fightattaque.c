/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void print_choixattaque(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[5], NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[6], NULL);
    for (int i = 3; i < 5; i++)
        sfRenderWindow_drawText(all->window,
        all->game->fight->pokedex->text[i], NULL);
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeyS && all->game->fight->updown < 1) {
            all->game->fight->ps_fleche.y += 40;
            all->game->fight->updown += 1;
            sfSprite_setPosition(all->game->fight->sprite[6],
            all->game->fight->ps_fleche);
        }
        if (all->event.key.code == sfKeyZ && all->game->fight->updown > 0) {
            all->game->fight->ps_fleche.y -= 40;
            all->game->fight->updown -= 1;
            sfSprite_setPosition(all->game->fight->sprite[6],
            all->game->fight->ps_fleche);
        }
        if (all->event.key.code == sfKeyEnter) {
            attaque(all);
        }
    }
}
void initvie_all(all_t *all)
{
    if (all->game->fight->barremax == 0 && all->game->boss == false)
        all->game->fight->status = 6;
    if (all->game->fight->barremax == 0 && all->game->boss == true)
        all->game->fight->status = 5;
    if (all->game->fight->mybarre == 0 && all->game->boss == true)
        all->game->fight->status = 7;
    sfText_setString(all->game->fight->textdialo->text,
    all->game->fight->textdialo->str[all->game->fight->status]);
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeySpace)
            initaprescbt(all);
    }
}

void initaprescbt(all_t *all)
{
    sfSprite_getPosition(all->game->player->sprite);
    if (all->game->fight->mybarre == 0 && all->game->boss == true) {
        all->game->fight = init_fight();
        all->game->temp = 1;

    }
    if (all->game->fight->barremax == 0 && all->game->boss == false) {
        vita_up(all);
        all->game->temp = 1;
        all->game->fight = init_fight();
    }
    if (all->game->temp == 1) {
        all->game->fight->vita->str[0] = all->game->savevie;
        sfText_setString(all->game->fight->vita->text[0],
        all->game->fight->vita->str[0]);
        all->game->fight->vita->str[1] = all->game->savevie1;
        sfText_setString(all->game->fight->vita->text[1],
        all->game->fight->vita->str[1]);
        all->game->temp = 0;
    }

    all->game->status = 0;
}
