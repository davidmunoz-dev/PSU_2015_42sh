/*
** shell.h for shell in /home/onillo_l/rendu/PSU/PSU_2015_42sh
**
** Made by Lucas
** Login   <onillo_l@epitech.net>
**
** Started on  Fri Apr 22 14:07:43 2016 Lucas
** Last update Sun Jun  5 22:10:08 2016 Lucas
*/

#ifndef	SHELL_H_
# define SHELL_H_

/*
** Include header files.
*/
# include <stdio.h>
# include <signal.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <string.h>
# include "my.h"

/*
** Macro definitions.
*/
# define	SH_OK		0
# define	SH_ERR		-1
# define	SH_BRK		-2
# define	BUFF_SIZE	4096
# define	BT_NB		8

/*
** Separator types level.
*/
# define	T_DEF		"0"
# define	T_AND		"1"
# define	T_OR		"2"
# define	T_COMA		"3"
# define	T_PIPE		"4"
# define	T_RAFTER_R	"5"
# define	T_RAFTER_RD	"6"
# define	T_RAFTER_L	"7"
# define	T_RAFTER_LD	"8"
# define	T_TOP		"9"

# define	T_MAX		(9)

/*
** Error macro definitions.
*/
# define	SI_ERR		"failed to init the signals handler."
# define	MUCH_ARG_ERR	"Too many arguments.\n"
# define	FEW_ARG_ERR	"Too few arguments.\n"
# define	FORK_ERR	"fork failed to create a child processus"
# define	EXE_ERR		"failed to execute the wanted command."
# define	READ_ERR	"failed to read the entered command."
# define	CMD_NOT_FOUND	"Command not found."
# define	NO_FOD		"No such file or directory."
# define	NULL_CMD	"Invalid null command."
# define	DUP_ERR		"failed to duplicate the a file descriptor."
# define	PIPE_ERR	"failed to create a pipe"
# define	WRITE_ERR	"failed on write"

/*
** Builtin macro defintion
*/
# define	FLAGS		"abcefnrtv"
# define	SETENV		"Setenv: "

typedef struct	s_shell		t_shell;
typedef struct	s_env		t_env;
typedef struct	s_history	t_history;
typedef struct	s_cmd		t_cmd;
typedef struct	s_separator	t_separator;

/*
** Function pointer defintion. Will be used in an array
** to handle the builtins research and the operator gesture.
*/
typedef	int	(*t_check_builtin)(t_shell *shell);
typedef int	(*t_check_sepa)(t_shell *shell, int pos);

/*
** Structures definition.
*/
struct			s_alias
{
  char			*data;
  char			*replace;
  struct s_alias       	*next;
}			t_alias;

struct			s_history
{
  char			*data;
  t_history     	*next;
  t_history     	*prev;
};

struct			s_env
{
  char			*name;
  char			*data;
  t_my_bool		is_actif;
  t_env			*next;
  t_env			*prev;
};

struct			s_shell
{
  t_my_bool		is_running;
  int			status;
  char			*logname;
  char			buffer[BUFF_SIZE + 1];
  char			*prompt;
  char			**path;
  char			*tmp_path;
  t_env			*env_list;
  t_check_builtin	bt_func[BT_NB + 1];
  char			*bt_array[BT_NB + 1];
  int			line;
  char			*sepa_array[T_MAX];
  char			*sepa_level[T_MAX];
  char			**av;
  int			ac;
  char			*op_pos;
  t_check_sepa		sepa_func[T_MAX];
};

/*
** ***************
** *   EXEC      *
** ***************
*/

int		sepa_and(t_shell *shell, int pos);
int		sepa_or(t_shell *shell, int pos);
int		sepa_coma(t_shell *shell, int pos);
int		sepa_pipe(t_shell *shell, int pos);
int		sepa_rafter_right(t_shell *shell, int pos);
int		sepa_rafter_left(t_shell *shell, int pos);
int		sepa_rafter_dright(t_shell *shell, int pos);
int		sepa_rafter_dleft(t_shell *shell, int pos);

/*
** ***************
** *   PARSER    *
** ***************
*/

int		exec_cmd(t_shell *shell);
int		check_current_cmd(t_shell *shell);
int		multi_pipe(t_shell *shell);
int		is_valid_command(t_shell *shell, int pos);
int		handle_separator(t_shell *shell);
int		get_max_pos(t_shell *shell);
int		no_operator(t_shell *shell);
int		update_cmd(t_shell *shell);
int		parse_line(t_shell *shell);
char		**list_to_array(t_env *env_list, char **env);

char		*correct_pathname(char *tmp, char *path, char *cmd);
int		find_binary(t_shell *shell);
int		read_command(t_shell *shell);

/*
** ***************
** *   BUILTINS  *
** ***************
*/

int		check_builtin(t_shell *shell);

int		builtin_echo(t_shell *shell);
int		builtin_history(t_shell *shell);
int		builtin_alias(t_shell *shell);
int		builtin_exit(t_shell *shell);
int		builtin_cd(t_shell *shell);
int		builtin_unsetenv(t_shell *shell);

/*
** src/builtins/builtin_prompt.c
*/
void		prompt_custom(t_shell *shell, int i);

/*
** src/builtins/builtin_env.c
*/
int		builtin_env(t_shell *shell);
t_env		*create_env_var(char **data, int i);
int		builtin_setenv(t_shell *shell);

/*
** src/builtins/init_builtins.c
*/
void		init_bt_ptr_func(t_shell *shell);
int		init_bt_array(t_shell *shell);

/*
** src/builtins/builtin_echo.c
*/
int	echo(int ac, char **av);

/*
** src/builtins/builtin_echo_option.c
*/

int     check_option(int ac, char **av);
void    no_option(char **av);
int     *right_arg(char **av, int nb_opt, int *option);
void    print_echo_backslash(int k);
void	delete_coma(char *back, int i);

/*
** src/builtins/builtin_echo_option2.c
*/
int     echo_option_e(char **av, int ac, int *option, int nb_opt);
void    echo_option_E(char **av, int ac, int *option, int nb_opt);
void    print_echo_arg(char **av, int ac, int nb_opt, int *option);

/*
** src/builtins/builtin_echo_backslsh.c
*/
int     echo_flag_exist(char *back, int i);
char	*add_end_back_token(char *bck, char *av, int i, int j);
char	*delete_backslash(char *av);
int     check_double_backslash(char *back, int i);
int     echo_backslash(char *back, int i);

/*
** src/utils/redirect_utils.c
*/
int	my_tablen(char **str);
char	**pars_av(char **av, int pos);
char	**pars_to_redi(char **av, int pos);

/*
** **************
** * INIT FUNC  *
** **************
*/

t_shell		*init_data(char **env);
t_env		*add_in_end(t_env *elem, char *data);
t_env		*create_elem(char *data);
void		show_list(t_env *list);
t_env		*init_env(t_env *env_list, char **env);

/*
** **************
** * UTILS FUNC *
** **************
*/

/*
** src/utils/init_operator.c
*/
void		init_sepa_ptr_func(t_shell *shell);

/*
** src/utils/shell_utils.c
*/
char		*epur_str(char *old);
void		display_prompt(t_shell *shell);

/*
** src/parser/parser_utils.c
*/
int		is_separator(char *str, t_shell *shell);
char		*update_oppos(t_shell *shell);
int		update_argcount(char **av);
int		calc_len(t_env *env_list);

/*
** src/utils/signal_utils.c
*/
int		handle_sig_ending();
int		handle_sig();

t_env		*update_env_var(char *data, int status);
t_env		*add_to_env(t_env *elem, char *data, int status);
char		**find_path(t_shell *shell, t_env *tmpenv);
t_env		*pars_env(char *data, t_env *elem);
char		*get_logname(t_shell *shell, char *var);

#endif	/* !SHELL_H_ */
