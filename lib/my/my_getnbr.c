/*
** my_getnbr.c for getnbr in /home/onillo_l/rendu/Piscine/Piscine_C_J07/lib/my
** 
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
** 
** Started on  Tue Oct  6 09:36:15 2015 Lucas Onillon
** Last update Wed Oct 14 16:21:47 2015 Lucas Onillon
*/

int	my_getnbr(char *str)
{
  int   c;
  long  result;

  result = 0;
  c = (str[0] == '-') ? 1 : 0;
  while (str[c])
    {
      if (str[c] >= '0' && str[c] <= '9')
        result = (result * 10) + (str[c] - '0');
      else
        {
          if (str[0] == '-')
            result *= -1;
          return ((int)result);
        }
      c++;
    }
  if (str[0] == '-')
    result *= -1;
  return ((int)result);
}

