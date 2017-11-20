/*
** is_digit.c for is_digit in /home/onillo_l/rendu/CPE/CPE_2015_BSQ
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Sun Dec 20 19:00:58 2015 Lucas Onillon
** Last update Sun Dec 20 19:03:27 2015 Lucas Onillon
*/

#include "my.h"

int		is_digit(char c)
{
  if (c >= '0' && c <= '9')
    return (0);
  else
    return (-1);
}
