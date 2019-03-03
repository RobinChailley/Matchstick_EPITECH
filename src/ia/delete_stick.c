/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

void delete_stick_cpy(int line, int ms, all_t *all)
{
	int i = 1;

	while (all->tab_cpy[line][i] == ' ' && all->tab_cpy[line][i])
		i++;
	while (all->tab_cpy[line][i] == '|' && all->tab_cpy[line][i])
		i++;
	i--;
	for (int j = 0; j < ms; j++) {
		if (all->tab_cpy[line][i] == '|')
			all->tab_cpy[line][i] = ' ';
		i--;
	}
}

void delete_stick(int line, int ms, all_t *all)
{
	int i = 1;

	while (all->tab[line][i] == ' ' && all->tab[line][i])
		i++;
	while (all->tab[line][i] == '|' && all->tab[line][i])
		i++;
	i--;
	for (int j = 0; j < ms; j++) {
		if (all->tab[line][i] == '|')
			all->tab[line][i] = ' ';
		i--;
	}
}

int there_is_still_sticks_core(all_t *all, int i)
{
	for (int j = 0; j < all->size_x; j++) {
		if (all->tab[i][j] == '|')
			return (1);
	}
	return (0);
}

int there_is_still_sticks(all_t *all)
{
	for (int i = 0; i < all->size_y; i++) {
		if (there_is_still_sticks_core(all, i) == 1)
			return (1);
	}
	return (0);
}

int line_empty(all_t *all, char *str)
{
	for (int i = 0; i < all->size_x + 2; i++) {
		if (str[i] == '|') {
			return (0);
		}
	}
	return (1);
}