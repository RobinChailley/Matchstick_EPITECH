/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** init.c
*/

#include "my.h"

void create_tab(all_t *all)
{
	all->tab = malloc(sizeof(char *) * (all->size_y + 2));
	for (int i = 0; i < all->size_y; i++)
		all->tab[i] = malloc(sizeof(char) * (all->size_x + 2));
	for (int i = 0; i < all->size_y; i++) {
		for (int j = 0; j < all->size_x; j++)
			all->tab[i][j] = ' ';
	}
	for (int i = 0; i < all->size_x - 1; i++) {
		all->tab[0][i] = '*';
		all->tab[all->size_y - 1][i] = '*';
	}
	for (int i = 0; i < all->size_y; i++) {
		all->tab[i][0] = '*';
		all->tab[i][all->size_x- 1] = '*';
		all->tab[i][all->size_x] = 0;
	}
	all->tab[all->size_y] = NULL;
}

void fill_tab(all_t *all)
{
	for (int i = 1; i < all->size_y - 1; i++) {
		all->tab[i][(all->size_x / 2)] = '|';
		for (int j = 0; j < i; j++) {
			all->tab[i][(all->size_x / 2) - j] = '|';
			all->tab[i][(all->size_x / 2) + j] = '|';
		}
	}
}

res_t *init_res(void)
{
	res_t *res = malloc(sizeof(*res));

	res->score = 0;
	res->line = 0;
	res->ms = 0;
	res->next = NULL;
	return (res);
}

void create_all_2(char **av, all_t *all)
{
	all->res = init_res();
	all->input = NULL;
	all->line = 0;
	all->ms = 0;
	all->max = my_getnbr(av[2]);
	all->size_y = my_getnbr(av[1]);
	all->size_x = 0;
	for (int i = 0; i < all->size_y; i++)
		all->size_x += 2;
	all->size_x += 1;
	all->size_y += 2;
	create_tab(all);
	fill_tab(all);
	all->tab_cpy = malloc(sizeof(char *) * all->size_y + 2);
	for (int i = 0; i < all->size_y + 2; i++)
		all->tab_cpy[i] = malloc(sizeof(char) * all->size_x + 2);
}

void create_all(all_t *all, char **av, int *ret_value)
{
	srand(time(NULL));
	if (av[1] && av[2]) {
		if (int_char_star(av[2]) == 0 || int_char_star(av[1]) == 0) {
			*ret_value = -1;
			return;
		}
		if (my_getnbr(av[2]) == 0 || my_getnbr(av[1]) < 2 ||
		my_getnbr(av[1]) > 99) {
			*ret_value = -1;
			return;
		}
		create_all_2(av, all);
	} else {
		*ret_value = -1;
	}
}