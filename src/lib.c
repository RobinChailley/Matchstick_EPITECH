/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** get_nbr
*/

#include "my.h"

void my_putchar(char c)
{
	write(1, &c, 1);
}

void my_putstr(char *str)
{
	for (int i = 0; str[i]; i++)
		my_putchar(str[i]);
}

void my_putnbr(int nb)
{
	int m;

	if (nb < 0) {
		my_putchar('-');
		nb = nb * -1;
	}
	if (nb >= 0) {
		if (nb >= 10) {
			m = (nb % 10);
			nb = (nb - m) / 10;
			my_putnbr(nb);
			my_putchar(m + 48);
		} else {
			my_putchar(48 + (nb % 10));
		}
	}
}

void		reverse_str(char *str)
{
	int i = 0;
	int j = 0;
	char c;

	for (i = 0, j = my_strlen(str)-1; i<j; i++, j--) {
		c = str[i];
		str[i] = str[j];
		str[j] = c;
	}
}

void 		my_getcharstar(int nb, char *str)
{
	int i = 0;
	int sign = nb;

	if (sign < 0)
		nb = -nb;
	do {
		str[i++] = nb % 10 + '0';
	} while ((nb /= 10) > 0);
	if (sign < 0)
		str[i++] = '-';
	str[i] = '\0';
	reverse_str(str);
}