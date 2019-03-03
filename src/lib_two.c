/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** get_nbr
*/

#include "my.h"

char 		*my_strcat(char *s1, char *s2)
{
	int i = 0;
	int a = 0;
	char *new = malloc(sizeof(char) * (my_strlen(s1) + my_strlen(s2) + 1));

	for (int j = 0; j < my_strlen(s1) + my_strlen(s2) + 1; j++)
		new[j] = '\0';
	if (s1 != NULL) {
		while (s1[i] != '\0') {
			new[i] = s1[i];
			i++;
		}
	}
	if (s2 != NULL) {
		while (s2[a] != '\0') {
			new[i] = s2[a];
			i++;
			a++;
		}
	}
	return (new);
}

int my_strlen(char *str)
{
	int i = 0;

	while (str[i] != 0)
		i++;
	return (i);
}

int my_getnbr(char *str)
{
	int sign = 0;
	int res = 0;
	int i = 0;

	if (str[0] == '-') {
		sign = -1;
		i = 1;
	} else
		sign = 1;

	while (str[i] != '\0') {
		if (str[i] >= '0' && str[i] <= '9')
			res = (res * 10) + (str[i] - '0');
		else
			break;
		i++;
	}
	res = res * sign;
	return (res);
}