/*
** update_cmd.c for update_cmd in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Tue May 31 13:32:13 2016 Lucas
** Last update Sun Jun  5 23:04:50 2016 Lucas
*/

#include "shell.h"

int		check_syntax(t_shell *shell)
{
  int		i;
  int		j;

  i = j = 0;
  while (shell->av[i])
    {
      while (shell->av[i][j])
	{
	  if (shell->av[i][j] == '|' && shell->av[i][j+1] &&
	      shell->av[i][j+1] == '|' && shell->av[i][j+2] &&
	      shell->av[i][j+2] == '|')
	    return (SH_ERR);
	  j++;
	}
      i++;
    }
  return (SH_OK);
}

int		no_operator(t_shell *shell)
{
  int		check;
  int		i;

  i = check = 0;
  if (check_syntax(shell) == SH_ERR)
    return (SH_ERR);
  while (shell->op_pos[i])
    {
      if (shell->op_pos[i] > '0')
	check++;
      i++;
    }
  if (check > 0)
    return (SH_ERR);
  return (SH_OK);
}

int		update_cmd(t_shell *shell)
{
  char		*tmp;

  tmp = epur_str(shell->buffer);
  if ((shell->av = my_str_to_wordtab(tmp, ' ')) == NULL ||
      (shell->av[0]) == NULL)
    return (SH_ERR);
  shell->ac = update_argcount(shell->av);
  if ((shell->op_pos = malloc(sizeof(int) * shell->ac)) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR));
  if ((shell->op_pos = update_oppos(shell)) == NULL)
    return (SH_ERR);
  return (SH_OK);
}
