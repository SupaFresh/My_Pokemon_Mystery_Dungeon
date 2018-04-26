/*
** EPITECH PROJECT, 2018
** my_rpg_2017
** File description:
** settings_save.c
*/

#include <fcntl.h>
#include "settings.h"
#include "my.h"

void settings_save(settings_t *settings, char *file_name)
{
	int fd = CREAT(file_name, S_IRUSR | S_IWUSR | S_IRGRP);

	if (fd == -1)
		return;
	if (settings == NULL)
		*settings = settings_defaut();
	my_fprintf(fd, "%s %d %d\n", "WindowSize:", settings->window_size.x, settings->window_size.y);
	my_fprintf(fd, "%s %f\n", "MusicVolume:", settings->music_volume);
	my_fprintf(fd, "%s %f\n", "SoundVolume:", settings->sound_volume);
	my_fprintf(fd, "%s %d\n", "KeyUp:", settings->key[KEY_UP]);
	my_fprintf(fd, "%s %d\n", "KeyLeft:", settings->key[KEY_LEFT]);
	my_fprintf(fd, "%s %d\n", "KeyRight:", settings->key[KEY_RIGHT]);
	my_fprintf(fd, "%s %d\n", "KeyDown:", settings->key[KEY_DOWN]);
	my_fprintf(fd, "%s %d\n", "KeyEnter:", settings->key[KEY_ENTER]);
	my_fprintf(fd, "%s %d\n", "KeyEchap:", settings->key[KEY_ECHAP]);
	my_fprintf(fd, "%s %d\n", "KeyWait:", settings->key[KEY_WAIT]);
	my_fprintf(fd, "%s %d\n", "KeyRotate:", settings->key[KEY_ROTATE]);
	my_fprintf(fd, "%s %d\n", "KeyAttack:", settings->key[KEY_ATTACK]);
	close(fd);
}
