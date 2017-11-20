/*
** builtin_cd.c for cd in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Jun  1 09:21:34 2016 Lucas
** Last update Sun Jun  5 19:25:46 2016 Lucas
*/

#include "shell.h"

int		count_arg(char **cmd)
{
  int		i;

  i = 0;
  while (cmd[i])
    i++;
  return (i);
}

int		handle_old(t_env *env_list)
{
  t_my_bool	check;
  t_env		*tmp;

  check = MY_FALSE;
  tmp = env_list;
  while (tmp)
    {
      if (my_strcmp(tmp->name, "OLDPWD") == 0)
	{
	  check = MY_TRUE;
	  my_putstr(tmp->name);
	  if (chdir(tmp->data) == -1)
	    return (cerr_zero(INT_ERR, NO_FOD, SH_ERR));
	}
      tmp = tmp->next;
    }
  if (check == MY_FALSE)
    my_putstr("bash: cd: « OLDPWD » non défini.\n");
  return (SH_OK);
}

int		handle_newdir(t_env *env_list, t_shell *shell)
{
  t_my_bool	check;

  check = MY_FALSE;
  if (chdir(shell->av[1]) == -1)
    return (fprintf(stderr, "%s: %s\n", shell->av[1], NO_FOD), SH_ERR);
  while (env_list)
    {
      if (my_strcmp(env_list->name, "OLDPWD") == 0)
	{
	  check = MY_TRUE;
	  env_list->data = shell->av[1];
	}
      env_list = env_list->next;
    }
  if (check == MY_FALSE)
    {
      env_list = add_to_env(env_list, "OLDPWD", 1);
      env_list = add_to_env(env_list, getcwd(NULL, 0), 2);
    }
  return (SH_OK);
}

/*
** Handle the cd builtin.
*/
int		builtin_cd(t_shell *shell)
{
  int		ac;

  ac = count_arg(shell->av);
  if (ac == 1)
    {
      while (my_strcmp(shell->env_list->name, "HOME") != 0)
	shell->env_list = shell->env_list->next;
      if (chdir(shell->env_list->data) == -1)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, NO_FOD), SH_ERR);
    }
  else
    {
      if (my_strcmp(shell->av[1], "-") == 0)
	handle_old(shell->env_list);
      else
	handle_newdir(shell->env_list, shell);
    }
  return (SH_OK);
}
