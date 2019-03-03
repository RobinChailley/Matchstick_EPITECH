/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

int game_ended_core(all_t *all, int i)
{
	for (int j = 0; j < all->size_x; j++)
		if (all->tab_cpy[i][j] == '|')
			return (0);
	return (1);
}

int game_ended(all_t *all)
{
	for (int i = 0; i < all->size_y; i++) {
		if (game_ended_core(all, i) == 0)
			return (0);
	}
	return (1);
}