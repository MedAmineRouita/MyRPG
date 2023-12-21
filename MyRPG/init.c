/*
** EPITECH PROJECT, 2022
** init_for_rpg
** File description:
** init.c
*/

#include "include/my.h"

inventory_t *init_inventory(void);
map_t *init_map(void);
player_t *init_player(void);

button_t *init_button(char *path1, char *path2, sfVector2f pos)
{
    button_t *button = malloc(sizeof(button_t));

    button->sprite = sfSprite_create();
    button->texture1 = sfTexture_createFromFile(path1, NULL);
    button->texture2 = sfTexture_createFromFile(path2, NULL);
    sfSprite_setTexture(button->sprite, button->texture1, sfTrue);
    button->status = 1;
    button->size = sfSprite_getGlobalBounds(button->sprite);
    sfSprite_setPosition(button->sprite, pos);
    button->pos = pos;
    return button;
}

menu_t *init_menu(void)
{
    menu_t *menu = malloc(sizeof(menu_t));
    sfTexture *texture = sfTexture_createFromFile("sprite/background", NULL);

    menu->play = init_button("sprite/button/play2.png",
    "sprite/button/play1.png", (sfVector2f) {250, 150});
    menu->quit = init_button("sprite/button/quit2.png",
    "sprite/button/quit1.png", (sfVector2f) {250, 550});
    menu->background = sfSprite_create();
    sfSprite_setTexture(menu->background, texture, sfTrue);
    return menu;

}

game_t *init_game(void)
{
    game_t *game = malloc(sizeof(game_t));

    game->player = init_player();
    game->inventory = init_inventory();
    game->map = init_map();
    game->fight = init_fight();
    game->status = 0;
    game->boll_inv = 0;
    return game;
}

pause_t *init_pause(void)
{
    pause_t *pause = malloc(sizeof(pause_t));
    sfTexture *texture = sfTexture_createFromFile("sprite/background", NULL);

    pause->menu = init_button("sprite/button/menu2.png",
    "sprite/button/menu1.png", (sfVector2f) {250, 150});
    pause->play = init_button("sprite/button/play2.png",
    "sprite/button/play1.png", (sfVector2f) {250, 550});
    pause->background = sfSprite_create();
    sfSprite_setTexture(pause->background, texture, sfTrue);
    return pause;

}

all_t *init_all(void)
{
    all_t *all = malloc(sizeof(all_t));
    sfVideoMode mode = {1920, 1080, 32};

    all->menu = init_menu();
    all->game = init_game();
    all->pause = init_pause();
    all->status = 1;
    all->window = sfRenderWindow_create(mode, "my_rpg", sfClose | sfResize,
    NULL);
    all->clock = sfClock_create();
    all->delta_time = 0;
    all->clicked = 0;
    sfRenderWindow_setFramerateLimit(all->window, 60);
    return all;
}
