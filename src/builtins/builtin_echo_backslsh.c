/*
** builtin_echo_backslsh.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Thu Jun  2 13:54:23 2016 David Munoz
** Last update Sat Jun  4 18:08:27 2016 David Munoz
*/

#include "shell.h"

/*
** If flag exist dont print '\\'
*/
int		echo_flag_exist(char *back, int i)
{
  int   k;

  k = -1;
  while (FLAGS[++k] && back[i] != FLAGS[k]);
  if (FLAGS[k])
    i -= 2;
  else
    {
      my_putchar('\\');
      i -= 1;
    }
  return (i);
}

char		*add_end_back_token(char *bck, char *av,
				   int i, int j)
{
  if (av[i] == '\\')
    i++;
  while (av[i])
    {
      bck[j] = av[i];
      i++;
      j++;
    }
  bck[j] = 0;
  return (bck);
}

/*
** Ici convertir av[nb_opt][i] par back
*/
char		*delete_backslash(char *av)
{
  char	*bck;
  int	j;
  int	i;

  i = 0;
  j = 0;
  if ((bck = malloc((sizeof(char) * my_strlen(av)) + 2)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (av[j] != '\\' && av[j] != '\0')
    {
      bck[j] = av[j];
      j++;
      i++;
    }
  while (av[i] == '\\' && av[i+1] == '\\')
    {
      bck[j] = '\\';
      i += 2;
      j++;
    }
  bck = add_end_back_token(bck, av, i, j);
  return (bck);
}

/*
** Check if double backslash exist
*/
int		check_double_backslash(char *back, int i)
{
  int   j;
  int   k;
  int   tmp;

  j = 0;
  k = -1;
  while (back[i] == '\\')
    {
      i++;
      j++;
    }
  tmp = j;
  j = j / 2;
  while (++k < j)
    my_putchar('\\');
  if (tmp % 2 == 0)
    i--;
  else
    i = echo_flag_exist(back, i);
  return (i);
}

/*
** Pars all backslash escapes
*/
int		echo_backslash(char *back, int i)
{
  int   k;
  int   check;

  check = 0;
  if (back[i] == '\\' && back[i+1] == '\\')
    {
      i = check_double_backslash(back, i);
      check++;
    }
  else if (back[i] == '\\')
    {
      k = -1;
      while (FLAGS[++k] && back[i + 1] != FLAGS[k]);
      if (FLAGS[k])
        {
          print_echo_backslash(k);
          i++;
          check++;
        }
      else
        my_putchar('\\');
    }
  else if (check == 0)
    delete_coma(back, i);
  return (i);
}
