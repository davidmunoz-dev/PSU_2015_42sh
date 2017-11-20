/*
** sepa_pipe.c for sepa_pipe in /home/onillo_l/rendu/PSU/PSU_2015_42sh/src/exec
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Sat Jun  4 20:04:26 2016 Lucas
** Last update Sun Jun  5 19:42:38 2016 lenoir_g
*/

#include "shell.h"

int		piped_exec()
{
  return (1);
}


char	**form_cmd_r(t_shell *sh, int pos)
{
  int	i;
  int	c;
  char	**ret;

  i = pos + 1;
  while (sh->op_pos[i] == '0' && sh->op_pos[i])
    i++;
  if ((ret = malloc((i - pos + 2) * sizeof(char *))) == NULL)
    return (NULL);
  i = pos + 1;
  while (sh->op_pos[i])
    {
      ret[c] = my_strdup(sh->av[i]);
      c++;
      i++;
    }
  ret[c] = NULL;
  return (ret);
}

char	**form_cmd_l(t_shell *sh, int pos)
{
  char	**ret;
  int	i;
  int	c;

  c = 0;
  i = pos - 1;
  while (i > -1 && sh->op_pos[i] == '0')
    {
      i--;
      c++;
    }
  if (i < 0)
    i = 0;
  if ((ret = malloc((c + 1) * sizeof(char *))) == NULL)
    return (NULL);
  c = 0;
  while (i < pos)
    {
      ret[c] = my_strdup(sh->av[i]);
      i++;
      c++;
    }
  ret[c] = NULL;
  return (ret);
}

int		sepa_pipe(t_shell *shell, int pos)
{
  printf("sepa | wanted pos: %s\n",shell->op_pos);
  char **t;
  t = form_cmd_l(shell, pos);
  int		k = 0;
  while (t[k])
    {
      printf("- %s\n", t[k]);
      k++;
    }
  char **e;
  e = form_cmd_r(shell, pos);
  int		a = 0;
  while (e[a])
    {
      printf("-- %s\n", e[a]);
      a++;
    }
  return (SH_OK);
}
