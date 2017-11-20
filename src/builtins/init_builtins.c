/*
** init_builtins.c for init_builtins in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 08:50:21 2016 Lucas
** Last update Tue May 31 14:42:29 2016 Lucas
*/

#include "shell.h"

/*
** Init the function pointer array used for the builtins.
*/
void		init_bt_ptr_func(t_shell *shell)
{
  shell->bt_func[0] = (t_check_builtin)&builtin_env;
  shell->bt_func[1] = (t_check_builtin)&builtin_setenv;
  shell->bt_func[2] = (t_check_builtin)&builtin_unsetenv;
  shell->bt_func[3] = (t_check_builtin)&builtin_cd;
  shell->bt_func[4] = (t_check_builtin)&builtin_exit;
  shell->bt_func[5] = (t_check_builtin)&builtin_alias;
  shell->bt_func[6] = (t_check_builtin)&builtin_history;
  shell->bt_func[7] = (t_check_builtin)&builtin_echo;
  shell->bt_func[8] = NULL;
}

/*
** Init the bultin array.
*/
int		init_bt_array(t_shell *shell)
{
  if (((shell->bt_array[0] = my_strdup("env")) == NULL) ||
      ((shell->bt_array[1] = my_strdup("setenv")) == NULL) ||
      ((shell->bt_array[2] = my_strdup("unsetenv")) == NULL) ||
      ((shell->bt_array[3] = my_strdup("cd")) == NULL) ||
      ((shell->bt_array[4] = my_strdup("exit")) == NULL) ||
      ((shell->bt_array[5] = my_strdup("alias")) == NULL) ||
      ((shell->bt_array[6] = my_strdup("history")) == NULL) ||
      ((shell->bt_array[7] = my_strdup("echo")) == NULL))
    return (SH_ERR);
  shell->bt_array[8] = NULL;
  return (SH_OK);
}
