/*
** parse_line for pars_line in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sun May 29 22:42:01 2016 Lucas
** Last update Sun Jun  5 23:04:36 2016 Lucas
*/

#include "shell.h"

char		**list_to_array(t_env *env_list, char **env)
{
  int           i;
  t_env        *tmp;
  int           size;

  size = i = 0;
  tmp = env_list;
  while (tmp)
    {
      size++;
      tmp = tmp->next;
    }
  if ((env = malloc(sizeof(char *) * (size + 2))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (env_list)
    {
      if ((env[i] = malloc(sizeof(char) * (calc_len(env_list) + 2))) == NULL)
	return (cerr_msg(INT_ERR, MALL_ERR));
      my_strcpy(env[i], env_list->name);
      my_strcat(env[i], "=");
      my_strcat(env[i++], env_list->data);
      env_list = env_list->next;
    }
  env[i] = NULL;
  return (env);
}

int		exec_cmd(t_shell *shell)
{
  int		status;
  pid_t		pid;
  char		**env;

  env = NULL;
  if ((env = list_to_array(shell->env_list, env)) == NULL)
    return (SH_ERR);
  if ((pid = fork()) == SH_ERR)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, FORK_ERR), SH_ERR);
  if (pid == 0)
    {
      if (handle_sig_ending() == SH_ERR)
	return (SH_ERR);
      if (execve(shell->tmp_path, shell->av, env) == SH_ERR)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, EXE_ERR), SH_ERR);
    }
  wait(&status);
  free(env);
  return (SH_OK);
}

int		check_current_cmd(t_shell *shell)
{
  int		i;
  t_my_bool    	current;

  current = MY_FALSE;
  i = 0;
  while (shell->buffer[i])
    {
      if (shell->buffer[i] == '/')
	current = MY_TRUE;
      i++;
    }
  if (current == MY_TRUE)
    {
      if (access(shell->av[0], F_OK | X_OK) == SH_OK)
	{
	  if ((shell->tmp_path = my_strdup(shell->av[0])) == NULL)
	    return (SH_OK);
	  exec_cmd(shell);
	}
    }
  return (SH_ERR);
}

int		parse_line(t_shell *shell)
{
  if (update_cmd(shell) == SH_ERR)
    return (SH_ERR);
  if (no_operator(shell) == SH_OK)
    {
      if ((check_current_cmd(shell) == SH_OK) ||
	  (check_builtin(shell) == SH_OK))
	return (SH_OK);
      if ((find_binary(shell)) == SH_OK)
	{
	  if (exec_cmd(shell) == SH_ERR)
	    return (SH_ERR);
	  return (SH_OK);
	}
    }
  else if (handle_separator(shell) == SH_ERR)
    return (SH_BRK);
  return (SH_OK);
}
