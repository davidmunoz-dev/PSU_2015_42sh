/*
** cerr_err.c for cerr_err in /home/onillo_l/rendu/Piscine/Piscine_C_J10/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Oct  9 14:53:32 2015 Lucas Onillon
** Last update Sat Dec 19 10:05:27 2015 Lucas Onillon
*/

#include "my.h"

int	cerr_zero(char *log, char *info, int status)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (status);
}

void	*cerr_msg(char *log, char *info)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (NULL);
}

char	*cerr_null(char *log, char *info)
{
  write(2, log, my_strlen(log));
  write(2, info, my_strlen(info));
  return (NULL);
}
