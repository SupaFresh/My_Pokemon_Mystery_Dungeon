/*
** EPITECH PROJECT, 2018
** my_strncat
** File description:
** my_strncat
*/

#include <stdlib.h>
#include <unistd.h>
#include "my.h"

char *concat_n(char *s1, char *s2, int n)
{
	int c = 0;
	char *str = malloc(sizeof(char) * (my_strlen(s1) + n + 1));

	if (str == NULL)
		return (NULL);
	for (int i = 0; s1[i] != '\0'; i++) {
		str[c] = s1[i];
		c++;
	} for (int j = 0; j != n; j++) {
		str[c] = s2[j];
		c++;
	}
	str[c] = '\0';
	return (str);
}
