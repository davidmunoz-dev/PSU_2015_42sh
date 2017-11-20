/*
** my_strstr.c for strstr in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:44:38 2015 Lucas Onillon
** Last update Thu Mar  3 00:38:57 2016 Lucas
*/

#include "my.h"

int	my_strstr(char *str, char *to_find)
{
  int	i;
  int	j;

  i = j = 0;
  while (str[i])
    {
      if (str[i] == to_find[j])
	j++;
      else
	j = 0;
      i++;
    }
  if (j != my_strlen(to_find))
    return (-1);
  else
    return (0);
}
