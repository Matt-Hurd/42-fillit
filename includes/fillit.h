/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:52 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 21:28:19 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> // Delete
# include <time.h> // Delete

typedef struct	s_board
{
	int		size;
	char	**board;
}				t_board;

typedef struct	s_etris
{
	char	**piece;
	int		width;
	int		height;
	char	letter;
}				t_etris;

void			run_fillit(const char *file_path);

void			throw_error(char *text, int num, int fd);
t_list			*parse_file(int fd);
char			**dup_array(char **in);
t_board			*gen_board(int size);
int				place(t_board *b, t_etris *p, int y_origin, int x_origin);
void			unplace(t_board *b, t_etris *p, int y_origin, int x_origin);
t_board			*solve(t_list *tetris);
t_list			*make_piece(char **p, int count);
void			ft_lstadd_back(t_list **alst, t_list *new);

#endif
