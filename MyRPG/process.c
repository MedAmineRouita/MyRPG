/*
** EPITECH PROJECT, 2022
** process_for_rpg
** File description:
** process.c
*/

#include "include/my.h"

void move_player(all_t *all);

int check_position(sfVector2i m, sfFloatRect s1)
{
    if (m.x < s1.left + s1.width && m.x > s1.left &&
    m.y < s1.top + s1.height && m.y > s1.top)
        return 1;
    return 0;
}

void check_pause(sfVector2i mouse, all_t *all)
{
    if (check_position(mouse,
    sfSprite_getGlobalBounds(all->pause->menu->sprite)) == 1) {
        sfSprite_setTexture(all->pause->menu->sprite,
        all->pause->menu->texture2, sfTrue);
        if (all->clicked == 1) {
            all->status = 1;
        }
    } else
        sfSprite_setTexture(all->pause->menu->sprite,
        all->pause->menu->texture1, sfTrue);
    if (check_position(mouse,
    sfSprite_getGlobalBounds(all->pause->play->sprite)) == 1) {
        sfSprite_setTexture(all->pause->play->sprite,
        all->pause->play->texture2, sfTrue);
        if (all->clicked == 1) {
            all->status = 2;
        }
    } else
        sfSprite_setTexture(all->pause->play->sprite,
        all->pause->play->texture1, sfTrue);
}

void check_menu(sfVector2i mouse, all_t *all)
{
    if (check_position(mouse,
    sfSprite_getGlobalBounds(all->menu->play->sprite)) == 1) {
        sfSprite_setTexture(all->menu->play->sprite,
        all->menu->play->texture2, sfTrue);
        if (all->clicked == 1) {
            all->status = 2;
        }
    } else
        sfSprite_setTexture(all->menu->play->sprite,
        all->menu->play->texture1, sfTrue);
    if (check_position(mouse,
    sfSprite_getGlobalBounds(all->menu->quit->sprite)) == 1) {
        sfSprite_setTexture(all->menu->quit->sprite,
        all->menu->quit->texture2, sfTrue);
        if (all->clicked == 1) {
            sfRenderWindow_close(all->window);
        }
    } else
        sfSprite_setTexture(all->menu->quit->sprite,
        all->menu->quit->texture1, sfTrue);
}

void check_all(all_t *all)
{
    if (all->status == 1) {
        check_menu(sfMouse_getPositionRenderWindow(all->window), all);
    }
    if (all->status == 2) {
        if (all->event.key.code == sfKeyEscape &&
        all->event.type == sfEvtKeyPressed) {
            all->status = 3;
        }
        if (all->game->status == 0)
            move_player(all);

    }
    if (all->status == 3) {
        check_pause(sfMouse_getPositionRenderWindow(all->window), all);
    }
}

void process(all_t *all)
{
    while (sfRenderWindow_isOpen(all->window)) {
        while (sfRenderWindow_pollEvent(all->window, &all->event)) {
            if (all->event.type == sfEvtClosed) {
                sfRenderWindow_close(all->window);
            }
            if (all->event.type == sfEvtMouseButtonPressed) {
                all->clicked = 1;
            } else {
                all->clicked = 0;
            }
            check_all(all);
            print_all(all);
        }
    }
}
