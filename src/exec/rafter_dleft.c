/*
** rafter_dleft.c for rafter_dleft in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 18:03:31 2016 Lucas
** Last update Sun Jun  5 21:42:13 2016 David Munoz
*/

#include "shell.h"

int	exec_double_left(t_shell *shell, char **new_av,
                         char **env, char *buffer)
{
  pid_t pid;
  int   pipefd[2];

  if (pipe(pipefd) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, WRITE_ERR), SH_ERR);
  if (write(pipefd[1], buffer, my_strlen(buffer) + 1) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, PIPE_ERR), SH_ERR);
  if ((pid = fork()) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, FORK_ERR), SH_ERR);
  if (pid == 0)
    {
      close(pipefd[1]);
      close(0);
      if (dup(pipefd[0]) == SH_ERR)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, DUP_ERR), SH_ERR);
      if (execve(shell->tmp_path, new_av, env) == SH_ERR)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, EXE_ERR), SH_ERR);
    }
  close(pipefd[0]);
  close(pipefd[1]);
  return (0);
}



int		double_left_redirection(t_shell *shell, int pos, char **env)
{
  char  *line;
  char  *buffer;
  char  **new_av;
  int   i;

  if ((new_av = pars_to_redi(shell->av, pos)) == NULL)
    return (SH_ERR);
  i = 0;
  while (my_strcmp(shell->av[i], "<<") != 0)
    i++;
  i++;
  if ((buffer = malloc(4000)) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), SH_ERR);
  memset(buffer, 0, 4000);
  my_putstr("? ");
  while ((line = get_next_line(0))
         && my_strcmp(line, shell->av[i]) != 0)
    {
      my_putstr("? ");
      my_strcat(line, "\n");
      my_strcat(buffer, line);
    }
  if (exec_double_left(shell, new_av, env, buffer) == SH_ERR)
    return (SH_ERR);
  return (SH_OK);
}

int		sepa_rafter_dleft(t_shell *shell, int pos)
{
  char  **env;
  int   status;

  env = NULL;
  if ((env = list_to_array(shell->env_list, env)) == NULL)
    return (SH_ERR);
  if (find_binary(shell) == SH_OK)
    {
      if ((double_left_redirection(shell, pos, env)) == SH_ERR)
        return (SH_ERR);
    }
  wait(&status);
  free(env);
  return (SH_OK);
}
