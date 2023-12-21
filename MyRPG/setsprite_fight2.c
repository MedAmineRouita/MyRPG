/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void choise_poke(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[5], fight->rchoise);
    sfSprite_setPosition(fight->sprite[5], fight->ps_choise);
    sfSprite_setScale(fight->sprite[5], (sfVector2f) {5,4.8});
    sfSprite_setTextureRect(fight->sprite[6], fight->rfleche);
    sfSprite_setPosition(fight->sprite[6], fight->ps_fleche);
    sfSprite_setScale(fight->sprite[6], (sfVector2f) {3, 3});
    setmypoke(fight);
}
void setmypoke(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[7], fight->rdracau);
    sfSprite_setPosition(fight->sprite[7], fight->ps_dracau);
    sfSprite_setScale(fight->sprite[7], (sfVector2f) {5,5});
    sfSprite_setTextureRect(fight->sprite[8], fight->rflori);
    sfSprite_setPosition(fight->sprite[8], fight->ps_dracau);
    sfSprite_setScale(fight->sprite[8], (sfVector2f) {5,5});
    sfSprite_setTextureRect(fight->sprite[9], fight->rtortank);
    sfSprite_setPosition(fight->sprite[9], fight->ps_dracau);
    sfSprite_setScale(fight->sprite[9], (sfVector2f) {5,5});
}

void setpokemonad(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[14], fight->rleo);
    sfSprite_setPosition(fight->sprite[14], fight->ps_leo);
    sfSprite_setScale(fight->sprite[14], (sfVector2f) {5,5});
    sfSprite_setTextureRect(fight->sprite[15], fight->rlucas);
    sfSprite_setPosition(fight->sprite[15], fight->ps_leo);
    sfSprite_setScale(fight->sprite[15], (sfVector2f) {5,5});
}

void set_fullcbt(fight_t *fight)
{
    setspriteback(fight);
    setspritespot1(fight);
    setspritespot2(fight);
    setsacha(fight);
    setdialo(fight);
    choise_poke(fight);
    setbarrevie(fight);
    setpokemonad(fight);
}
