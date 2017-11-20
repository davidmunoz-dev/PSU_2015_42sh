/*
** env_utils.c for env_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 06:33:53 2016 Lucas
** Last update Thu Jun  2 15:39:43 2016 Lucas
*/

#include "shell.h"

/*
** Add a new variable to the current env.
*/
t_env		*add_to_env(t_env *elem, char *data, int status)
{
  t_env        *new_elem;
  t_env        *tmp;

  if ((new_elem = update_env_var(data, status)) == NULL)
    return (NULL);
  tmp = elem;
  if (elem == NULL)
    return (new_elem);
  else
    {
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      new_elem->prev = tmp;
    }
  return (elem);
}

/*
** Go through the env linked list to try to find the PATH
** and then copy it a string array.
*/
char		**find_path(t_shell *shell, t_env *tmpenv)
{
  char		*tmp;
  int		i;

  i = 0;
  tmpenv = shell->env_list;
  if (shell->env_list == NULL)
    return (NULL);
  while (tmpenv && my_strcmp(tmpenv->name, "PATH") != SH_OK)
    if ((tmpenv = tmpenv->next) == NULL)
      {
	shell->path = NULL;
	return (shell->path);
      }
  if ((tmp = malloc(my_strlen(tmpenv->data) + 1)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (tmpenv->data[i])
    {
      tmp[i] = tmpenv->data[i];
      i++;
    }
  tmp[i] = '\0';
  if ((shell->path = my_str_to_wordtab(tmp, ':')) == NULL)
    return (NULL);
  free(tmp);
  return (shell->path);
}

/*
** Search the logname in the environment
** and add it at the prompt
*/
char		*get_logname(t_shell *shell, char *var)
{
  t_env		*temp;
  int		i;

  if (shell->env_list == NULL)
    return (NULL);
  temp = shell->env_list;
  while (temp && my_strcmp(temp->name, var) != SH_OK)
    if ((temp = temp->next) == NULL)
      return (NULL);
  if ((shell->logname = malloc(sizeof(temp->data) + 1)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  i = -1;
  while (temp->data[++i])
    shell->logname[i] = temp->data[i];
  shell->logname[i] = '\0';
  return (shell->logname);
}

/*
** Calc the current environment variable name.
*/
int		find_name_size(char *str)
{
  int		i;

  i = 0;
  while (str[i] && str[i] != '=')
    i++;
  return (i);
}

/*
** Parse the current environment variable.
*/
t_env		*pars_env(char *data, t_env *elem)
{
  int		j;
  int		i;
  int		n_size;

  i = j = 0;
  n_size = find_name_size(data);
  if (((elem->name = malloc(sizeof(char) * n_size + 1)) ==  NULL) ||
      (elem->data = malloc(sizeof(char) * (my_strlen(data) - n_size) + 1))
      == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (data[i] && data[i] != '=')
    {
      elem->name[i] = data[i];
      i++;
    }
  elem->name[i] = '\0';
  i++;
  while (data[i])
    {
      elem->data[j] = data[i];
      j++;
      i++;
    }
  elem->data[j] = '\0';
  return (elem);
}
