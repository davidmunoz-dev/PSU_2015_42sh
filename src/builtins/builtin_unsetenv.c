/*
** builtin_env2.c for builtin_env2 in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/builtins
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 09:16:45 2016 Lucas
** Last update Mon May 30 16:05:30 2016 David Munoz
*/

#include "shell.h"

/*
** Principal function of the unsetenv builtin
** it turn off the element of the env to won't be displayed
*/
int		builtin_unsetenv(t_shell *shell)
{
  char		**cmd_tab;
  t_env		*temp;

  temp = shell->env_list;
  if ((cmd_tab = my_str_to_wordtab(shell->buffer, ' ')) == NULL)
    return (SH_ERR);
  while (temp)
    {
      if (cmd_tab[1] == NULL)
	return (cerr_zero("unsetenv: ", FEW_ARG_ERR, SH_ERR));
      else if (cmd_tab[2] != NULL)
	return (cerr_zero("unsetenv: ", MUCH_ARG_ERR, SH_ERR));
      if (my_strcmp(cmd_tab[1], temp->name) == 0)
	temp->is_actif = MY_FALSE;
      temp=temp->next;
    }
  return (SH_OK);
}
