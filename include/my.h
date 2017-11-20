/*
** my.h for my.h in /home/onillo_l/rendu/Piscine/Piscine_C_J09/include
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Thu Oct  8 12:20:26 2015 Lucas Onillon
** Last update Tue Mar 29 11:50:20 2016 Lucas
*/

#ifndef	MY_H_
# define MY_H_

# include <unistd.h>
# include <stdlib.h>
# include "utils.h"
# include "get_next_line.h"

void		my_putchar(char c);
int		my_isneg(int nb);
int		my_put_nbr(int nb);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_getnbr(char *str);
char		*my_strcpy(char *dest, char *src);
char		*my_strncpy(char *dest, char *src, int nb);
char		*my_revstr(char *str);
int		my_strstr(char *str, char *to_find);
int		my_strcmp(char *s1, char *s2);
int		my_strncmp(char *s1, char *s2, int nb);
char		*my_strcat(char *dest, char *src);
char		*my_strncat(char *dest, char *src, int nb);
int		my_strlcat(char *dest, char *src, int size);
int		is_alpha(char c);
int		is_num(char c);
int		is_alphanum(char c);
int		cerr_zero(char *log, char *info, int status);
void		*cerr_msg(char *log, char *info);
char		*cerr_null(char *log, char *info);
int		is_digit(char c);
char		**my_str_to_wordtab(char *str, char c);
int		cpt_word(char *str, char c);
char		*copy(char *str, char *dest, int begin, char c);
int		cpt_letter(char *str, int begin, char c);
char		*my_strdup(char *src);
char		*my_realloc(char *recup, int ret);
char		*my_concat(char *s1, char *s2);

#endif	/* MY_H_ */
