# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mhurd <marvin@42.fr>                       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:34:56 by mhurd             #+#    #+#              #
#    Updated: 2016/09/29 23:45:21 by mhurd            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= fillit 

SRC		= main.c \
		  parser.c \
		  error.c \
		  struct_handlers.c \
		  board.c \
		  solver.c

OBJ		= $(addprefix $(OBJDIR),$(SRC:.c=.o))

CC		= gcc
CFLAGS	= -Wall -Wextra -Werror

LIBFT	= ./src/libft/libft.a
LIBINC	= -I./src/libft
LIBLINK	= -L./src/libft -lft

SRCDIR	= ./src/
INCDIR	= ./includes/
OBJDIR	= ./obj/

all: obj libft $(NAME)

obj:
	mkdir -p $(OBJDIR)

$(OBJDIR)%.o:$(SRCDIR)%.c
	$(CC) $(CFLAGS) $(LIBINC) -I $(INCDIR) -o $@ -c $<

libft: $(LIBFT)

$(LIBFT):
	make -C ./src/libft

$(NAME): $(OBJ)
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)

clean:
	rm -rf $(OBJDIR)
	make -C ./src/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./src/libft fclean

re: fclean all
