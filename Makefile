##
## Makefile for make in /home/onillo_l/rendu/PSU/PSU_2015_42sh
## 
## Made by Lucas
## Login   <onillo_l@epitech.net>
## 
## Started on  Fri Apr 22 14:04:25 2016 Lucas
## Last update Sun Jun  5 23:05:23 2016 Lucas
##

TARGET	= 42sh

SRC	= main.c		\
	  init_env.c		\
	  read_command.c	\
	  init.c		\

BUILTIN	= init_builtins.c	\
	  builtin_env.c		\
	  builtin_unsetenv.c	\
	  builtin_setenv.c	\
	  builtin_cd.c		\
	  builtin_exit.c	\
	  builtin_alias.c	\
	  builtin_history.c	\
	  builtin_prompt.c	\
	  builtin_utils.c	\
	  builtin_echo_option.c	\
	  builtin_echo_option2.c \
	  builtin_echo_backslsh.c \
	  builtin_echo.c	\

UTILS	= env_utils.c		\
	  signal_utils.c	\
	  shell_utils.c		\
	  bt_utils.c		\
	  init_operator.c	\
	  redirect_utils.c	\

PARSER	= parse_line.c		\
	  parser_utils.c	\
	  update_cmd.c		\
	  handle_separator.c	\
	  security_check.c	\

EXEC	= exec.c		\
	  sepa_and.c		\
	  sepa_or.c		\
	  sepa_coma.c		\
	  sepa_pipe.c		\
	  rafter_right.c	\
	  rafter_dright.c	\
	  rafter_left.c		\
	  rafter_dleft.c	\

CFLAGS  = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = src
SUTLDIR	 = src/utils
SBLTDIR	 = src/builtins
SPRSDIR  = src/parser
EXECDIR	 = src/exec

OBJDIR   = obj
OUTLDIR	 = obj/utils
OBLTDIR  = obj/builtins
OBPRSDIR = obj/parser
OBJEXEC	 = obj/exec
DIRLIB   = lib/my/

SOURCES  := $(addprefix src/, $(SRC))		\
	$(addprefix src/builtins/, $(BUILTIN))	\
	$(addprefix src/utils/, $(UTILS))	\
	$(addprefix src/parser/, $(PARSER))	\
	$(addprefix src/exec/, $(EXEC))		\

OBJECTS  := $(SOURCES:$(SRCDIR)/%.c=$(OBJDIR)/%.o)

rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	cd $(DIRLIB) && $(MAKE)
	@$(CC) $(CFLAGS) -o $@ $(OBJECTS) -L./lib/my -lmy
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : $(SRCDIR)/%.c
	@$(mkdir) $(OBJDIR) $(OUTLDIR) $(OBLTDIR) $(OBPRSDIR) $(OBJEXEC)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all	: $(OBJECTS) $(TARGET)

clean	:
	@$(rm) $(OBJDIR)
	cd $(DIRLIB) && $(MAKE) clean
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean	: clean
	@$(rm) $(TARGET)
	cd $(DIRLIB) && $(MAKE) fclean
	@echo "\033[1;31mBinary and executable files have been deleted\033[0m"

re	: lib fclean all

.PHONY	: all clean fclean re lib
