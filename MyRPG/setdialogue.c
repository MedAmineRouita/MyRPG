/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void setdialo(fight_t *fight)
{
    sfSprite_setTextureRect(fight->sprite[4], fight->rdialo);
    sfSprite_setPosition(fight->sprite[4], fight->ps_dialo);
    sfSprite_setScale(fight->sprite[4], (sfVector2f) {7.7,5});
}

void text_nb(dialo_t *textdialo)
{
    char **str = NULL;
    int z = 9;

    str = malloc(sizeof(char *) * z);
    for (int i = 0; i < z; i++)
        str[i] = malloc(sizeof(char) * 700);
    str[0] = "Appuie sur la touche Espace pour continuer..";
    str[1] = "Bienvenue a toi Sacha,\n\nTu es finalement arrive a ton \
premier combat Choisis le Pokemon avec lequel tu veux commencer \
ton combat.";
    str[2] = "Choisi ton Pokemon a l'aide des touches :\n                    \
z et s\nPuis appuie sur la touche Entrer pour pouvoir valider ton choix.";
    str[3] = "Tu es enfin pret a combatre.. \nAppuie sur la touche Espace \
pour continuer.";
    str[4] = "Choisi ton attaque. Puis appuie sur Entrer";
    str[5] = "Felicitation tu as fini par vaincre Lucas te voila arriver a la\
    fin du jeu.\nAppuie sur Espace.";
    str[6] = "Felicitation tu as fini par vaincre Leo.\nUn petit conseil \
entraine toi encore avant de faire face a Lucas.\nAppuie sur Espace.";
    str[7] = "Helas tu as manque d'experience, mais rien n'est perdu, \
continue de t'entrainer et reviens une fois plus fort.\nAppuie sur Espace.";

    str[z - 1] = NULL;
    textdialo->str = str;
}

dialo_t *init_dialo(fight_t *fight)
{
    dialo_t *textdialo = malloc(sizeof(dialo_t));
    text_nb(textdialo);
    textdialo->text = sfText_create();
    textdialo->font_text = sfFont_createFromFile("sprite/fight/poke.ttf");
    sfText_setCharacterSize(textdialo->text, 15);
    sfText_setString(textdialo->text, textdialo->str[fight->status]);
    sfText_setFont(textdialo->text, textdialo->font_text);
    sfText_setColor(textdialo->text, sfWhite);
    sfText_setPosition(textdialo->text, ((sfVector2f){70, 830}));
    return textdialo;
}
