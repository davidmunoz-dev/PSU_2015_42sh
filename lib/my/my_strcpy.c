/*
** my_strcpy.c for strcpy in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Oct  6 09:41:30 2015 Lucas Onillon
** Last update Wed Mar  9 00:11:18 2016 Lucas
*/

#include <stdio.h>
#include "my.h"

char	*my_concat(char *s1, char *s2)
{
  char	*result;

  if ((result = malloc(my_strlen(s1) + my_strlen(s2) + 1)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  my_strcpy(result, s1);
  result = my_strcat(result, s2);
  return (result);
}

char	*my_strcpy(char *dest, char *src)
{
  int	i;

  i = 0;
  while (src[i])
    {
      dest[i] = src[i];
      i++;
    }
  dest[i] = '\0';
  return (dest);
}
