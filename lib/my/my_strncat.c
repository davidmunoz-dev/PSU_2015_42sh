/*
** my_strncat.c for strncat in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:55:51 2015 Lucas Onillon
** Last update Mon Jan 18 22:57:07 2016 Lucas Onillon
*/

#include "my.h"

char	*my_strncat(char *dest, char *src, int nb)
{
  int   i;
  int   max;

  i = 0;
  max = my_strlen(dest);
  while (src[i] && nb > 0)
    {
      dest[max] = src[i];
      i = i + 1;
      nb = nb - 1;
      max = max + 1;
    }
  dest[max] = '\0';
  return (dest);
}
