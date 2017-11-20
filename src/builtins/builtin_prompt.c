/*
** builtin_prompt.c for  in /home/munoz_d/Bureau/PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Wed May 11 02:27:30 2016 David Munoz
** Last update Mon May 23 16:13:44 2016 Lucas
*/

#include "shell.h"

/*
** Custom prompt with the logname and number of lines
*/
void		prompt_custom(t_shell *shell, int i)
{
  if ((shell->logname = get_logname(shell, "USER")) != NULL)
    {
      my_putstr(shell->logname);
      my_putstr(" - ");
      my_put_nbr(i);
      my_putstr(" - $> ");
    }
  else
    {
      my_putstr("- ");
      my_put_nbr(i);
      my_putstr(" - $> ");
    }
}
