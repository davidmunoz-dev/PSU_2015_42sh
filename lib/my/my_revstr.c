/*
** my_revstr.c for revstr in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:44:04 2015 Lucas Onillon
** Last update Mon Jan 18 22:53:49 2016 Lucas Onillon
*/

#include "my.h"

char	*my_revstr(char *src)
{
  int   i;
  char  *tmp1;
  char  *tmp2;
  int   tmp3;

  i = my_strlen(src);
  tmp1 = src;
  tmp2 = tmp1 + (i - 1);
  while (tmp2 > tmp1)
    {
      tmp3 = *tmp1;
      *tmp1 = *tmp2;
      *tmp2 = tmp3;
      tmp1 = tmp1 + 1;
      tmp2 = tmp2 - 1;
    }
  return (src);
}
