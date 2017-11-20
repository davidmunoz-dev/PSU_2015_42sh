/*
** builtin_echo.c for  in /home/munoz_d/Epitech/rendu/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_42sh/src/builtins
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Tue May 31 13:37:04 2016 David Munoz
** Last update Sat Jun  4 15:45:10 2016 Lucas
*/

#include "shell.h"

/*
** echo - display a line of text
*/
int	echo(int ac, char **av)
{
  int	*option;
  int	i;

  if ((option = malloc(sizeof(int) * 3)) == NULL)
    return (-1);
  option[0] = 0;
  option[1] = 0;
  option[2] = 1;
  i = check_option(ac, av);
  if (i == 0)
    no_option(av);
  else
    {
      option = right_arg(av, i, option);
      print_echo_arg(av, ac, i, option);
    }
  free(option);
  return (0);
}

int		builtin_echo(t_shell *shell)
{
  if (echo(shell->ac, shell->av) == SH_ERR)
    return (SH_ERR);
  return (SH_OK);
}
