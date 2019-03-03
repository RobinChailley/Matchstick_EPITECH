/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** main.c
*/

#include "my.h"

int rand_a_b(int a, int b)
{
	return (rand()%(b-a) +a);
}

int main(int ac, char **av)
{
	int ret_value = 0;
	all_t all;
	int ret = 0;

	(void)ac;
	create_all(&all, av, &ret_value);
	if (ret_value == -1)
		return (84);
	ret = loop(&all);
	return (ret);
}