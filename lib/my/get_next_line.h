/*
** get_next_line.h for headerfile in /home/onillo_l/rendu/CPE/CPE_2015_getnextline
**
** Made by Lucas Onillon
** Login   <onillo_l@epitech.net>
**
** Started on  Sun Jan 17 10:46:32 2016 Lucas Onillon
** Last update Thu Mar 10 22:13:56 2016 Lucas
*/

#ifndef READ_SIZE
# define READ_SIZE	14

#endif	/* !READ_SIZE*/

#ifndef GET_NEXT_LINE_H_
# define GET_NEXT_LINE_H_

/*
** System includes.
*/
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/stat.h>
#include <fcntl.h>

/*
** Structure definition.
*/
typedef struct		s_buffer
{
  char			*data;
  struct s_buffer	*next;
}			t_buffer;

/*
** Function prototypes.
*/
t_buffer       	*add_elem(t_buffer *ptr, char *data);
char	       	*fill_buffer(t_buffer *ptr, int max);
int    		check_line(char *buf, int ret);
t_buffer       	*my_read(const int fd, t_buffer *first, char* buf, char **all);
char		*get_next_line(const int fd);

#endif /* !GET_NEXT_LINE_H_ */
