/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

int loop_player_core(all_t *all, int *a)
{
	int ret = 0;

	while (1) {
		ret = ask_line(all);
		if (ret == -1)
			return (-1);
		if (valid_line(all) == -1)
			break;
		ret = ask_ms(all);
		if (ret == -1)
			return (-1);
		if (valid_ms(all) == -1)
			break;
		*a = 0;
		delete_stick(all->line, all->ms, all);
		break;
	}
	return (0);
}

int loop_player(all_t *all)
{
	int a = 1;

	display_grid(all);
	my_putstr("\nYour turn:\n");
	while (a == 1) {
		if (loop_player_core(all, &a) == -1)
			return (-1);
	}
	display_sentence(all);
	return (0);
}

void get_random_pos_valid(all_t *all, int *line_ia, int *ms_ia)
{
	do {
		*line_ia = rand_a_b(1, all->size_y - 1);
	} while (line_empty(all, all->tab_cpy[*line_ia]) == 1);
	if (all->max <= ms_line_cpy(*line_ia, all))
		*ms_ia = rand_a_b(1, all->max + 1);
	else
		*ms_ia = rand_a_b(1, ms_line_cpy(*line_ia, all) + 1);
}

int loop(all_t *all)
{
	while (1) {
		if (loop_player(all) == -1)
			return (0);
		if (there_is_still_sticks(all) == 0) {
			display_grid(all);
			my_putstr("You lost, too bad...\n");
			return (2);
		}
		ia(all);
		if (there_is_still_sticks(all) == 0) {
			display_grid(all);
			my_putstr("I lost... snif... but I'll ");
			my_putstr("get you next time!!\n");
			return (1);
		}
	}
	return (0);
}