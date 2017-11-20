/*
** builtin_echo_option2.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun  2 13:51:15 2016 David Munoz
** Last update Sat Jun  4 16:58:02 2016 David Munoz
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
** OPTION : -e
** DESC: enable interpretation of backslash escapes
** \c produce no further output
*/
int		echo_option_e(char **av, int ac, int *option, int nb_opt)
{
  char	*back;
  int   i;

  while (nb_opt < ac)
    {
      i = 0;
      back = delete_backslash(av[nb_opt]);
      while (back[i])
        {
          if (back[i] == '\\' && back[i+1] == 'c')
            back[i + 2] = '\0';
          i = echo_backslash(back, i);
          i++;
        }
      free(back);
      my_putchar(' ');
      nb_opt++;
    }
  if (option[0] == 0)
    my_putchar('\n');
  return (0);
}

/*
** OPTION : -E
** DESC : disable  interpretation
** of backslash escapes
*/
void		echo_option_E(char **av, int ac, int *option, int nb_opt)
{
  int   i;

  while (nb_opt < ac)
    {
      i = 0;
      while (av[nb_opt][i])
        {
	  if (av[nb_opt][i] != 34)
	    my_putchar(av[nb_opt][i]);
          i++;
        }
      my_putchar(' ');
      nb_opt++;
    }
  if (option[0] == 0)
    my_putchar('\n');
}

/*
** Direct to the right option
*/
void		print_echo_arg(char **av, int ac, int nb_opt, int *option)
{
  int   i;

  i = ac - nb_opt - 1;
  if (i == 0)
    {
      if (option[0] != 1)
        printf("\n");
    }
  else
    {
      nb_opt++;
      if (option[1] == 1)
        echo_option_e(av, ac, option, nb_opt);
      else if (option[2] == 1)
        echo_option_E(av, ac, option, nb_opt);
    }
}
