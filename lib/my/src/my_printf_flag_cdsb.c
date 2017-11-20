/*
** my_printf_flag_cdsb.c for cdsb in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Tue Nov 10 16:51:46 2015 Lucas Onillon
** Last update Mon Nov 16 21:30:35 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

/*
** Handle the '%c' flag case.
*/
int		my_flag_c(va_list arg, t_printf *prtf)
{
  unsigned int	c;

  c = (unsigned int)va_arg(arg, int);
  my_put_const_char(c, prtf);
  return (PRINTF_OK);
}

/*
** Will put the number in the standard output
*/
int		my_flag_d_next(int i, t_printf *prtf)
{
  if (i <= -10)
    my_flag_d_next(i / 10, prtf);
  my_put_const_char((i % 10) - '0', prtf);
  return (PRINTF_OK);
}

/*
** Handle the '%d' flag case.
*/
int		my_flag_d(va_list arg, t_printf *prtf)
{
  int		i;

  i = va_arg(arg, int);
  if (i > 0)
    i = -i;
  else
    my_put_const_char('-', prtf);
  my_flag_d_next(i, prtf);
  return (PRINTF_OK);
}

/*
** Handle the '%s' flag case.
*/
int		my_flag_s(va_list arg, t_printf *prtf)
{
  const char	*str;

  if ((str = va_arg(arg, const char *)) == NULL)
    str = N_FORMAT;
  while (*str)
    {
      my_put_const_char(*str, prtf);
      *str++;
    }
  return (PRINTF_OK);
}

/*
** Handle the '%i' case, in a lazy way but at least in works.
*/
int		my_flag_i(va_list arg, t_printf *prtf)
{
  return (my_flag_d(arg, prtf));
}
