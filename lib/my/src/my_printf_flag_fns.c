/*
** my_printf_flag_fns.c for fns in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Mon Nov 16 21:35:32 2015 Lucas Onillon
** Last update Mon Nov 16 23:19:59 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

int		my_flag_big_s(t_printf *prtf, va_list arg)
{
  return (PRINTF_OK);
}

int		my_flag_f(t_printf *prtf, va_list arg)
{
  return (PRINTF_OK);
}

/*
** Handle the '%n' flag.
*/
int		my_flag_n(t_printf *prtf, va_list arg)
{
  int		*i;

  i = va_arg(arg, int *);
  *i = prtf->count;
  return (PRINTF_OK);
}
