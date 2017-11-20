/*
** redirect_utils.c for  in /home/munoz_d/Epitech/projets/rendu_Systeme_Unix/rendu_ProgShell/PSU_2015_42sh/src/utils
**
** Made by David Munoz
** Login   <munoz_d@epitech.net>
**
** Started on  Sun Jun  5 16:29:47 2016 David Munoz
** Last update Sun Jun  5 21:49:51 2016 David Munoz
*/

#include "shell.h"

/*
** Return the lenght of the char **
*/
int		my_tablen(char **str)
{
  int   i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

/*
** Pars the redirection
** AV = line of command
** pos = position of redirection
** Ex : cat -e < Makefile
** = cat -e Makefile
*/
char	**pars_av(char **av, int pos)
{
  char  **new_av;
  int   i;
  int   j;
  int   k;

  i = k = 0;
  if ((new_av = malloc(my_tablen(av) * sizeof(char *))) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
  while (av[i] != NULL)
    {
      if ((new_av[k] = malloc(sizeof(char) * my_strlen(av[i]) + 1)) == NULL)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
      j = 0;
      if (av[i][j] != av[pos][j] && av[i][j])
        {
          while (av[i][j] != '\0')
            {
              new_av[k][j] = av[i][j];
              j++;
            }
	  new_av[k++][j] = '\0';
	}
      i++;
    }
  return (new_av);
}


int	check_position(int i, char **av, int pos)
{
  if (i == pos)
    {
      if (av[i+1] != NULL)
	i += 2;
    }
  return (i);
}

/*
** Pars redirection like : ls > toto -l
** = ls -l
** and will open&write on toto
*/
char	**pars_to_redi(char **av, int pos)
{
  char  **new_av;
  int   i;
  int   j;
  int   k;

  i = k = 0;
  if ((new_av = malloc(sizeof(char *) * (my_tablen(av) + 2))) == NULL)
    return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
  while (av[i])
    {
      if ((new_av[k] = malloc(sizeof(char) * (my_strlen(av[i]) + 1))) == NULL)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, MALL_ERR), NULL);
      j = 0;
      while (av[i][j] != '\0')
	{
	  new_av[k][j] = av[i][j];
	  j++;
	}
      new_av[k][j] = '\0';
      k++;
      i++;
      i = check_position(i, av, pos);
    }
  return (new_av);
}
