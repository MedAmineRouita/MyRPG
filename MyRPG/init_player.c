/*
** EPITECH PROJECT, 2022
** init_player_for_rpg
** File description:
** init_player.c
*/

#include "include/my.h"

inventory_t *init_inventory(void)
{
    inventory_t *inventory = malloc(sizeof(inventory_t));
    sfTexture *texture = sfTexture_createFromFile("sprite/inventory.png",
    NULL);
    sfTexture *item1_texture = sfTexture_createFromFile(
    "sprite/items/vie.png", NULL);
    sfTexture *item2_texture = sfTexture_createFromFile(
    "sprite/items/potion.png", NULL);
    sfTexture *item3_texture = sfTexture_createFromFile(
    "sprite/items/epée.png", NULL);

    inventory->item1 = sfSprite_create();
    inventory->item2 = sfSprite_create();
    inventory->item3 = sfSprite_create();
    inventory->sprite = sfSprite_create();
    sfSprite_setTexture(inventory->sprite, texture, sfTrue);
    sfSprite_setTexture(inventory->item1, item1_texture, sfTrue);
    sfSprite_setTexture(inventory->item2, item2_texture, sfTrue);
    sfSprite_setTexture(inventory->item3, item3_texture, sfTrue);
    sfSprite_setPosition(inventory->sprite, (sfVector2f) {30, 30});
    sfSprite_setPosition(inventory->item1, (sfVector2f) {350, 450});
    sfSprite_setPosition(inventory->item2, (sfVector2f) {490, 450});
    sfSprite_setPosition(inventory->item3, (sfVector2f) {620, 450});

    return inventory;
}

char **setup_array()
{
    char *map = NULL;
    int fd = open("./sprite/map/map.txt", O_RDONLY);
    struct stat sb;

    if (stat("./sprite/map/map.txt", &sb) == -1)
        return NULL;
    map = malloc(sizeof(char) * (sb.st_size + 1));
    if (read(fd, map, sb.st_size) == -1)
        return NULL;
    map[sb.st_size] = 0;
    return my_str_to_word_array(map);
}

map_t *init_map(void)
{
    map_t *map = malloc(sizeof(map_t));
    sfTexture *back = sfTexture_createFromFile("sprite/map/map.png", NULL);
    sfTexture *front = sfTexture_createFromFile("sprite/map/1plan.png", NULL);

    map->backmap = sfSprite_create();
    map->frontmap = sfSprite_create();
    map->map = setup_array();
    sfSprite_setTexture(map->backmap, back, sfTrue);
    sfSprite_setTexture(map->frontmap, front, sfTrue);
    return map;
}

player_t *init_player(void)
{
    player_t *player = malloc(sizeof(player_t));

    player->sprite = sfSprite_create();
    player->texture1 = sfTexture_createFromFile("sprite/player/chara.png",
    NULL);
    player->pos = (sfVector2f) {410, 900};
    player->rect = (sfIntRect) {6, 9, 16, 27};
    player->dir = 3;
    player->clock = sfClock_create();
    sfSprite_setTexture(player->sprite, player->texture1, sfTrue);
    sfSprite_setTextureRect(player->sprite, player->rect);
    sfSprite_setPosition(player->sprite, player->pos);
    sfSprite_setScale(player->sprite, (sfVector2f) {2,2});
    return player;
}
