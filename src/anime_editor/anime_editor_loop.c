/*
** EPITECH PROJECT, 2017
** my_rpg_2017
** File description:
** anime_game_loop.c
*/

#include <stdlib.h>
#include <stdbool.h>
#include "prototype.h"
#include "macro.h"

void zoom(sfEvent *event, sfIntRect *sprite_rect)
{
	if (event->type == sfEvtMouseWheelScrolled) {
		sprite_rect->width += event->mouseWheelScroll.delta;
		if (sprite_rect->width <= 1)
			sprite_rect->width = 1;
		if (sprite_rect->width >= 100)
			sprite_rect->width = 100;
		sprite_rect->height = sprite_rect->width;
	}
}

void set_rectex_pos(sfEvent *event, sfRenderWindow *window,
		    rectex_t *rectex, sfIntRect sprite_rect)
{
	if (event->type == sfEvtMouseButtonPressed)
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			rectex->rect.left = (MOUSE_POS.x - sprite_rect.left);
			rectex->rect.top = (MOUSE_POS.y - sprite_rect.top);
			rectex->rect.left /= sprite_rect.width;
			rectex->rect.top /= sprite_rect.height;
			rectex->rect.width = 0;
			rectex->rect.height = 0;
		}
}

void sprite_move(sfEvent *event, sfRenderWindow *window, sfIntRect *sprite_rect)
{
	if (event->type == sfEvtMouseMoved) {
		if (MOUSE_POS.x < 10)
			sprite_rect->left += 10;
		if (MOUSE_POS.y < 10)
			sprite_rect->top += 10;
		if (MOUSE_POS.x >= (int)WINDOW_SIZE.x - 10)
			sprite_rect->left -= 10;
		if (MOUSE_POS.y >= (int)WINDOW_SIZE.y - 10)
			sprite_rect->top -= 10;
	}
}

void manage_nums(anime_tab_t *anime_tab, size_t *anime_num, size_t *rectex_num)
{
	if (sfKeyboard_isKeyPressed(sfKeyP))
		if (*rectex_num > 0)
			*rectex_num -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyN))
		if (*rectex_num < anime_tab->anime[*anime_num].nb_rectex - 1)
			*rectex_num += 1;
	if (sfKeyboard_isKeyPressed(sfKeyBack))
		if (*anime_num > 0)
			*anime_num -= 1;
	if (sfKeyboard_isKeyPressed(sfKeyReturn))
		if (*anime_num < anime_tab->nb_anime - 1)
			*anime_num += 1;
}

void manage_rectex(rectex_t *rectex)
{
	bool cond = sfKeyboard_isKeyPressed(sfKeyLShift);

	if (cond || sfKeyboard_isKeyPressed(sfKeyRShift)) {
		sfKeyboard_isKeyPressed(sfKeyLeft) ? rectex->rect.width-- : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? rectex->rect.width++ : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? rectex->rect.height-- : 0;
		sfKeyboard_isKeyPressed(sfKeyDown) ? rectex->rect.height++ : 0;
	}
	else {
		sfKeyboard_isKeyPressed(sfKeyLeft) ? rectex->rect.left-- : 0;
		sfKeyboard_isKeyPressed(sfKeyRight) ? rectex->rect.left++ : 0;
		sfKeyboard_isKeyPressed(sfKeyUp) ? rectex->rect.top-- : 0;
		sfKeyboard_isKeyPressed(sfKeyDown) ? rectex->rect.top++ : 0;
	}
	if (cond && sfKeyboard_isKeyPressed(sfKeyRShift)) {
		if (rectex->rect.width > rectex->rect.height)
			rectex->rect.height = rectex->rect.width;
		if (rectex->rect.height > rectex->rect.width)
			rectex->rect.width = rectex->rect.height;
	}
}

void manage_rectex2(anime_tab_t *anime_tab, rectex_t *rectex,
		    size_t *anime_num, size_t *rectex_num)
{
	if (sfKeyboard_isKeyPressed(sfKeyEqual) && *rectex_num > 0) {
		rectex->rect.width = anime_tab->anime[*anime_num].rectex[*rectex_num - 1].rect.width;
		rectex->rect.height = anime_tab->anime[*anime_num].rectex[*rectex_num - 1].rect.height;
	}
}

int anime_editor_loop(sfRenderWindow *window, anime_tab_t *anime_tab)
{
	sfSprite *sprite = sfSprite_create();
	sfRectangleShape *rect = sfRectangleShape_create();
	sfEvent event;
	size_t anime_num = 0;
	size_t rectex_num = 0;
	sfIntRect sprite_rect = {0, 0, 1, 1};
	rectex_t *rectex = &anime_tab->anime[anime_num].rectex[rectex_num];

	sfRectangleShape_setFillColor(rect, sfTransparent);
	sfRectangleShape_setOutlineColor(rect, sfRed);
	sfSprite_setTexture(sprite, anime_tab->texname[rectex->texture_num].texture, sfTrue);
	while (sfRenderWindow_isOpen(window)) {
		if (sfMouse_isButtonPressed(sfMouseLeft)) {
			rectex->rect.width = (MOUSE_POS.x - sprite_rect.left) / sprite_rect.width - rectex->rect.left;
			rectex->rect.height = (MOUSE_POS.y - sprite_rect.top) / sprite_rect.height - rectex->rect.top;
		}
		while (sfRenderWindow_pollEvent(window, &event)) {
			evt_close(&event, window);
			zoom(&event, &sprite_rect);
			set_rectex_pos(&event, window, rectex, sprite_rect);
			sprite_move(&event, window, &sprite_rect);
			if (event.type == sfEvtKeyPressed) {
				manage_rectex(rectex);
				manage_rectex2(anime_tab, rectex, &anime_num, &rectex_num);
				manage_nums(anime_tab, &anime_num, &rectex_num);
				anime_tab->num = anime_num;
				rectex = &anime_tab->anime[anime_num].rectex[rectex_num];
			}
		}
		sfRectangleShape_setOutlineThickness(rect, sprite_rect.width);
		sfRectangleShape_setPosition(rect, (sfVector2f){rectex->rect.left * sprite_rect.width + sprite_rect.left, rectex->rect.top * sprite_rect.height + sprite_rect.top});
		sfRectangleShape_setSize(rect, (sfVector2f){rectex->rect.width * sprite_rect.width, rectex->rect.height * sprite_rect.height});
		sfSprite_setPosition(sprite, (sfVector2f){sprite_rect.left, sprite_rect.top});
		sfSprite_setScale(sprite, (sfVector2f){sprite_rect.width, sprite_rect.height});
		sfRenderWindow_clear(window, sfBlack);
		sfRenderWindow_drawSprite(window, sprite, NULL);
		sfRenderWindow_drawRectangleShape(window, rect, NULL);
		anime_tab_aff(window, anime_tab, (sfFloatRect){1500, 400, 500, 500});
		sfRenderWindow_display(window);
	}
	sfRectangleShape_destroy(rect);
	sfSprite_destroy(sprite);
	return (0);
}
