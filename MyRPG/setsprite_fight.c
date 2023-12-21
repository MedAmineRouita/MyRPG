/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void setspriteback(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[0], fight->rectback);
    sfSprite_setPosition(fight->sprite[0], fight->pos);
    sfSprite_setScale(fight->sprite[0], (sfVector2f) {14,14});
}

void setspritespot1(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[1], fight->spot1);
    sfSprite_setPosition(fight->sprite[1], fight->ps_spot1);
    sfSprite_setScale(fight->sprite[1], (sfVector2f) {5,5});
}

void setspritespot2(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[2], fight->spot2);
    sfSprite_setPosition(fight->sprite[2], fight->ps_spot2);
    sfSprite_setScale(fight->sprite[2], (sfVector2f) {5,5});
}

void setsacha(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[3], fight->rsacha);
    sfSprite_setPosition(fight->sprite[3], fight->ps_sacha);
    sfSprite_setScale(fight->sprite[3], (sfVector2f) {5,5});
}

void setbarrevie(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[10], fight->rbarremy);
    sfSprite_setPosition(fight->sprite[10], fight->ps_barremy);
    sfSprite_setScale(fight->sprite[10], (sfVector2f) {6,5});
    sfSprite_setTextureRect(fight->sprite[11], fight->rbarread);
    sfSprite_setPosition(fight->sprite[11], fight->ps_barread);
    sfSprite_setScale(fight->sprite[11], (sfVector2f) {6,5});
    sfSprite_setTextureRect(fight->sprite[12], fight->rblack);
    sfSprite_setPosition(fight->sprite[12], fight->ps_black1);
    sfSprite_setScale(fight->sprite[12], (sfVector2f) {0,5});
    sfSprite_setTextureRect(fight->sprite[13], fight->rblack);
    sfSprite_setPosition(fight->sprite[13], fight->ps_black2);
    fight->scale2 = (sfVector2f) {0,5};
    sfSprite_setScale(fight->sprite[12], fight->scale2);
    fight->scale1 = (sfVector2f) {0,5};
    sfSprite_setScale(fight->sprite[13], fight->scale1);
}
