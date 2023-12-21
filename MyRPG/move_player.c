/*
** EPITECH PROJECT, 2022
** move_for_player
** File description:
** move_player.c
*/

#include "include/my.h"
#include <math.h>

void check_dir(all_t *all)
{
    sfTime time = sfClock_getElapsedTime(all->game->player->clock);

    if (time.microseconds > 95000) {
        all->game->player->rect.left = all->game->player->rect.left + 18;
        if (all->game->player->rect.left > 43 + (54 * all->game->player->dir))
            all->game->player->rect.left = 6 + (54 * all->game->player->dir);
        sfSprite_setTextureRect(all->game->player->sprite,
        all->game->player->rect);
        sfClock_restart(all->game->player->clock);
    }
}

int cast(float f)
{
    return (int) roundf(f);
}

void check_move_3(all_t *all, sfVector2f dir, move_t *move)
{
    if (dir.y < 0) {
        if (cast(move->y * move->line) == 13 && (cast(move->dx * move->col)
        == 3 || cast(move->dx * move->col) == 4)) {
            all->game->status = 1;
            all->game->boss = false;
        }
        if (cast(move->y * move->line) == 31 && (cast(move->dx * move->col)
        == 114 || cast(move->dx * move->col) == 115)) {
            all->game->status = 1;
            all->game->boss = true;
        }
        if (move->dy > 0 && all->game->map->map[cast(move->dy * move->line)]
        [cast(move->x * move->col)] == '0') {
            sfSprite_move(all->game->player->sprite, dir);
            all->game->player->pos.y += dir.y;
        }
    }
}

void check_move_2(all_t *all, sfVector2f dir, move_t *move)
{
    move->dx += dir.x;
    move->dy += dir.y;
    if (dir.x < 0)
        if (move->dx > 0 && all->game->map->map[cast(move->y * move->line)]
        [cast(move->dx * move->col)] == '0') {
            sfSprite_move(all->game->player->sprite, dir);
            all->game->player->pos.x += dir.x;
        }
    if (dir.x > 0)
        if (move->dx < 1920 && all->game->map->map[cast(move->y * move->line)]
        [cast(move->dx * move->col)] == '0') {
            sfSprite_move(all->game->player->sprite, dir);
            all->game->player->pos.x += dir.x;
        }
    if (dir.y > 0)
        if (move->dy < 1080 && all->game->map->map[cast(move->dy *
        move->line)][cast(move->x * move->col)] == '0') {
            sfSprite_move(all->game->player->sprite, dir);
            all->game->player->pos.y += dir.y;
        }
    check_move_3(all, dir, move);
}

void check_inv(all_t *all)
{
    if (all->event.key.code == sfKeyE) {
        if (all->game->boll_inv == 1)
            all->game->boll_inv = 0;
        else
            all->game->boll_inv = 1;
    }
}

void check_move(all_t *all, move_t *move)
{
    if (all->event.type == sfEvtKeyPressed) {
        if (all->event.key.code == sfKeyZ) {
            check_move_2(all, (sfVector2f) {0, -10}, move);
            all->game->player->dir = 2;
            if (all->game->player->rect.left < 96 || all->game->player->rect.left > 132)
            all->game->player->rect.left = 96;
        }
        if (all->event.key.code == sfKeyD) {
            check_move_2(all, (sfVector2f) {10, 0}, move);
            all->game->player->dir = 3;
            if (all->game->player->rect.left < 150 || all->game->player->rect.left > 186)
                all->game->player->rect.left = 150;
        }
        if (all->event.key.code == sfKeyS) {
            check_move_2(all, (sfVector2f) {0, 10}, move);
            all->game->player->dir = 0;
        }
        if (all->event.key.code == sfKeyQ) {
            check_move_2(all, (sfVector2f) {-10, 0}, move);
            all->game->player->dir = 1;
            if (all->game->player->rect.left < 60 || all->game->player->rect.left > 96)
                all->game->player->rect.left = 60;
        }
        check_inv(all);
        check_dir(all);
    }
}

void move_player(all_t *all)
{
    move_t move = {.line = 68.f / 1080.f, .col = 120.f / 1920.f,
    .dx = all->game->player->pos.x,
    .dy = all->game->player->pos.y,
    .x = all->game->player->pos.x, .y = all->game->player->pos.y};

    check_move(all, &move);
}
