/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:52 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 00:31:14 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct	s_board
{
	int		size;
	char	**board;
}				t_board;

void			throw_error(char *text, int num, int fd);
t_list			*parse_file(int fd);
char			**dup_array(char **in);
t_board			*gen_board(int size);
int				place(t_board *b, char **piece, int y_origin, int x_origin);
void			unplace(t_board *b, char **piece, int y_origin, int x_origin);
t_board			*solve(t_list *tetris);


#endif
