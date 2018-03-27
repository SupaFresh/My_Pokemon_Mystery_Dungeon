/*
** EPITECH PROJECT, 2017
** header
** File description:
** header
*/

#ifndef MY_H
#define MY_H

#include <stdlib.h>
#include <unistd.h>
#include <SFML/Graphics.h>
#define TEX_FIRE "texture/fire.png"
#define TEX_SMOKE "texture/smoke.png"

typedef struct {
	sfRectangleShape *rect;
	sfTexture *texture;
	sfVector2f speed;
	sfVector2f acc;
} particle_t;

typedef struct {
	size_t nb_particle;
	particle_t *particle;
} particle_tab_t;

int **mem_alloc_2d_array_int(int nb_rows, int nb_cols);
char **mem_alloc_2d_array(int nb_rows, int nb_cols);
int fs_open_file (char const *filepath);
int my_atoi(char *str);
int my_putstr(char const *str);

#endif
