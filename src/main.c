/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** main.c
*/

#include <stdlib.h>
#include "prototype.h"

int my_strcmp(const char *a, const char *b)
{
	return (*a != *b || *a == '\0' ? *a - *b : my_strcmp(a + 1, b + 1));
}

int main(int nb_arg, char **arg_tab)
{
	srand((long long)arg_tab);
	return (main_menu());
	/*if (nb_arg == 1)
		return (game_menu());
	else {
		if (my_strcmp(arg_tab[1], "-m") == 0)
			return (map_editor_menu());
		else if (my_strcmp(arg_tab[1], "-a") == 0)
			return (anime_editor_menu());
			}*/
}
