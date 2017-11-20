/*
** my_putchar.c for putchar in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:25:47 2015 Lucas Onillon
** Last update Mon Jan 18 22:52:20 2016 Lucas Onillon
*/

#include "my.h"

void	my_putchar(char c)
{
  write(1, &c, 1);
}
