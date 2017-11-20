/*
** my_printf.h for my_printf in /home/onillo_l/rendu/PSU/PSU_2015_my_printf
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Nov  6 01:58:28 2015 Lucas Onillon
** Last update Mon Nov 16 23:15:03 2015 Lucas Onillon
*/

#ifndef MY_PRINTF_H_
# define MY_PRINTF_H_

/*
** Include system.
*/
# include <stdio.h>
# include <stdlib.h>
# include <stdarg.h>

/*
** Macro definitions.
*/
# define	PRINTF_ERR	-1
# define	PRINTF_OK	0
# define	FLAG_TYPES	"cdsiSfn"
# define	FLAG_NBR	7
# define	N_FORMAT	"(null)"

/*
** Error macro definitions.
*/
# define	ERR_INTERNAL	"Internal error: "
# define	ERR_SYNTAX	"Syntax error: "
# define	ERR_MALLOC	"malloc failed to allocate the wanted memory\n"
# define	ERR_UNDEF	"Something unexpected happened, please refer to\
				 the README file for more informations\n"

/*
** Pointer to function prototype that will be used to handle the different flags
**                          passed in parameter.
*/
typedef int	(*flag_func)(va_list arg, void *prtf);


/*
** Structure definitions.
*/
typedef struct	s_printf
{
  char		*types;
  int		count;
  flag_func	fl_func[FLAG_NBR + 1];
}		t_printf;

/*
** In the section below, you'll find all the function prototypes used by
**                        the my_printf project.
*/

/*
** src/my_printf.c
*/
int		my_printf(const char *format, ...);
int		handle_flags(const char *format, va_list arg, t_printf *prtf);
int		final_printf(t_printf *prtf);

/*
** src/my_printf_flag_utils.c
*/
int		find_flag(const char *format, int *i, t_printf *prtf);
int		check_null(const char *format, int *i, int flag_char);
int		flag_through_spaces(const char *format, int i, t_printf *prtf);

/*
** src/my_printf_flag_cdsb.c
*/
int		my_flag_c(va_list arg, t_printf *prtf);
int		my_flag_d(va_list arg, t_printf *prtf);
int		my_flag_s(va_list arg, t_printf *prtf);
int		my_flag_i(va_list arg, t_printf *prtf);

/*
** src/init_ptr_func.c
*/
int		init_ptr_func(t_printf *prtf);

/*
** src/my_printf_utils.c
*/
int		check_flag_instance(const char *format);
void		my_put_const_str(const char *format, t_printf *prtf);
int		my_const_strlen(const char *str);
void		my_put_const_char(const char c, t_printf *prtf);
void		my_put_str_spec(const char *format);

/*
** src/my_printf_flag_fns.c
*/
int		my_flag_big_s(t_printf *prtf, va_list arg);
int		my_flag_f(t_printf *prtf, va_list arg);
int		my_flag_n(t_printf *prtf, va_list arg);

#endif	/* !MY_PRINTF_H_ */
