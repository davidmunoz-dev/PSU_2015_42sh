/*
** my_strncmp.c for strncmp in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:46:09 2015 Lucas Onillon
** Last update Thu Jan 21 10:11:25 2016 Lucas
*/

#include "my.h"

int	my_strncmp(char *s1, char *s2, int nb)
{
  int	i;
  int	j;

  i = j = 0;
  while (i < nb && s1[i] && s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}
