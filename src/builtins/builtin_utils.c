/*
** builtin_utils.c for builtin_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Tue May 31 09:48:59 2016 Lucas
** Last update Sat Jun  4 15:35:24 2016 Lucas
*/

#include "shell.h"

int		check_builtin(t_shell *shell)
{
  int		i;

  i = 0;
  while (i < BT_NB)
    {
      if (my_strcmp(shell->bt_array[i], shell->av[0]) == SH_OK)
	{
	  shell->bt_func[i](shell);
	  return (SH_OK);
	}
      i++;
    }
  return (SH_ERR);
}
