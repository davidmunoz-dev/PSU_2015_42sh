/*
** history.c for history in /home/colett_j/rendu/minishell/PSU_2015_42sh/src
**
** Made by Jean-baptiste Colette
** Login   <collet_j@epitech.net>
**
** Started on  Wed Apr 27 12:05:35 2016 Jean-baptiste Colette
** Last update Thu Jun  2 15:37:57 2016 Lucas
*/

#include "shell.h"

t_history		*list_add(t_history *elem, char *data)
{
  t_history                *new_elem;
  t_history                *tmp;

  if ((new_elem = create_elem(data)) == NULL)
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

void		show_history(t_history *history)
{
  t_history	*tmp;

  tmp = history;
  while (tmp->next)
    {
      my_printf("%s\n", tmp->data);
      tmp = tmp->next;
    }
  return ;
}

t_history	init_history(t_history *history, char *str)
{
  if ((history = list_add(history, str)) == NULL)
    my_putstr("problem with list");
  return (t_history);
}
