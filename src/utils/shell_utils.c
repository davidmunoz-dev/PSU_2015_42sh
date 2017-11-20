/*
** shell_utils.c for shell_utils in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Tue May 31 09:59:24 2016 Lucas
** Last update Sun Jun  5 22:05:03 2016 David Munoz
*/

#include "shell.h"

char		*pur_str(char *old, char *new_str, int i, int j)
{
  while (old[i])
    {
      if (old[i] != ' ' && old[i] != '\t' && old[i] != '\n')
        {
          new_str[j] = old[i];
          if (old[i + 1] ==  '\t' || old[i + 1] == ' ')
            {
              new_str[j + 1] = ' ';
              j++;
              i++;
            }
          j++;
        }
      i++;
    }
  new_str[i] = '\0';
  return (new_str);
}

char            *epur_str(char *old)
{
  int           i;
  int           j;
  char          *new_str;

  i = j = 0;
  if ((new_str = malloc(my_strlen(old) + 1)) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  while (*old == '\t' || *old == ' ')
    *old += 1;
  pur_str(old, new_str, i, j);
  return (new_str);
}


void		display_prompt(t_shell *shell)
{
  t_env		*tmp;
  t_my_bool	check;

  tmp = shell->env_list;
  check = MY_FALSE;
  shell->line += 1;
  while (tmp)
    {
      if (my_strcmp(tmp->name, "LOGNAME") == SH_OK)
	{
	  check = MY_TRUE;
	  my_putstr("$ ");
	  my_putstr(tmp->data);
	  my_putstr(" ~ ");
	  my_put_nbr(shell->line);
	  my_putstr(" > ");
	}
      tmp = tmp->next;
    }
  if (check == MY_FALSE)
    {
      my_putstr("$ ~ ");
      my_put_nbr(shell->line);
      my_putstr(" > ");
    }
}
