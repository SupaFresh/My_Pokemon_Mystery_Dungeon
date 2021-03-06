/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdbool.h>
#include "prototype.h"
#include "main_menu/menu.h"
#include "macro.h"

size_t move_curseur(menu_t *menu, sfEvent *event)
{
	static size_t y = 0;
	static ssize_t r = 0;

	if (event && event->type == sfEvtKeyPressed) {
		if (r == 0 && sfKeyboard_isKeyPressed(sfKeyUp) && y > 0) {
			y -= 1;
			sfMusic_play(menu->sound.sound_effect[5]);
			r = 100;
		} if (r == 0 && sfKeyboard_isKeyPressed(sfKeyDown)
		&& y < NB_BUTTON - 1) {
			y += 1;
			sfMusic_play(menu->sound.sound_effect[5]);
			r = -100;
		}
	}
	sfRectangleShape_setPosition(menu->rect[3],
	V2F(10, y * 100 + r + 20));
	r > 0 ? r -= 10 : 0;
	r < 0 ? r += 10 : 0;
	return (y);
}
