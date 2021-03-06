/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_resize.c
*/

#include <stdlib.h>
#include "map.h"

static void swap_map(map_t *map, tva_t **tab,
		size_t nb_case_x, size_t nb_case_y)
{
	for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			tab[i][j] = map->tab[i][j];
	for (size_t i = 0; i < map->nb_case_x; i++)
		free(map->tab[i]);
	free(map->tab);
	map->nb_case_x = nb_case_x;
	map->nb_case_y = nb_case_y;
	map->tab = tab;
}

void item_resize(map_t *map, size_t new_nb_case_x, size_t new_nb_case_y)
{
	enum item_e **item;

	item = malloc(sizeof(enum item_e *) * new_nb_case_x);
	for (size_t i = 0; i < new_nb_case_x; i++) {
		item ? item[i] = malloc(sizeof(tva_t) * new_nb_case_y) : 0;
		if (item == NULL || item[i] == NULL)
			return;
		for (size_t j = 0; j < new_nb_case_y; j++)
			item[i][j] = NONE;
	} for (size_t i = 0; i < map->nb_case_x; i++)
		for (size_t j = 0; j < map->nb_case_y; j++)
			item[i][j] = map->item[i][j];
	for (size_t i = 0; i < map->nb_case_x; i++)
		free(map->item[i]);
	free(map->item);
	map->item = item;
}

void map_resize(map_t *map, size_t new_nb_case_x, size_t new_nb_case_y)
{
	tva_t **tab;

	if (new_nb_case_x <= 0 || new_nb_case_y <= 0)
		return;
	tab = malloc(sizeof(tva_t *) * new_nb_case_x);
	for (size_t i = 0; i < new_nb_case_x; i++) {
		tab ? tab[i] = malloc(sizeof(tva_t) * new_nb_case_y) : 0;
		if (tab == NULL || tab[i] == NULL)
			return;
		for (size_t j = 0; j < new_nb_case_y; j++)
			tab[i][j] = (tva_t){0, 4, 0};
	}
	new_nb_case_x < map->nb_case_x ? map->nb_case_x = new_nb_case_x : 0;
	new_nb_case_y < map->nb_case_y ? map->nb_case_y = new_nb_case_y : 0;
	item_resize(map, new_nb_case_x, new_nb_case_y);
	swap_map(map, tab, new_nb_case_x, new_nb_case_y);
}
