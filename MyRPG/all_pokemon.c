/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void text_poke(poke_t *pokedex)
{
    char **str = NULL;
    int z = 6;

    str = malloc(sizeof(char *) * z);
    for (int i = 0; i < z; i++)
        str[i] = malloc(sizeof(char) * 700);
    str[0] = "Dracaufeu";
    str[1] = "Florizarre";
    str[2] = "Tortank";
    str[3] = "Attaquer";
    str[4] = "Soigner";
    str[z - 1] = NULL;
    pokedex->str = str;
}
sfText **init_text(void)
{
    sfText **text = malloc(sizeof(sfText *) * 5);
    text[0] = sfText_create();
    text[1] = sfText_create();
    text[2] = sfText_create();
    text[3] = sfText_create();
    text[4] = sfText_create();
    return text;
}

poke_t *init_pokemon(void)
{
    poke_t *pokedex = malloc(sizeof(poke_t));
    int z = 0;
    text_poke(pokedex);
    pokedex->text = init_text();
    pokedex->font_text = sfFont_createFromFile("sprite/fight/poke.ttf");
    for (int i = 0; i < 3; i++) {
        sfText_setCharacterSize(pokedex->text[i], 15);
        sfText_setString(pokedex->text[i], pokedex->str[i]);
        sfText_setFont(pokedex->text[i], pokedex->font_text);
        sfText_setColor(pokedex->text[i], sfBlack);
        sfText_setPosition(pokedex->text[i], ((sfVector2f){1190, 850 + z}));
        z += 40;
    }
    z = 0;
    for (int i = 3; i < 5; i++) {
        sfText_setCharacterSize(pokedex->text[i], 15);
        sfText_setString(pokedex->text[i], pokedex->str[i]);
        sfText_setFont(pokedex->text[i], pokedex->font_text);
        sfText_setColor(pokedex->text[i], sfBlack);
        sfText_setPosition(pokedex->text[i], ((sfVector2f){1190, 850 + z}));
        z += 40;
    }
    return pokedex;
}
