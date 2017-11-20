/*
** is_alpha.c for is_alpha in /home/onillo_l/rendu/CPE/CPE_2015_lemin/lib/my
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Mar 29 11:48:35 2016 Lucas
** Last update Sat Jun  4 19:23:12 2016 Lucas
*/

#include "my.h"

int	is_alpha(char c)
{
  if ((c >= 'a' && c <= 'z') ||
      (c >= 'A' && c <= 'Z'))
    return (1);
  return (0);
}

int	is_num(char c)
{
  if (c >= '0' && c <= '9')
    return (1);
  return (0);
}

int	is_alphanum(char c)
{
  if (is_alpha(c))
    return (1);
  else if (is_num(c))
    return (2);
  return (0);
}
