/*
** rafter_left.c for rafter_left in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 18:03:57 2016 Lucas
** Last update Sun Jun  5 21:35:56 2016 David Munoz
*/

#include "shell.h"

int		sepa_rafter_left(t_shell *shell, int pos)
{
  int	status;
  char	**env;
  char	**new_av;
  pid_t	pid;

  env = NULL;
  if ((env = list_to_array(shell->env_list, env)) == NULL)
    return (SH_ERR);
  if (find_binary(shell) == SH_OK)
    {
      if ((new_av = pars_av(shell->av, pos)) == NULL)
	return (SH_ERR);
      if ((pid = fork()) == SH_ERR)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, FORK_ERR), SH_ERR);
      if (pid == 0)
	{
	  if (execve(shell->tmp_path, new_av, env) == SH_ERR)
	    return (fprintf(stderr, "%s: %s\n", INT_ERR, EXE_ERR), SH_ERR);
	}
    }
  wait(&status);
  free(env);
  return (SH_OK);
}
