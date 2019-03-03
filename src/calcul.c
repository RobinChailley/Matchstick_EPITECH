/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

int nb_ms_in_line(all_t *all, int line_ia)
{
	int nb = 0;

	for (int i = 0; i < all->size_x; i++) {
		if (all->tab[line_ia][i] == '|')
			nb++;
	}
	return (nb);
}

int rest_line_core(all_t *all, int i, int *nb_line)
{
	for (int j = 0; j < all->size_x - 1; j++) {
		if (all->tab[i][j] == '|') {
			*nb_line += 1;
		}
	}
	return (0);
}

int rest_line(all_t *all)
{
	int nb_line = 0;

	for (int i = 0; i < all->size_y - 1; i++)
		rest_line_core(all, i, &nb_line);
	return (nb_line);
}

int ms_line_cpy(int lia, all_t *all)
{
	int ms = 0;

	for (int i = 0; i < all->size_x; i++) {
		if (all->tab_cpy[lia][i] == '|')
			ms++;
	}
	return (ms);
}

void cpy_tab(all_t *all)
{
	for (int i = 0; all->tab[i]; i++) {
		for (int j = 0; all->tab[i][j]; j++)
			all->tab_cpy[i][j] = all->tab[i][j];
	}
}
