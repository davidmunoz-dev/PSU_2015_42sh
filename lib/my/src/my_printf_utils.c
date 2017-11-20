/*
** my_printf_utils.c for utils in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Nov  6 01:57:42 2015 Lucas Onillon
** Last update Mon Nov 16 23:14:34 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

/*
** Check if a flag is called in the string passed to my_printf.
*/
int		check_flag_instance(const char *format)
{
  int		i;
  int		check;

  i = check = 0;
  while (format[i])
    {
      if (format[i] == '%')
	check++;
      i++;
    }
  if (check == 0)
    {
      my_put_str_spec(format);
      return (0);
    }
  else
    return (check);
}

/*
** Function used to return the number of character in a 'const string'.
*/
int		my_const_strlen(const char *str)
{
  int		i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

/*
** Version of the my_putchar working with const char as parameter.
*/
void		my_put_const_char(char c, t_printf *prtf)
{
  write(1, &c, 1);
  prtf->count++;
  return ;
}

/*
** This function had the same behavior as the my_putstr function,
** concept for 'const string'.
*/
void		my_put_const_str(const char *format, t_printf *prtf)
{
  int		i;

  i = 0;
  while (format[i])
    {
      write(1, &format[i], 1);
      prtf->count++;
      i++;
    }
  return ;
}

/*
** Just a putstr for const char type, no big deal.
*/
void		my_put_str_spec(const char *format)
{
  int		i;

  i = 0;
  while (format[i])
    {
      write(1, &format[i], 1);
      i++;
    }
  return ;
}
