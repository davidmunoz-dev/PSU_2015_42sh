/*
** list_func.c for list_func in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Mon Apr 25 07:11:21 2016 Lucas
** Last update Wed May 11 03:18:31 2016 David Munoz
*/

#include "shell.h"

/*
** Will create a new element and make the basic inits.
*/
t_env			*create_elem(char *data)
{
  t_env			*new_elem;

  if ((new_elem = malloc(sizeof(t_env))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  if ((new_elem = pars_env(data, new_elem)) == NULL)
    return (NULL);
  new_elem->next = NULL;
  new_elem->prev = NULL;
  new_elem->is_actif = MY_TRUE;
  return (new_elem);
}

/*
** Will create a new element at the end of the linked list.
*/
t_env			*add_in_end(t_env *elem, char *data)
{
  t_env			*new_elem;
  t_env			*tmp;

  if ((new_elem = create_elem(data)) == NULL)
    return (NULL);
  if (elem == NULL)
    return (new_elem);
  else
    {
      tmp = elem;
      while (tmp->next != NULL)
	tmp = tmp->next;
      tmp->next = new_elem;
      new_elem->prev = tmp;
    }
  return (elem);
}

/*
** Display the data contained in the linked list in parameter.
*/
void			show_list(t_env *list)
{
  t_env			*tmp;

  tmp = list;
  while (tmp != NULL)
    {
      my_putstr(tmp->name);
      my_putchar('=');
      my_putstr(tmp->data);
      my_putchar('\n');
      tmp = tmp->next;
    }
  return ;
}

/*
** Create a linked list using the 'env' string.
*/
t_env		*init_env(t_env *env_list, char **env)
{
  int		i;

  i = 0;
  while (env[i])
    {
      if ((env_list = add_in_end(env_list, env[i])) == NULL)
	return (NULL);
      i++;
    }
  return (env_list);
}
