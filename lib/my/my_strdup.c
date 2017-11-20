/*
** my_strdup.c for strdup in /home/onillo_l/rendu/Piscine/Piscine_C_J08/ex_01
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Oct  7 09:42:11 2015 Lucas Onillon
** Last update Mon Jan 18 23:00:12 2016 Lucas Onillon
*/

#include "my.h"

char	*my_strdup(char *src)
{
  int	i;
  int	max;
  char	*dup;

  i = 0;
  if (src == NULL)
    return (NULL);
  max = my_strlen(src);
  if ((dup = malloc(max + 1)) == NULL)
    return (NULL);
  while (i < max)
    {
      dup[i] = src[i];
      i++;
    }
  dup[i] = 0;
  return (dup);
}
