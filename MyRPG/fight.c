/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

sfTexture **creat_texturefight(fight_t *fight)
{
    sfTexture **texture = malloc(sizeof(sfTexture *) * fight->nb_sprite);
    texture[0] = sfTexture_createFromFile("sprite/fight/all.png", NULL);
    texture[1] = sfTexture_createFromFile("sprite/fight/all.png", NULL);
    texture[2] = sfTexture_createFromFile("sprite/fight/all.png", NULL);
    texture[3] = sfTexture_createFromFile("sprite/fight/chara.png", NULL);
    texture[4] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[5] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[6] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[7] = sfTexture_createFromFile("sprite/fight/pokebac.png", NULL);
    texture[8] = sfTexture_createFromFile("sprite/fight/pokebac.png", NULL);
    texture[9] = sfTexture_createFromFile("sprite/fight/pokebac.png", NULL);
    texture[10] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[11] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[12] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[13] = sfTexture_createFromFile("sprite/fight/dialo.png", NULL);
    texture[14] = sfTexture_createFromFile("sprite/fight/gold.png", NULL);
    texture[15] = sfTexture_createFromFile("sprite/fight/gold.png", NULL);

    return texture;
}
void creat_rect(fight_t *fight)
{
    fight->rectback = (sfIntRect) {15, 566, 257, 150};
    fight->spot1 = (sfIntRect) {904, 143, 162, 17};
    fight->spot2 = (sfIntRect) {1034, 91, 125, 30};
    fight->rsacha = (sfIntRect) {339, 85, 52, 60};
    fight->rdialo = (sfIntRect) {296, 56, 241, 48};
    fight->rchoise = (sfIntRect) {296, 3, 161, 49};
    fight->rfleche = (sfIntRect) {268, 3, 7, 11};
    fight->rdracau = (sfIntRect) {(48 * 5), 3, 48, 48};
    fight->rflori = (sfIntRect) {(48 * 2), 0, 48, 48};
    fight->rtortank = (sfIntRect) {(48 * 8), 0, 48, 48};
    fight->rbarremy = (sfIntRect) {2, 43, 105, 38};
    fight->rbarread = (sfIntRect) {2, 2, 101, 30};
    fight->rblack = (sfIntRect) {116, 20, 10, 4};
    fight->rleo = (sfIntRect) {(56 * 12), 0, 56, 56};
    fight->rlucas = (sfIntRect) {(56 * 8), (12 * 56), 56, 56};
}
void creat_pos(fight_t *fight)
{
    fight->pos = (sfVector2f) {0, 0};
    fight->ps_spot1 = (sfVector2f) {-4, 700};
    fight->ps_spot2 = (sfVector2f) {1150, 200};
    fight->ps_sacha = (sfVector2f) {150, 486};
    fight->ps_dialo = (sfVector2f) {-8, 785};
    fight->ps_choise = (sfVector2f) {1040, 785};
    fight->ps_fleche = (sfVector2f) {1090, 850};
    fight->ps_dracau = (sfVector2f) {350, 557};
    fight->ps_barremy = (sfVector2f) {1100, 557};
    fight->ps_barread = (sfVector2f) {150, 100};
    fight->ps_black1 = (sfVector2f) {1360 + (32.5 * 10), 642};
    fight->ps_black2 = (sfVector2f) {(355 + (32.5 * 10)), 184};
    fight->ps_leo = (sfVector2f) {1350, 57};
}
sfSprite **init_sprite(int z)
{
    sfSprite **sprite = malloc(sizeof(sfSprite *) * z);
    for (int i = 0; i < z; i++)
        sprite[i] = sfSprite_create();
    return sprite;
}

fight_t *init_fight(void)
{
    fight_t *fight = malloc(sizeof(fight_t));
    fight->attaque = 0;
    fight->status = 0;
    fight->mybarre = 32.5;
    fight->barremax = 32.5;
    fight->clock = sfClock_create();
    fight->updown = 0;
    fight->pokemon = 0;
    fight->dial = true;
    fight->textdialo = init_dialo(fight);
    fight->pokedex = init_pokemon();
    fight->vita = init_vita();
    fight->nb_sprite = 16;
    creat_rect(fight);
    creat_pos(fight);
    fight->sprite = init_sprite(fight->nb_sprite);
    fight->texture = creat_texturefight(fight);
    for (int i = 0; i < fight->nb_sprite; i++)
        sfSprite_setTexture(fight->sprite[i], fight->texture[i], sfTrue);
    set_fullcbt(fight);
    return fight;
}
