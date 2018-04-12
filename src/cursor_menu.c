/*
** EPITECH PROJECT, 2018
** test
** File description:
** test
*/

#include <stdbool.h>
#include "prototype.h"
#include "menu.h"

size_t move_curseur(menu_t *menu, sfEvent *event)
{
	static size_t y = 0;
	static ssize_t r = 0;

	if (event && event->type == sfEvtKeyPressed) {
		if (r == 0 && sfKeyboard_isKeyPressed(sfKeyUp) && y > 0) {
			y -= 1;
			r = 100;
		} if (r == 0 && sfKeyboard_isKeyPressed(sfKeyDown) && y <  NB_BUTTON - 1) {
			y += 1;
			r = -100;
		}
	}
	y == 0 ? sfRectangleShape_setPosition(menu->rect[3], (sfVector2f) {10, 20}) :
	sfRectangleShape_setPosition(menu->rect[3], (sfVector2f) {10, y * 100 + r});
	r > 0 ? r -= 10 : 0;
	r < 0 ? r += 10 : 0;
	return (y);
}
