/*
** exec.c for exec in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Tue May 31 11:22:25 2016 Lucas
** Last update Sat Jun  4 15:35:53 2016 Lucas
*/

#include "shell.h"

char		*correct_pathname(char *tmp, char *path, char *cmd)
{
  int           i;
  int           j;

  i = j = 0;
  if ((tmp = malloc(my_strlen(path) + (my_strlen(cmd)) + 3)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (path[i])
    {
      tmp[i] = path[i];
      i++;
    }
  tmp[i] = '/';
  i++;
  tmp[i] = '\0';
  while (cmd[j])
    {
      tmp[i] = cmd[j];
      i++;
      j++;
    }
  tmp[i] = '\0';
  return (tmp);
}


int		find_binary(t_shell *shell)
{
  int		i;

  i = 0;
  while (shell->path[i])
    {
      if ((shell->tmp_path = correct_pathname(shell->tmp_path, shell->path[i],
					      shell->av[0])) == NULL)
	return (SH_ERR);
      if (access(shell->tmp_path, F_OK | X_OK) == SH_OK)
	return (SH_OK);
      i++;
    }
  return (SH_ERR);
}
