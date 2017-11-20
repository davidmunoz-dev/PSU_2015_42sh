##
## Makefile for Makefile in /home/onillo_l/rendu/Piscine/Piscine_C_J10/lib/my
## 
## Made by Lucas Onillon
## Login   <onillo_l@epitech.net>
## 
## Started on  Fri Oct  9 10:47:12 2015 Lucas Onillon
## Last update Mon May 30 16:54:20 2016 David Munoz
##

TARGET	= libmy.a

SOURCES	= my_getnbr.c			\
	  my_putchar.c			\
	  my_put_nbr.c			\
	  my_putstr.c			\
	  my_revstr.c			\
	  my_strcat.c			\
	  my_strcmp.c			\
	  my_strcpy.c			\
	  my_strlen.c			\
	  my_strncat.c			\
	  is_alpha.c			\
	  my_strncmp.c			\
	  my_strncpy.c			\
	  my_strstr.c			\
	  my_strdup.c			\
	  cerr_err.c			\
	  is_digit.c			\
	  my_str_to_wordtab.c		\
	  my_realloc.c			\
	  get_next_line.c		\

HFILES	= my.h				\
	  utils.h			\
	  get_next_line.h		\

CFLAGS   = -W -Wall -Werror -ansi -pedantic -Iinclude

SRCDIR   = my
OBJDIR   = obj

OBJECTS  := $(SOURCES:%.c=$(OBJDIR)/%.o)

CCLIB    = ar rc
RANLIB   = ranlib
rm       = rm -rf
mkdir    = mkdir -p

$(TARGET): $(OBJECTS)
	@$(CCLIB) $(TARGET) -o $@ $(OBJECTS)
	@$(RANLIB) $(TARGET)
	@cp $(TARGET) ../
	@cp my.h ../../include
	@echo "\033[0;35m"$(TARGET)"\033[1;32m compiled !\033[0m"

$(OBJECTS): $(OBJDIR)/%.o : %.c
	@$(mkdir) $(OBJDIR)
	@$(CC) $(CFLAGS) -c $< -o $@
	@echo "\033[1;32m  [OK]  \033[1;36m"$<"\033[0m"

all     : $(TARGET)

clean   :
	@$(rm) $(OBJDIR)
	@echo "\033[1;31mBinary files deleted\033[0m"

fclean  : clean
	@$(rm) $(TARGET)
	@$(rm) ../$(TARGET)
	@echo "\033[1;31mBinary and executable files have been deleted\033[0m"

re      : fclean all

.PHONY: all clean fclean re
