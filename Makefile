# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/09/28 19:34:56 by mhurd             #+#    #+#              #
<<<<<<< HEAD
#    Updated: 2016/10/05 14:21:20 by mhurd            ###   ########.fr        #
=======
#    Updated: 2016/09/30 19:28:22 by mfernand         ###   ########.fr        #
>>>>>>> 0dfa6fdcec0bc40d83896b9cfc51cfcdcca31ff2
#                                                                              #
# **************************************************************************** #

NAME	= fillit 

SRC		= main.c \
		  fillit.c \
		  parser.c \
		  error.c \
		  struct_handlers.c \
		  board.c \
<<<<<<< HEAD
		  solver.c \
		  count_islands.c \
		  helpers.c
=======
		  solver.c
>>>>>>> 0dfa6fdcec0bc40d83896b9cfc51cfcdcca31ff2

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
<<<<<<< HEAD
	$(CC) -o $(NAME) $(OBJ) $(LIBLINK)
=======
	$(CC) $(LIBLINK) -o $(NAME) $(OBJ)
>>>>>>> 0dfa6fdcec0bc40d83896b9cfc51cfcdcca31ff2

clean:
	rm -rf $(OBJDIR)
	make -C ./src/libft clean

fclean: clean
	rm -rf $(NAME)
	make -C ./src/libft fclean

re: fclean all
