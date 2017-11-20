/*
** my_printf_flags_utils.c for printf_flags_utils in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Nov  6 18:17:15 2015 Lucas Onillon
** Last update Mon Nov 16 23:41:00 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

/*
** Basic function used to check if the current character contained in the format
** is null or not.
*/
int		check_null(const char *format, int *i, int flag_char)
{
  if (format[*i + flag_char] == 0)
    {
      *i = *i + flag_char;
      return (FLAG_NBR + 1);
    }
  else
    return (PRINTF_OK);
}

/*
** Function that will handle the eventual spaces and tabulations that can
** be found in the specified format. In this case, the nw_char stands for
** the non-wanted char.
*/
int		flag_through_spaces(const char *format, int i, t_printf *prtf)
{
  int		nw_char;

  nw_char = 0;
  my_put_const_char('%', prtf);
  if (format[i + 1] == ' ')
    {
      my_put_const_char(' ', prtf);
      while (format[i + 1 + nw_char++] == ' ');
      return (nw_char);
    }
  else
    return (1);
  return (PRINTF_OK);
}

/*
** Will try to find any flag and return the corresponding number in the pointer
** to function tab by scrolling the specified format.
*/
int		find_flag(const char *format, int *i, t_printf *prtf)
{
  int		flag_char;
  int		flag_pos;

  flag_pos = 0;
  flag_char = 1;
  while (format[*i + flag_char] == ' ')
    flag_char++;
  if ((check_null(format, i, flag_char)) == PRINTF_ERR)
    return (FLAG_NBR + 1);
  else
    {
      while (prtf->types[flag_pos] != format[*i + flag_char]
	     && prtf->types[flag_pos])
	flag_pos++;
      if (flag_pos < FLAG_NBR)
	{
	  *i += flag_char + 1;
	  return (flag_pos);
	}
      else
	*i += flag_through_spaces(format, *i, prtf);
    }
  return (FLAG_NBR + 1);
}
