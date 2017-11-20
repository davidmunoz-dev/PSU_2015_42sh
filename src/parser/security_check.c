/*
** security_check.c for security_check in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sun Jun  5 15:11:30 2016 Lucas
** Last update Sun Jun  5 22:35:44 2016 Lucas
*/

#include "shell.h"

int		multi_pipe(t_shell *shell)
{
  int		i;
  int		check;

  i = check = 0;
  while (shell->op_pos[i])
    {
      if (shell->op_pos[i] == '4')
	check++;
      i++;
    }
  if (check > 1)
    return (SH_OK);
  return (SH_ERR);
}

int		is_valid_command(t_shell *shell, int pos)
{
  if (!(shell->op_pos[pos - 1]) && ((shell->op_pos[pos] != '1') ||
				     (shell->op_pos[pos] != '3')))
    return (fprintf(stderr, "%s\n", NULL_CMD), SH_BRK);
  else if (!(shell->op_pos[pos + 1] && (shell->op_pos[pos] == '3')))
    return (fprintf(stderr, "%s\n", NULL_CMD), SH_BRK);
  return (SH_OK);
}
