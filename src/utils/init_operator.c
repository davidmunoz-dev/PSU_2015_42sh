/*
** init_operator.c for init_operator in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 19:40:40 2016 Lucas
** Last update Sat Jun  4 19:51:56 2016 Lucas
*/

#include "shell.h"

void		init_sepa_ptr_func(t_shell *shell)
{
  shell->sepa_func[0] = (t_check_sepa)&sepa_and;
  shell->sepa_func[1] = (t_check_sepa)&sepa_or;
  shell->sepa_func[2] = (t_check_sepa)&sepa_coma;
  shell->sepa_func[3] = (t_check_sepa)&sepa_pipe;
  shell->sepa_func[4] = (t_check_sepa)&sepa_rafter_right;
  shell->sepa_func[5] = (t_check_sepa)&sepa_rafter_dright;
  shell->sepa_func[6] = (t_check_sepa)&sepa_rafter_left;
  shell->sepa_func[7] = (t_check_sepa)&sepa_rafter_dleft;
  shell->sepa_func[8] = NULL;
}
