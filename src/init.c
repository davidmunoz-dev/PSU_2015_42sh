/*
** init.c for init in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Mon May 23 15:28:46 2016 Lucas
** Last update Sun Jun  5 20:53:21 2016 Lucas
*/

#include "shell.h"

int		init_separator(t_shell *shell)
{
  if (((shell->sepa_array[0] = my_strdup("&&")) == NULL) ||
      ((shell->sepa_array[1] = my_strdup("||")) == NULL) ||
      ((shell->sepa_array[2] = my_strdup(";")) == NULL) ||
      ((shell->sepa_array[3] = my_strdup("|")) == NULL) ||
      ((shell->sepa_array[4] = my_strdup(">")) == NULL) ||
      ((shell->sepa_array[5] = my_strdup(">>")) == NULL) ||
      ((shell->sepa_array[6] = my_strdup("<")) == NULL) ||
      ((shell->sepa_array[7] = my_strdup("<<")) == NULL))
    return (SH_ERR);
  shell->sepa_array[8] = NULL;
  return (SH_OK);
}

int		init_sepa_level(t_shell *shell)
{
  if (((shell->sepa_level[0] = my_strdup(T_DEF)) == NULL) ||
      ((shell->sepa_level[1] = my_strdup(T_AND)) == NULL) ||
      ((shell->sepa_level[2] = my_strdup(T_OR)) == NULL) ||
      ((shell->sepa_level[3] = my_strdup(T_COMA)) == NULL) ||
      ((shell->sepa_level[4] = my_strdup(T_PIPE)) == NULL) ||
      ((shell->sepa_level[5] = my_strdup(T_RAFTER_R)) == NULL) ||
      ((shell->sepa_level[6] = my_strdup(T_RAFTER_RD)) == NULL) ||
      ((shell->sepa_level[7] = my_strdup(T_RAFTER_L)) == NULL) ||
      ((shell->sepa_level[8] = my_strdup(T_RAFTER_LD)) == NULL))
    return (SH_ERR);
  shell->sepa_level[9] = NULL;
  return (SH_OK);
}

/*
** Init the main structure of the program.
*/
t_shell		*init_data(char **env)
{
  t_shell	*shell;

  if ((shell = malloc(sizeof(t_shell))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  if (((shell->env_list = init_env(NULL, env)) == NULL) ||
      ((shell->path = find_path(shell, NULL)) == NULL) ||
      ((init_separator(shell)) == SH_ERR) ||
      ((init_sepa_level(shell)) == SH_ERR) ||
      ((init_bt_array(shell))) == SH_ERR)
    return (NULL);
  shell->status = SH_OK;
  shell->line = -1;
  init_bt_ptr_func(shell);
  init_sepa_ptr_func(shell);
  return (shell);
}
