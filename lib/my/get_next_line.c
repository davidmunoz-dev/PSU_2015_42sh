/*
** get_next_line.c for get_next_line in /home/onillo_l/rendu/CPE/CPE_2015_getnextline
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Sun Jan 17 10:45:38 2016 Lucas Onillon
** Last update Sun Jan 17 19:50:22 2016 Lucas Onillon
*/

#include "get_next_line.h"

/*
** Will create a new element to the linked list in param,
** and set the data to the current element.
*/
t_buffer	*add_elem(t_buffer *elem, char *data)
{
  t_buffer	*first;

  first = elem;
  if (elem == NULL)
    {
      if ((elem = malloc(sizeof(t_buffer))) == NULL)
	return (NULL);
      elem->data = data;
      elem->next = NULL;
      return (elem);
    }
  while (elem->next)
    elem = elem->next;
  if ((elem->next = malloc(sizeof(t_buffer))) == NULL)
    return (NULL);
  elem->next->data = data;
  elem->next->next = NULL;
  return (first);
}

/*
** This "fill_buffer" function act like a realloc except that
** it will only work with linked list.
*/
char	*fill_buffer(t_buffer *elem, int max)
{
  char	*new_str;
  int	n;
  int	i;

  if ((new_str = malloc(max * READ_SIZE + 1)) == NULL)
    return (NULL);
  i = 0;
  while (elem)
    {
      n = 0;
      while (elem->data[n] && elem->data[n] != '\n')
	{
	  new_str[i] = elem->data[n];
	  n++;
	  i++;
	}
      elem = elem->next;
    }
  new_str[i] = '\0';
  return (new_str);
}

/*
** Basic line parsing.
*/
int	check_line(char *buf, int ret)
{
  int	i;

  i = 0;
  if (ret != READ_SIZE)
    return (0);
  if ((buf) == NULL)
    return (1);
  while (buf[i])
    {
      if (buf[i] == '\n')
	return (0);
      i = i + 1;
    }
  return (1);
}

/*
** Will read the file line by line in a loop and create
** a new element of the linked list after each lap.
*/
t_buffer	*my_read(const int fd, t_buffer *elem, char *buffer,
			 char **line)
{
  int	count;
  int	ret;

  count = 1;
  ret = READ_SIZE;
  while (check_line(buffer, ret))
    {
      if ((buffer = malloc(READ_SIZE + 1)) == NULL)
	return (NULL);
      if ((ret = read(fd, buffer, READ_SIZE)) <= 0)
	return (0);
      buffer[ret] = '\0';
      if ((elem = add_elem(elem, buffer)) == NULL)
	return (NULL);
      count++;
    }
  *line = fill_buffer(elem, count);
  return (elem);
}

/*
** Entry point of the function, will init all the needed data
** and fill the line field with the elem linked list.
*/
char		*get_next_line(const int fd)
{
  static char	file[READ_SIZE + 1];
  t_buffer     	*elem;
  char		*buffer;
  char		*line;
  int		i;

  buffer = file;
  if ((elem = add_elem(NULL, buffer)) == NULL)
    return (NULL);
  if ((elem = my_read(fd, elem, buffer, &line)) == NULL)
    return (NULL);
  i = -1;
  while (elem->next != NULL)
    elem = elem->next;
  while (*elem->data && *elem->data != '\n')
    elem->data = elem->data + 1;
  while (*(elem->data = elem->data + 1))
    file[(i = i + 1)] = *elem->data;
  file[i + 1] = '\0';
  return (line);
}
