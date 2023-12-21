/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

void text_vita(vita_t *vita)
{
    char **str = NULL;
    int z = 7;

    str = malloc(sizeof(char *) * z);
    for (int i = 0; i < z; i++)
        str[i] = malloc(sizeof(char) * 700);
    str[0] = "100";
    str[1] = "/ 100";
    str[2] = "100";
    str[3] = "/ 100";
    str[4] = "200";
    str[5] = "/ 200";
    str[z - 1] = NULL;
    vita->str = str;
}
sfText **init_textv(void)
{
    sfText **text = malloc(sizeof(sfText *) * 6);
    text[0] = sfText_create();
    text[1] = sfText_create();
    text[2] = sfText_create();
    text[3] = sfText_create();
    text[4] = sfText_create();
    text[5] = sfText_create();
    return text;
}

vita_t *init_vita(void)
{
    vita_t *vita = malloc(sizeof(vita_t));
    int z = 0;
    text_vita(vita);
    vita->text = init_textv();
    vita->font_text = sfFont_createFromFile("sprite/fight/poke.ttf");
    for (int i = 0; i < 2; i++) {
        sfText_setCharacterSize(vita->text[i], 15);
        sfText_setString(vita->text[i], vita->str[i]);
        sfText_setFont(vita->text[i], vita->font_text);
        sfText_setColor(vita->text[i], sfBlack);
        sfText_setPosition(vita->text[i], ((sfVector2f){1200 + z, 600}));
        z += 50;
    }
    z = 0;
    for (int i = 2; i < 6; i++) {
        sfText_setCharacterSize(vita->text[i], 15);
        sfText_setString(vita->text[i], vita->str[i]);
        sfText_setFont(vita->text[i], vita->font_text);
        sfText_setColor(vita->text[i], sfBlack);
        sfText_setPosition(vita->text[i], ((sfVector2f){195 + z, 142}));
        z += 50;
        if (z == 100)
            z = 0;
    }
    return vita;
}
