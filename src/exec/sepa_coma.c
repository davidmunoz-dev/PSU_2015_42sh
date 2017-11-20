/*
** sepa_coma.c for sepa_coma in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 20:03:39 2016 Lucas
** Last update Sun Jun  5 22:36:24 2016 Lucas
*/

#include "shell.h"

int		count_argcoma(t_shell *shell)
{
  int		i;
  int		nb;

  nb = i = 0;
  while (shell->op_pos[i])
    {
      if (shell->op_pos[i] == '0')
	nb++;
      i++;
    }
  return (nb);
}

char		**get_cmd(t_shell *shell)
{
  int		i;
  int		nb;
  char		**arg;

  i = 0;
  nb = count_argcoma(shell);
  if ((arg = malloc(sizeof(char *) * (nb + 1))) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
  while (i < 2)
    {
      if ((arg[i] = my_strdup(shell->av[i])) == NULL)
	    return (NULL);
      i++;
    }
  return (arg);
}

int		exec_coma(t_shell *shell)
{
  char		**av;
  int		status;
  pid_t		pid;
  char		**env;

  env = NULL;
  if ((av = get_cmd(shell)) == NULL)
    return (SH_ERR);
  if ((env = list_to_array(shell->env_list, env)) == NULL)
    return (SH_ERR);
  if ((pid = fork()) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, FORK_ERR), SH_ERR);
  if (pid == 0)
    {
      if (handle_sig_ending() == SH_ERR)
	return (SH_ERR);
      if (execve(shell->tmp_path, av, env) == SH_ERR)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, EXE_ERR), SH_ERR);
    }
  wait(&status);
  free(env);
  return (SH_OK);
}

int		sepa_coma(t_shell *shell, int pos)
{
  (void)pos;
  printf("; not handle by the shell.\n");
  return (SH_OK);
  if ((check_current_cmd(shell) == SH_OK) ||
      (check_builtin(shell) == SH_OK))
    return (SH_OK);
  if ((find_binary(shell)) == SH_OK)
    {
      if (exec_coma(shell) == SH_ERR)
	return (SH_ERR);
      return (SH_OK);
    }
  return (SH_OK);
}
