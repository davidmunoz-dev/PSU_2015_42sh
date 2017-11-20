/*
** read_command.c for read_command in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Wed Apr 27 12:33:55 2016 Lucas
** Last update Wed Jun  1 11:19:36 2016 Lucas
*/

#include "shell.h"

int		read_command(t_shell *shell)
{
  int		ret;

  shell->is_running = MY_TRUE;
  handle_sig();
  while (shell->is_running == MY_TRUE)
    {
      display_prompt(shell);
      if ((ret = read(0, shell->buffer, BUFF_SIZE)) < 0)
	return (fprintf(stderr, "%s: %s\n", INT_ERR, READ_ERR), SH_ERR);
      if (ret == 0)
	{
	  handle_sig_ending();
	  shell->status = 0;
	  return (builtin_exit(shell));
	}
      shell->buffer[(shell->buffer[ret - 1] == '\n' ? ret - 1 : ret)] = 0;
      if (parse_line(shell) == SH_ERR)
	printf("%s: %s\n", shell->buffer, CMD_NOT_FOUND);
    }
  return (SH_OK);
}
