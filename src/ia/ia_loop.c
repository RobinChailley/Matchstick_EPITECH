/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

void get_ia_play(all_t *all, int *line_ia, int *ms_ia)
{
	int win = 0;
	int max = 0;

	all->res = init_res();
	for (int i = 0; i < 10000; i++) {
		cpy_tab(all);
		get_random_pos_valid(all, line_ia, ms_ia);
		win = play_game(all, *line_ia, *ms_ia);
		add_res(win, *line_ia, *ms_ia, all);
	}
	search_best_res(all, line_ia, ms_ia, max);
}

int play_game(all_t *all, int line, int ms)
{
	delete_stick_cpy(line, ms, all);
	if (game_ended(all) == 1)
		return (0);
	while (1) {
		get_random_pos_valid(all, &line, &ms);
		delete_stick_cpy(line, ms, all);
		if (game_ended(all) == 1)
			return (1);
		get_random_pos_valid(all, &line, &ms);
		delete_stick_cpy(line, ms, all);
		if (game_ended(all) == 1)
			return (0);
	}
	return (-1);
}

void search_best_res(all_t *all, int *line_ia, int *ms_ia, int max)
{
	for (res_t *tmp = all->res->next; tmp; tmp = tmp->next ) {
		if (tmp->score > max)
			max = tmp->score;
	}
	for (res_t *tmp = all->res->next; tmp; tmp = tmp->next) {
		if (tmp->score == max) {
			*line_ia = tmp->line;
			*ms_ia = tmp->ms;
			remove_res(all);
			return;
		}
	}
}


void ia(all_t *all)
{
	int line_ia = 1;
	int ms_ia = 1;

	display_grid(all);
	my_putstr("\nAI's turn...\nAI removed ");
	get_ia_play(all, &line_ia, &ms_ia);
	delete_stick(line_ia, ms_ia, all);
	my_putnbr(ms_ia);
	my_putstr(" match(es) from line ");
	my_putnbr(line_ia);
	my_putchar('\n');
}