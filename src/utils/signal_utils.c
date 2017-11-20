/*
** my_utils.c for my_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Apr 29 04:11:11 2016 Lucas
** Last update Fri Apr 29 04:14:06 2016 Lucas
*/

#include "shell.h"

/*
** Sig handling when leaving the process.
*/
int		handle_sig_ending()
{
  if (signal(SIGINT, SIG_DFL) == SIG_ERR)
    return (cerr_zero(INT_ERR, SI_ERR, SH_ERR));
  return (SH_OK);
}

/*
** Prevent the usage of signals during the process.
*/
int		handle_sig()
{
  if (signal(SIGINT, SIG_IGN) == SIG_ERR)
    return (cerr_zero(INT_ERR, SI_ERR, SH_ERR));
  if (signal(SIGQUIT, SIG_IGN) == SIG_ERR)
    return (cerr_zero(INT_ERR, SI_ERR, SH_ERR));
  return (SH_OK);
}
