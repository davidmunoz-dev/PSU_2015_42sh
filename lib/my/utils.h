/*
** utils.h for utils.h in /home/onillo_l/rendu/PSU/PSU_2015_minishell1/lib/my
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Jan  8 16:44:52 2016 Lucas Onillon
** Last update Thu May 12 17:01:47 2016 Lucas
*/

#ifndef	UTILS_H_
# define UTILS_H_

typedef char	t_my_bool;

/*
** Std Macro definitions.
*/
# define	MY_TRUE		1
# define	MY_FALSE	0

/*
** Error macro definitions.
*/
# define	INT_ERR		"\033[1;31mInternal error: \033[0m"
# define	SYNT_ERR	"\033[1;31mSyntax error: \033[0m"
# define	MALL_ERR	"Malloc failed to allocate the needed memory.\n"

#endif	/* !UTILS_H_ */
