/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** loop.c
*/

#include "my.h"

int ask_line(all_t *all)
{
	my_putstr("Line: ");
	all->input = get_next_line(0);
	if (all->input == NULL || all->input[0] == 0)
		return (-1);
	all->line = my_getnbr(all->input);
	return (0);
}

int ask_ms(all_t *all)
{
	my_putstr("Matches: ");
	all->input = get_next_line(0);
	if (all->input == NULL || all->input[0] == 0)
		return (-1);
	all->ms = my_getnbr(all->input);
	return (0);
}