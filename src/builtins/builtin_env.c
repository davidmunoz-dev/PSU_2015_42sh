/*
** builtin_env.c for builtin_env in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/builtins
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 09:17:00 2016 Lucas
** Last update Tue May 10 20:50:12 2016 Munoz David
*/

#include "shell.h"

/*
** Principal function of the env
** who display the environment
*/
int		builtin_env(t_shell *shell)
{
  t_env		*temp;

  temp = shell->env_list;
  while (temp && temp->name)
    {
      if (temp->is_actif == MY_TRUE)
	printf("%s=%s\n", temp->name, temp->data);
      temp = temp->next;
    }
  free(temp);
  return (SH_OK);
}
