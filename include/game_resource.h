/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** game_resource.h
*/

#ifndef GAME_RESOURCE_H_
#define GAME_RESOURCE_H_

#include <SFML/Graphics.h>
#include <SFML/Audio.h>
#include "settings.h"
#include "dungeon.h"
#include "map.h"
#include "entity.h"
#include "item.h"

// game_macros
#define INVENTORY_SIZE 1

// file_macros
#define GAME_FONT "resources/font/Minecraftia.ttf"
#define GAME_MUSIC "resources/music/adventure.ogg"
#define CAPACITY_UP "resources/texture/Bup.png"
#define CAPACITY_LEFT "resources/texture/Bleft.png"
#define CAPACITY_RIGHT "resources/texture/Bright.png"
#define CAPACITY_DOWN "resources/texture/Bdown.png"
#define STAT_RECT "resources/texture/n1.png"
#define STAT_SHADOW "resources/texture/n5.png"

// code_macros
#define GET_INFO(map) info[(map).nb_case_x][(map).nb_case_y]
#define ITEM(map, entity) (map).item[(entity).pos.x][(entity).pos.y]
#define GENT(num) garou->dungeon.entity[num]

// macro_macros
#define PAUSE game_pause

typedef struct {
	entity_t player;
	dungeon_t dungeon;
	enum item_e inventory[INVENTORY_SIZE];
	sfMusic *music;
	settings_t settings;
} garou_t;

garou_t garou_create(char *settings_file_name);
void garou_destroy(garou_t *garou);
bool game_pause(sfRenderWindow *window, garou_t *garou);
void game_aff(sfRenderWindow *window, garou_t *garou);
void capacity_aff(sfRenderWindow *window, garou_t *garou);
void inventory_aff(sfRenderWindow *window, garou_t *garou);
void atk_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre);
void def_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre);
void spa_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre);
void spd_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfRectangleShape *rectangle_ombre);
void hp_stat(garou_t *garou, sfRenderWindow *window,
	sfText *text, sfFont *font);
bool manage_input(entity_t *entity, map_t *map,
		entity_t *info[map->nb_case_x][map->nb_case_y],
		size_t input);
size_t player(entity_t *entity, garou_t *garou, sfEvent *event);
size_t ia(entity_t *entity, map_t *map,
	entity_t *info[map->nb_case_x][map->nb_case_y]);
void spread(map_t *map, size_t tab[map->nb_case_x][map->nb_case_y],
	entity_t *cible);
size_t input_attack(entity_t *entity, map_t *map,
		size_t tab[map->nb_case_x][map->nb_case_y],
		entity_t *info[map->nb_case_x][map->nb_case_y]);
size_t input_move_short(entity_t *entity, map_t *map,
			size_t tab[map->nb_case_x][map->nb_case_y],
			entity_t *info[map->nb_case_x][map->nb_case_y]);
size_t input_move_long(entity_t *entity, map_t *map,
		size_t tab[map->nb_case_x][map->nb_case_y],
		entity_t *info[map->nb_case_x][map->nb_case_y]);

#endif
