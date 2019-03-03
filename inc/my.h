/*
** EPITECH PROJECT, 2017
** CPE_matchstick_2017
** File description:
** my.h
*/

#ifndef MY_H_
#define MY_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define READ_SIZE 50000

typedef struct res_s res_t;
typedef struct res_s
{
	int line;
	int ms;
	int score;
	res_t *next;
} res_t;

typedef struct all_s
{
	int size_x;
	int size_y;
	char **tab;
	char **tab_cpy;
	int max;
	char *input;
	int line;
	int ms;
	res_t *res;
} all_t;

int my_strlen(char *str);
int rand_a_b(int a, int b);
int my_getnbr(char *str);
void create_tab(all_t *all);
void fill_tab(all_t *all);
void create_all(all_t *all, char **av, int *ret_value);
char *get_next_line(int fd);
void display_grid(all_t *all);
void my_putstr(char *str);
void my_putchar(char c);
int int_char_star(char *str);
void my_putnbr(int nb);
int loop(all_t *all);
void display_sentence(all_t *all);
int ask_line(all_t *all);
int ask_ms(all_t *all);
void delete_stick(int line, int ms, all_t *all);
int loop_player_core(all_t *all, int *a);
int loop_player(all_t *all);
res_t *init_res(void);
int there_is_still_sticks(all_t *all);
int loop(all_t *all);
int valid_line(all_t *all);
int enough_match_on_line(all_t *all);
int valid_ms(all_t *all);
void reverse_str(char *str);
void my_getcharstar(int nb, char *str);
char *my_strcat(char *s1, char *s2);
void delete_stick_cpy(int line, int ms, all_t *all);
int line_empty(all_t *all, char *str);
int ms_line_cpy(int lia, all_t *all);
void ia(all_t *all);
void cpy_tab(all_t *all);
void get_random_pos_valid(all_t *all, int *line_ia, int *ms_ia);
int add_res_core(res_t *tmp, int line_ia, int ms_ia, int win);
void remove_res(all_t *all);
void search_best_res(all_t *all, int *line_ia, int *ms_ia, int max);
int play_game(all_t *all, int line, int ms);
void get_ia_play(all_t *all, int *line_ia, int *ms_ia);
int game_ended(all_t *all);
void add_res(int win, int line_ia, int ms_ia, all_t *all);
#endif /* !MY_H_ */