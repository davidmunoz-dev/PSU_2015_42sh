/*
** my_str_to_wordtab.c for str_to_wordtab in /home/onillo_l/rendu/CPE/CPE_2015_lemin/lib/my
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Mar 30 10:40:48 2016 Lucas
** Last update Sat Jun  4 16:01:27 2016 Lucas
*/

#include "my.h"

int	cpy_word(char *str, char c)
{
  int	i;
  int	cpy;
  char	prev;

  prev = c;
  i = cpy = 0;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	cpy++;
      prev = str[i];
      i++;
    }
  return (cpy);
}

char	*copy(char *str, char *dest, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      dest[i] = str[start];
      i++;
      start++;
    }
  dest[i] = '\0';
  return (dest);
}

int	cpy_letter(char *str, int start, char c)
{
  int	i;

  i = 0;
  while ((str[start] != c) && (str[start]))
    {
      start++;
      i++;
    }
  return (i);
}

char	**my_str_to_wordtab(char *str, char c)
{
  int	i;
  int	j;
  char	prev;
  char	**tab;

  i = j = 0;
  if ((tab = malloc((cpy_word(str, c) + 1) * sizeof(*tab))) == NULL)
    return (cerr_msg(INT_ERR, MALL_ERR));
  prev = c;
  while (str && str[i])
    {
      if ((prev == c) && (str[i] != c))
	{
	  if ((tab[j] = malloc((cpy_letter(str, i, c) + 1) * sizeof(**tab)))
	      == NULL)
	    return (cerr_msg(INT_ERR, MALL_ERR));
	  copy(str, tab[j], i, c);
	  j++;
	}
      prev = str[i];
      i++;
    }
  tab[j] = NULL;
  return (tab);
}
