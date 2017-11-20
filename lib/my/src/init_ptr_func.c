/*
** init_ptr_func.c for init_ptr_func in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Mon Nov  9 00:05:16 2015 Lucas Onillon
** Last update Mon Nov 16 21:40:24 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

/*
** Dirty way to init a tab to pointer to function,
** but at least it works, wich is nice.
*/
int		init_ptr_func(t_printf *prtf)
{
  prtf->fl_func[0] = (flag_func)&my_flag_c;
  prtf->fl_func[1] = (flag_func)&my_flag_d;
  prtf->fl_func[2] = (flag_func)&my_flag_s;
  prtf->fl_func[3] = (flag_func)&my_flag_i;
  prtf->fl_func[4] = (flag_func)&my_flag_big_s;
  prtf->fl_func[5] = (flag_func)&my_flag_f;
  prtf->fl_func[6] = (flag_func)&my_flag_n;
  prtf->fl_func[7] = NULL;
  return (PRINTF_OK);
}
