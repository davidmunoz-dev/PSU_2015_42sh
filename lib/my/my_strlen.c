/*
** my_strlen.c for strlen in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:35:26 2015 Lucas Onillon
** Last update Mon Jan 18 22:53:30 2016 Lucas Onillon
*/

#include "my.h"

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i = i + 1;
  return (i);
}
