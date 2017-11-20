/*
** handle_separator.c for handle_ope in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sun Jun  5 12:44:10 2016 Lucas
** Last update Sun Jun  5 22:01:22 2016 Lucas
*/

#include "shell.h"

int		update_sepa(t_shell *shell, int pos)
{
  if (shell->op_pos[pos])
    shell->op_pos[pos] = '0';
  return (SH_OK);
}

int		handle_separator(t_shell *shell)
{
  int		i;
  int		pos;
  int		level;

  level = pos = i = 0;
  pos = get_max_pos(shell);
  level = shell->op_pos[pos] - 48;
  if (multi_pipe(shell) == SH_OK)
    return (printf("%s\n", NULL_CMD), SH_BRK);
  while (no_operator(shell) != SH_OK)
    {
      pos = get_max_pos(shell);
      level = shell->op_pos[pos] - 48;
      if (is_valid_command(shell, pos) != SH_OK)
	return (SH_ERR);
      shell->sepa_func[level - 1](shell, pos);
      update_sepa(shell, pos);
      i++;
    }
  return (SH_OK);
}

int		get_max_pos(t_shell *shell)
{
  int		i;
  int		pos;
  int		max;
  int		tmp;

  i = pos = max = tmp = 0;
  while (shell->op_pos[i])
    {
      tmp = shell->op_pos[i] - 48;
      if (tmp > max)
	{
	  max = tmp;
	  tmp = 0;
	}
      i++;
    }
  i = 0;
  while (shell->op_pos[i] - 48 != max)
    i++;
  return (i);
}
