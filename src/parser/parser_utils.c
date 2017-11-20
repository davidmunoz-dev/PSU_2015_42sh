/*
** parser_utils.c for parser_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Mon May 30 13:52:34 2016 Lucas
** Last update Sat Jun  4 19:09:56 2016 Lucas
*/

#include "shell.h"

int		is_separator(char *str, t_shell *shell)
{
  int		i;

  i = 0;
  while (shell->sepa_array && shell->sepa_array[i])
    {
      if (my_strcmp(shell->sepa_array[i], str) == SH_OK)
	return (SH_OK);
      i++;
    }
  return (SH_ERR);
}

char		found_separator(char *str, t_shell *shell)
{
  char		dest;
  int		i;

  i = 0;
  while (shell->sepa_array[i])
    {
      if (my_strcmp(shell->sepa_array[i], str) == SH_OK)
	dest = shell->sepa_level[i+1][0];
      i++;
    }
  return (dest);
}

char		*update_oppos(t_shell *shell)
{
  char		*tab;
  int		i;
  int		nb;

  i = nb = 0;
  if ((tab = malloc(sizeof(char) * (shell->ac + 1))) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
  while (shell->av[i])
    {
      if (is_separator(shell->av[i], shell) == SH_OK)
	{
	  tab[i] = found_separator(shell->av[i], shell);
	}
      else
	tab[i] = '0';
      i++;
    }
  tab[i] = '\0';
  return (tab);
}

int		update_argcount(char **av)
{
  int		i;

  i = 0;
  while (av[i])
    i++;
  return (i);
}

int		calc_len(t_env *env_list)
{
  return ((my_strlen(env_list->name) + my_strlen(env_list->data)));
}
