/*
** my_strcmp.c for strcmp in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:45:20 2015 Lucas Onillon
** Last update Mon Apr 11 17:22:37 2016 Lucas
*/

#include "my.h"

int		my_strcmp(char *s1, char *s2)
{
  int		i;

  i = 0;
  if (my_strlen(s1) != my_strlen(s2))
    return (1);
  while (s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  if (s1[i] && s2[i])
    return (1);
  else
    return (0);
}
