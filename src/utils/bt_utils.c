/*
** bt_utils.c for bt_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Jun  1 15:07:12 2016 Lucas
** Last update Thu Jun  2 15:39:03 2016 Lucas
*/

#include "shell.h"

/*
** Create a new element to the env linked list using the name and the data param
** of the setenv command.
*/
t_env		*update_env_var(char *data, int status)
{
  t_env        *new_elem;

  if ((new_elem = malloc(sizeof(t_env))) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
  if (status == 1)
    {
      new_elem->name = data;
      new_elem->data = NULL;
    }
  if (status == 2)
    new_elem->data = data;
  new_elem->next = NULL;
  new_elem->prev = NULL;
  return (new_elem);
}
