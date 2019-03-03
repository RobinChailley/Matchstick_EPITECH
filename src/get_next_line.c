/*
** EPITECH PROJECT, 2017
** CPE_getnextline_2017
** File description:
** CPE_getnextline_2017
*/

#include "my.h"

char *my_realloc(char *str, int len)
{
	char *new_str = malloc(sizeof(char) * (READ_SIZE + len + 1));
	int i = 0;

	for (int j = 0; j < len; j++, i++)
		new_str[j] = str[j];
	new_str[i+1] = '\0';
	return (new_str);
}

char get_char(int fd)
{
	static char str[READ_SIZE + 1];
	static int len = 0;
	static int i = 0;

	if (len == i) {
		len = read(fd, str, READ_SIZE);
		if (len == 0 || len == -1)
			return (-1);
		i = 0;
	}
	i++;
	return (str[i - 1]);
}

char *get_next_line(int fd)
{
	char *str = malloc(sizeof(char) * (READ_SIZE + 1));
	int k = 0;

	if (fd == -1)
		return (NULL);
	for (int i = 0; i < READ_SIZE + 1; i++)
		str[i] = '\0';
	while (1) {
		if (k % READ_SIZE == 0)
			str = my_realloc(str, k);
		str[k] = get_char(fd);
		if (str[k] == '\n') {
			str[k] = '\0';
			break;
		} else if (str[k] == -1) {
			free(str);
			return (NULL);
		}
		k++;
	}
	return (str);
}
