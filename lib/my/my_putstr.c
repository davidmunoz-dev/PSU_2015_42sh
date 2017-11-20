/*
** my_putstr.c for putstr in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:34:18 2015 Lucas Onillon
** Last update Mon Jan 18 22:53:08 2016 Lucas Onillon
*/

#include "my.h"

int	my_putstr(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    {
      my_putchar(str[i]);
      i = i + 1;
    }
  return (0);
}
