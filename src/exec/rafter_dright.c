/*
** rafter_dright.c for rafter_dright in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 18:04:33 2016 Lucas
** Last update Sun Jun  5 21:35:44 2016 David Munoz
*/

#include "shell.h"

int		double_right_redirection(t_shell *shell, int pos, char **env)
{
  char  **new_av;
  pid_t pid;
  int   i;
  int   fd;

  if ((new_av = pars_to_redi(shell->av, pos)) == NULL)
    return (SH_ERR);
  i = 0;
  while (my_strcmp(shell->av[i], ">>") != 0)
    i++;
  i++;
  fd = open(shell->av[i], O_CREAT | O_APPEND | O_WRONLY, 0644);
  if ((pid = fork()) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, FORK_ERR), SH_ERR);
  if (pid == 0)
    {
      if (dup2(fd, 1) == SH_ERR)
        return (fprintf(stderr, "%s: %s\n", INT_ERR, DUP_ERR), SH_ERR);
      if (execve(shell->tmp_path, new_av, env) == SH_ERR)
        return (fprintf(stderr, "%s: %s\n", INT_ERR, EXE_ERR), SH_ERR);
    }
  return (SH_OK);
}


int		sepa_rafter_dright(t_shell *shell, int pos)
{
  char  **env;
  int   status;

  env = NULL;
  if ((env = list_to_array(shell->env_list, env)) == NULL)
    return (SH_ERR);
  if (find_binary(shell) == SH_OK)
    {
      if ((double_right_redirection(shell, pos, env)) == SH_ERR)
        return (SH_ERR);
    }
  wait(&status);
  free(env);
  return (SH_OK);
}
