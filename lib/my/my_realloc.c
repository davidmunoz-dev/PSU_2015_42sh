/*
** my_realloc.c for my_realloc in /home/onillo_l/rendu/CPE/CPE_2015_BSQ/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Dec 19 09:38:16 2015 Lucas Onillon
** Last update Sat Dec 19 09:41:53 2015 Lucas Onillon
*/

#include "my.h"

/*
** Will copy the content of the recup string passed in parameter
** in a new string wich as already been allocate in the memory dynamically.
*/
char		*my_realloc(char *recup, int ret)
{
  char		*new_str;
  int		i;

  i = 0;
  if ((new_str = malloc(sizeof(char) * ret + my_strlen(recup) + 1)) == NULL)
    return (cerr_msg("Internal error: ", "malloc failed in realloc\n"));
  while (recup[i])
    {
      new_str[i] = recup[i];
      i++;
    }
  new_str[i] = '\0';
  if (my_strcmp(recup, "") != 0)
    free(recup);
  return (new_str);
}
