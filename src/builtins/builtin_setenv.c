/*
** builtin_setenv.c for  in /PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed May  4 13:07:42 2016 David Munoz
** Last update Mon May 30 15:39:18 2016 David Munoz
*/

#include "shell.h"

/*
** Count the number of paramter enter after "setenv"
*/
int		env_param_counter(t_shell *shell, char **cmd_tab)
{
  int		i;

  i = 0;
  while (cmd_tab[i])
    i++;
  if (i == 1)
    {
      builtin_env(shell);
      return (SH_ERR);
    }
  if (i > 3)
    return (cerr_zero(SETENV, MUCH_ARG_ERR, SH_ERR));
  return (i);
}

/*
**	Check if the name (first arg) of setenv already exist
*/
int		check_already_exist(t_shell *shell, char **data)
{
  t_env		*temp;

  temp = shell->env_list;
  while (temp)
    {
      if (my_strcmp(data[1], temp->name) == 0)
        temp->is_actif = MY_FALSE;
      temp=temp->next;
    }
  free(temp);
  return (SH_OK);
}

/*
** Create a new_elem for the new value of setenv
*/
t_env		*create_env_var(char **data, int i)
{
  t_env		*new_elem;

  if ((new_elem = malloc(sizeof(t_env))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  if (i == 1)
    {
      new_elem->name = data[1];
      new_elem->is_actif = MY_TRUE;
      new_elem->data = "\0";
    }
  else if (i == 2)
    {
      new_elem->name = data[1];
      new_elem->data = data[2];
      new_elem->is_actif = MY_TRUE;
    }
  new_elem->next = NULL;
  new_elem->prev = NULL;
  return (new_elem);
}

/*
** Add the new value to the environment
*/
t_env		*add_env(t_env *env_list, char **cmd, int i)
{
  t_env		*temp;
  t_env		*new_elem;

  if ((new_elem = create_env_var(cmd, i)) == NULL)
    return (NULL);
  temp = env_list;
  if (env_list == NULL)
    return (new_elem);
  else
    {
      while (temp->next != NULL)
        temp = temp->next;
      temp->next = new_elem;
      new_elem->prev = temp;
    }
  return (env_list);
}


/*
** Principal function of the setenv builtin
*/
int		builtin_setenv(t_shell *shell)
{
  char          **cmd_tab;
  int		argc;

  if ((cmd_tab = my_str_to_wordtab(shell->buffer, ' ')) == NULL)
    return (SH_ERR);
  if ((argc = env_param_counter(shell, cmd_tab)) == SH_ERR)
    return (SH_ERR);
  argc--;
  check_already_exist(shell, cmd_tab);
  if ((shell->env_list = add_env(shell->env_list, cmd_tab, argc)) == NULL)
    return (SH_ERR);
  return (SH_OK);
}
