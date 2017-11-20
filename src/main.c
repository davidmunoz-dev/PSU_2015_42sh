/*
** main.c for main in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Apr 22 14:06:35 2016 Lucas
** Last update Wed Jun  1 11:14:30 2016 Lucas
*/

#include "shell.h"

/*
** Looks like a main function... I guess.
*/
int		main(int ac, char **av, char **env)
{
  t_shell	*shell;
  (void)ac;
  (void)av;

  if ((shell = init_data(env)) == NULL)
    return (SH_ERR);
  if (read_command(shell) == SH_ERR)
    return (SH_ERR);
  return (shell->status);
}
