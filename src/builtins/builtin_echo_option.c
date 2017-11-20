/*
** builtin_echo_option.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun  2 13:35:28 2016 David Munoz
** Last update Sat Jun  4 18:08:36 2016 David Munoz
*/

#include "shell.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

/*
** Check wich option is inputed
*/
int		check_option(int ac, char **av)
{
  int   i;
  int   j;
  int   opt;

  i = 0;
  opt = 0;
  while (++i != ac)
    {
      if (av[i][0] != '-'
          || (av[i][0] == '-' && av[i][1] == '\0'))
        return (opt);
      else
        {
          j = 0;
          while (av[i][++j] != '\0')
            {
              if (av[i][j] != 'n' && av[i][j] != 'e'
                  && av[i][j] != 'E')
                return (opt);
            }
          opt++;
        }
    }
  return (opt);
}

/*
** Classic echo if no option inputed
*/
void		no_option(char **av)
{
  int   i;
  int   j;

  i = 1;
  while (av[i])
    {
      j = 0;
      while (av[i][j])
        {
	  if (av[i][j] != 34)
	    my_putchar(av[i][j]);
          j++;
        }
      my_putchar(' ');
      i++;
    }
  printf("\n");
}

/*
** Execute the right option
*/
int		*right_arg(char **av, int nb_opt, int *option)
{
  int   i;
  int   j;

  i = 0;
  while (++i <= nb_opt)
    {
      j = 1;
      while (av[i][j] != '\0')
        {
          if (av[i][j] == 'n')
            option[0] = 1;
          else if (av[i][j] == 'e')
            {
              option[1] = 1;
              option[2] = 0;
            }
          else if (av[i][j] == 'E')
            {
              option[1] = 0;
              option[2] = 1;
            }
          j++;
        }
    }
  return (option);
}

/*
** Print the backslash in question
** \a = alert ; \b = backspace
** \e = escape; \f = form feed
** \r = carriage return ; \v = vertical tab
*/
void		print_echo_backslash(int k)
{
  if (FLAGS[k] == 'a')
    my_putchar('\a');
  if (FLAGS[k] == 'b')
    my_putchar('\b');
  if (FLAGS[k] == 'e')
    my_putchar('\033');
  if (FLAGS[k] == 'f')
    my_putchar('\f');
  if (FLAGS[k] == 'n')
    my_putchar('\n');
  if (FLAGS[k] == 'r')
    my_putchar('\r');
  if (FLAGS[k] == 't')
    my_putchar('\t');
  if (FLAGS[k] == 'v')
    my_putchar('\v');
}

void		delete_coma(char *back, int i)
{
  if (back[i] != 34)
    my_putchar(back[i]);
}
