/*
** EPITECH PROJECT, 2018
** option
** File description:
** option
*/

#include <stdbool.h>
#include <stdio.h>
#include "prototype.h"
#include "macro.h"
#include "main_menu/menu.h"
#include "option_map_editor.h"
#include "main_menu/option_menu.h"

void display_options(option_t *option, sfRenderWindow *window)
{
	sfRenderWindow_drawSprite(window, option->screen, NULL);
	sfRenderWindow_drawRectangleShape(window, option->back, NULL);
	option_choice_cursor(option, window);
	//sfRenderWindow_drawText(window, option->text[option->nb_tile], NULL);
	//sfRenderWindow_drawText(window, option->size_map_x, NULL);
	//sfRenderWindow_drawText(window, option->size_map_y, NULL);
}

void create_option_choice(sfText *choice[3], sfFont *font)
{
	for (size_t i = 0; i < 3; i++) {
		choice[i] = sfText_create();
		sfText_setFont(choice[i], font);
	}
}

option_t option_create(sfRenderWindow *window)
{
	option_t option;

	option.font = sfFont_createFromFile(FONT);
	create_option_choice(option.choice, option.font);
	create_option_choice(option.window_size, option.font);
	option.screen = create_screen_param(window);
	option.back =  create_back_param(window);
	option.size_x = 1920;
	option.size_y = 1080;
	option.choice_curs = 0;
	return (option);
}

void option_choice_cursor(option_t *option, sfRenderWindow *window)
{
	int pos_y = WINDOW_SIZE.y / 2 - 300;

	sfText_setString(option->choice[0], "WINDOW_RESOLUTION");
	sfText_setString(option->choice[1], "GAME VOLUME");
	sfText_setString(option->choice[2], "SOUND_VOLUME");
	for (size_t i = 0; i < 3; i++) {
		sfText_setPosition(option->choice[i], (sfVector2f) {WINDOW_SIZE.x / 2 - 300, pos_y});
		sfText_setColor(option->choice[i], (sfColor){250, 250, 0,
					option->choice_curs == i ? 255 : 180});
		sfRenderWindow_drawText(window, option->choice[i], NULL);
		pos_y += 100;
	}
}

void option_move_cursor(option_t *option, sfEvent *event)
{
	if (event && event->type == sfEvtKeyPressed) {
		if (sfKeyboard_isKeyPressed(sfKeyUp)
		&& option->choice_curs > 0) {
			option->choice_curs--;
		} if (sfKeyboard_isKeyPressed(sfKeyDown)
		&& option->choice_curs <  2) {
			option->choice_curs++;
		}
	}
}

void option_menu(sfRenderWindow *window, sfEvent *event)
{
	option_t option = option_create(window);

	while (sfRenderWindow_isOpen(window)) {
		while (sfRenderWindow_pollEvent(window, event)) {
			if (sfKeyboard_isKeyPressed(sfKeyEscape))
				return;
			option_move_cursor(&option, event);
		}
		sfRenderWindow_clear(window, sfBlack);
		display_options(&option, window);
		sfRenderWindow_display(window);
	}
}
