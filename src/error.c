/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** get_nbr
*/

#include "my.h"

int is_a_int(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

int int_char_star(char *str)
{
	for (int i = 0; str[i]; i++) {
		if (is_a_int(str[i]) == 0) {
			return (0);
		}
	}
	return (1);
}

int valid_line(all_t *all)
{
	if (int_char_star(all->input) == 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (my_getnbr(all->input) > all->size_y - 2 ||
	my_getnbr(all->input) == 0) {
		my_putstr("Error: this line is out of range\n");
		return (-1);
	}
	return (0);
}

int enough_match_on_line(all_t *all)
{
	int nb_match = 0;

	for (int i = 0; i < all->size_x; i++) {
		if (all->tab[all->line][i] == '|')
			nb_match++;
	}
	if (my_getnbr(all->input) > nb_match)
		return (-1);
	return (1);
}

int valid_ms(all_t *all)
{
	if (int_char_star(all->input) == 0) {
		my_putstr("Error: invalid input (positive number expected)\n");
		return (-1);
	}
	if (my_getnbr(all->input) > all->max) {
		my_putstr("Error: you cannot remove more than ");
		my_putnbr(all->max);
		my_putstr(" matches per turn\n");
		return (-1);
	}
	if (my_getnbr(all->input) == 0) {
		my_putstr("Error: you have to remove at least one match\n");
		return (-1);
	}
	if (enough_match_on_line(all) == -1) {
		my_putstr("Error: not enough matches on this line\n");
		return (-1);
	}
	return (0);
}