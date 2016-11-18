/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:52 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/05 14:26:46 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>

extern const char	*g_patterns[];
extern const int	g_values[];

typedef struct	s_etris
{
	char	**string;
	long	*piece;
	int		width;
	int		height;
	char	letter;
	int		x;
	int		y;
	int		p;
}				t_etris;

typedef struct	s_board
{
	int		size;
	long	*board;
	t_list	*pieces;
}				t_board;

void			run_fillit(const char *file_path);
void			throw_error(char *text, int num, int fd);
t_list			*parse_file(int fd);
char			**dup_array(char **in);
t_board			*gen_board(int size, t_list *tetris);
int				place(t_board *b, t_etris *p, int y_origin, int x_origin);
void			unplace(t_board *b, t_etris *p, int y_origin, int x_origin);
t_board			*solve(t_list *tetris);
t_list			*make_piece(int p, int count);
void			ft_lstadd_back(t_list **alst, t_list *new);
void			print_board(t_board *board);
int				count_islands(char **p);
void			validate_next_line(char *r_buf, int fd, int *result);
int				clean(char **p);
void			add_piece(t_list **ret, char **buf, int *count);

#endif
