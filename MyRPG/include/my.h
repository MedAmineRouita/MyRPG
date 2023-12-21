/*
** EPITECH PROJECT, 2022
** include_for_rpg
** File description:
** my.h
*/

#ifndef _My_H_
    #define _My_H_
    #include <stdio.h>
    #include <time.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <SFML/System/Export.h>
    #include <SFML/System/Time.h>
    #include <SFML/System/Types.h>
    #include <stdlib.h>
    #include <string.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <sys/types.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #define UNUSED() __attribute__((unused))

typedef struct dialo_s {
    char **str;
    sfFont *font_text;
    sfText *text;
}dialo_t;

typedef struct poke_s {
    char **str;
    sfFont *font_text;
    sfText **text;
    sfSprite **sprite;
    sfTexture **texture;
    sfVector2f ps_poke;
    sfIntRect rpoke;
}poke_t;

typedef struct vita_s {
    char **str;
    sfFont *font_text;
    sfText **text;
}vita_t;

typedef struct fight_s {
    sfSprite **sprite;
    sfTexture **texture;
    dialo_t *textdialo;
    vita_t *vita;
    poke_t *pokedex;
    int pdv;
    int full;
    float barremax;
    float mybarre;
    float pourcent;
    int status;
    int savepoke;
    int attaque;
    int updown;
    bool dial;
    int pourc;
    int nb_sprite;
    bool sort;
    sfVector2f pos;
    sfVector2f ps_spot1;
    sfVector2f ps_spot2;
    sfVector2f ps_sacha;
    sfVector2f ps_dialo;
    sfVector2f ps_choise;
    sfVector2f ps_fleche;
    sfVector2f ps_dracau;
    sfVector2f ps_tortank;
    sfVector2f ps_flori;
    sfVector2f ps_barremy;
    sfVector2f ps_barread;
    sfVector2f ps_black1;
    sfVector2f ps_black2;
    sfVector2f ps_leo;
    sfVector2f scale1;
    sfVector2f scale2;
    sfIntRect rectback;
    sfIntRect spot1;
    sfIntRect spot2;
    sfIntRect rsacha;
    sfIntRect rdialo;
    sfIntRect rchoise;
    sfIntRect rfleche;
    sfIntRect rdracau;
    sfIntRect rflori;
    sfIntRect rtortank;
    sfIntRect rbarremy;
    sfIntRect rbarread;
    sfIntRect rblack;
    sfIntRect rlucas;
    sfIntRect rleo;
    sfClock *clock;
    int pokemon;
}fight_t;

typedef struct player_s {
    sfSprite *sprite;
    sfTexture *texture1;
    sfVector2f pos;
    sfIntRect rect;
    sfClock *clock;
    int dir;
}player_t;

typedef struct map_s {
    sfSprite *backmap;
    sfSprite *frontmap;
    char **map;
}map_t;

typedef struct inventory_s {
    sfSprite *sprite;
    sfSprite *item1;
    sfSprite *item2;
    sfSprite *item3;
}inventory_t;

typedef struct game_s {
    map_t *map;
    player_t *player;
    int status;
    bool boss;
    fight_t *fight;
    inventory_t *inventory;
    int boll_inv;
    char *savevie;
    char *savevie1;
    int temp;
    int item;
}game_t;

typedef struct button_s {
    sfSprite *sprite;
    sfTexture *texture1;
    sfTexture *texture2;
    int status;
    sfFloatRect size;
    sfVector2f pos;
}button_t;

typedef struct menu_s {
    button_t *play;
    button_t *quit;
    sfSprite *background;
}menu_t;

typedef struct pause_s {
    button_t *play;
    button_t *menu;
    sfSprite *background;
}pause_t;

typedef struct all_s {
    menu_t *menu;
    game_t *game;
    pause_t *pause;
    int status;
    sfRenderWindow *window;
    sfEvent event;
    sfClock *clock;
    float delta_time;
    int clicked;
}all_t;

typedef struct move_s {
    float line;
    float col;
    float dx;
    float dy;
    float x;
    float y;
} move_t;

all_t *init_all(void);
char *my_strcat(char *dest, char const *src);
int my_strcmp(char const *s1, char const *s2);
char *my_strcpy(char *dest, char const *src);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char *my_strdup(char const *src);
int my_strlen(char const *str);
char **my_str_to_word_array(char *str);
player_t *init_player(void);
void print_all(all_t *all);
void process(all_t *all);
void text_poke(poke_t *pokedex);
sfText **init_text(void);
poke_t *init_pokemon(void);
void text_poke(poke_t *pokedex);
sfText **init_text(void);
poke_t *init_pokemon(void);
sfTexture **creat_texturefight(fight_t *fight);
void creat_rect(fight_t *fight);
void creat_pos(fight_t *fight);
sfSprite **init_sprite(int z);
fight_t *init_fight(void);
void print_choixattaque(all_t *all);
void check_sacha(all_t *all);
void moove_sacha(all_t *all);
void print_mypoke(all_t *all);
void print_choixpoke(all_t *all);
void status_dial(all_t *all);
void print_fight(all_t *all);
void setdialo(fight_t *fight);
void text_nb(dialo_t *textdialo);
dialo_t *init_dialo(fight_t *fight);
void setspriteback(fight_t *fight);
void setspritespot1(fight_t *fight);
void setspritespot2(fight_t *fight);
void setsacha(fight_t *fight);
void setbarrevie(fight_t *fight);
void choise_poke(fight_t *fight);
void setmypoke(fight_t *fight);
void print_mybarre(all_t *all);
void attaque(all_t *all);
void set_fullcbt(fight_t *fight);
void inventaire_e(all_t *all);
void setpokemonad(fight_t *fight);
void printpokead(all_t *all);
char *my_malloc(unsigned int size);
char *my_itoa(int num);
vita_t *init_vita();
void text_vita(vita_t *vita);
void printmyvita(all_t *all);
int my_atoi(char *str);
void adattack(all_t *all);
float pourcentattak(char *str1, char *str, int z);
float degatmyattak(char *str, int z);
void initvie_all(all_t *all);
void initaprescbt(all_t *all);
void vita_up(all_t *all);

#endif
