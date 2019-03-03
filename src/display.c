/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** display.c
*/

#include "my.h"

void display_grid(all_t *all)
{
	for (int i = 0; all->tab[i]; i++) {
		my_putstr(all->tab[i]);
		my_putchar('\n');
	}
}

void display_sentence(all_t *all)
{
	my_putstr("Player removed ");
	my_putnbr(all->ms);
	my_putstr(" match(es) from line ");
	my_putnbr(all->line);
	my_putchar('\n');
}