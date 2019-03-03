/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

int add_res_core(res_t *tmp, int line_ia, int ms_ia, int win)
{
	if (tmp->line == line_ia && tmp->ms == ms_ia) {
		if (win == 1)
			tmp->score += 1;
		return (1);
	}
	return (0);
}

void add_res(int win, int line_ia, int ms_ia, all_t *all)
{
	res_t *n = NULL;
	res_t *tmp = all->res;

	while (tmp->next) {
		if (add_res_core(tmp, line_ia, ms_ia, win) == 1)
			return;
		tmp = tmp->next;
	}
	n = malloc(sizeof(*n));
	n->next = NULL;
	n->line = line_ia;
	n->ms = ms_ia;
	if (win == 1)
		n->score = 1;
	else
		n->score = 0;
	tmp->next = n;
}

void remove_res(all_t *all)
{
	res_t *tmp = NULL;

	while (all->res) {
		tmp = all->res;
		all->res = all->res->next;
		free(tmp);
	}
}