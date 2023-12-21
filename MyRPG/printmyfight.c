/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void print_choixpoke(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[5], NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[6], NULL);
    for (int i = 0; i < 3; i++)
        sfRenderWindow_drawText(all->window,
        all->game->fight->pokedex->text[i], NULL);
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeyS && all->game->fight->updown < 2) {
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
            all->game->fight->status = 3;
            sfText_setString(all->game->fight->textdialo->text,
            all->game->fight->textdialo->str[all->game->fight->status]);
        }
    }
}

void status_dial(all_t *all)
{
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeySpace &&
        all->game->fight->status < 2) {
            all->game->fight->status += 1;
            sfText_setString(all->game->fight->textdialo->text,
            all->game->fight->textdialo->str[all->game->fight->status]);
        }
    }
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeySpace &&
        all->game->fight->status == 3) {
            all->game->fight->status += 1;
            sfText_setString(all->game->fight->textdialo->text,
            all->game->fight->textdialo->str[all->game->fight->status]);
        }
    }
}

void print_fight(all_t *all)
{
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[0], NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[1], NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[2], NULL);
    sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[3], NULL);
    if (my_atoi(all->game->fight->vita->str[0]) >= 120 && all->game->fight->status == 1) {
        all->game->fight->status += 1;
        sfText_setString(all->game->fight->textdialo->text, all->game->fight->textdialo->str[all->game->fight->status]);
    }
    if (all->game->fight->dial == true) {
        sfRenderWindow_drawSprite(all->window, all->game->fight->sprite[4],
        NULL);
        sfRenderWindow_drawText(all->window, all->game->fight->textdialo->text,
        NULL);
    }
    if (all->game->fight->status == 2) {
        print_choixpoke(all);
        all->game->fight->savepoke = all->game->fight->updown;
    }
    if (all->game->fight->status >= 3) {
        if (all->game->fight->pokemon != 1)
            moove_sacha(all);
        print_mypoke(all);
        printmyvita(all);
    }
    if (all->game->fight->status == 4)
        print_choixattaque(all);
    if (all->game->fight->barremax == 0 || all->game->fight->mybarre == 0)
        initvie_all(all);

    status_dial(all);
}
