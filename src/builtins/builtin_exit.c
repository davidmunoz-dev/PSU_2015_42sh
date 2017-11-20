/*
** builtin_exit.c for builtin_exit in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/builtins
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 09:19:21 2016 Lucas
** Last update Sun Jun  5 20:53:42 2016 Lucas
*/

#include "shell.h"

void		free_array(t_shell *shell)
{
  int		i;

  i = 0;
  while (shell->bt_array[i])
    i++;
  while (i > 0)
    {
      free(shell->bt_array[i]);
      i--;
    }
  i = 0;
  while (shell->sepa_array[i])
    i++;
  while (i > 0)
    {
      free(shell->sepa_array[i]);
      i--;
    }
}

void		free_data(t_shell *shell)
{
  int		i;

  i = 0;
  while (shell->path[i])
    {
      free(shell->path[i]);
      i++;
    }
  free_array(shell);
  free(shell->path);
}

int		builtin_exit(t_shell *shell)
{
  int		status;

  printf("exit\n");
  status = shell->status;
  if (shell->av && shell->av[1])
    status = my_getnbr(shell->av[1]);
  shell->is_running = MY_FALSE;
  free_data(shell);
  return (status);
}
