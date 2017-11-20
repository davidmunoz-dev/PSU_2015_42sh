/*
** my_printf.c for my_printf in /home/onillo_l/rendu/PSU/PSU_2015_my_printf/src
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Nov  6 02:40:00 2015 Lucas Onillon
** Last update Mon Nov 16 19:15:59 2015 Lucas Onillon
*/

#include "my.h"
#include "my_printf.h"

/*
** Last function called during the my_printf process. It will
** return the number of character printed and free the used
** memory in a proper way.
*/
int		final_printf(t_printf *prtf)
{
  int		count;

  count = prtf->count;
  free(prtf->fl_func);
  free(prtf->types);
  free(prtf);
  return (count);
}

/*
** This function will be called only if the format passed in parameter to the
** my_printf function contain flag call(s). It job is to look in the FLAG_TYPES
** string and refers to the defined pointer to function.
*/
int		handle_flags(const char *format, va_list arg, t_printf *prtf)
{
  int		flag_pos;
  int		i;
  int		count;

  i = 0;
  while (format[i])
    {
      flag_pos = 0;
      if (format[i] == '%')
	{
	  if ((flag_pos = find_flag(format, &i, prtf)) < FLAG_NBR)
	    if (prtf->fl_func[flag_pos](arg, prtf) == PRINTF_ERR)
	      {
		count = final_printf(prtf);
		return (count);
	      }
	}
      else
	{
	  write(1, &format[i], 1);
	  prtf->count++;
	  i++;
	}
    }
  return (count);
}

/*
** Main function of the my_printf, will handle the main
** process to reproduce the behavior of the printf
** function provide by the system.
*/
int		my_printf(const char *format, ...)
{
  int		count;
  va_list	arg;
  t_printf	*prtf;

  if (format == NULL)
    return (0);
  if ((prtf = malloc(sizeof(t_printf))) == NULL)
    return (cerr_zero(ERR_INTERNAL, ERR_MALLOC, 0));
  if ((prtf->types = my_strdup(FLAG_TYPES)) == NULL)
    return (cerr_zero(ERR_INTERNAL, ERR_UNDEF, PRINTF_ERR));
  prtf->count = 0;
  va_start(arg, format);
  init_ptr_func(prtf);
  if (check_flag_instance(format) == 0)
     return (my_const_strlen(format));
  va_start(arg, format);
  count = handle_flags(format, arg, prtf);
  va_end(arg);
  return (count);
}
