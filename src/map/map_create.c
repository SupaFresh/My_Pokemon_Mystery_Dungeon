/*
** EPITECH PROJECT, 2018
** rpg
** File description:
** map_create.c
*/

#include <stdlib.h>
#include "map.h"

map_t map_create(int nb_case_x, int nb_case_y)
{
	map_t map = {.nb_case_x = nb_case_x, .nb_case_y = nb_case_y};

	map.tab = malloc(sizeof(tab_t *) * map.nb_case_x);
	if (map.tab == NULL) {
		map.nb_case_x = 0;
		return (map);
	}
	for (size_t i = 0; i < map.nb_case_x; i++) {
		map.tab[i] = malloc(sizeof(tab_t) * map.nb_case_y);
		if (map.tab[i] == NULL) {
			map.nb_case_x = 0;
			return (map);
		}
	}
	return (map);
}
