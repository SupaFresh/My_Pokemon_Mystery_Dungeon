/*
** EPITECH PROJECT, 2018
** for_norme
** File description:
** entity.h
*/

#ifndef ENTITY_H_
#define ENTITY_H_

#include <SFML/Graphics.h>
#include <stdbool.h>
#include "map.h"

typedef struct {
	sfVector2i pos;
	sfVector2f move_pos;
	sfVector2i new_pos;
} entity_t;

void entity_move(entity_t *entity);
void entity_aff(sfRenderWindow *window, entity_t *entity,
		map_t *map, sfVector2f *pos);

#endif
