/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:04:22 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/01 06:47:52 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_to_print(char **p, t_etris *t)
{
	int		id;
	int		x;

	id = -1;
	while (g_values[++id] != t->p)
		;
	x = -1;
	while (++x < (int)ft_strlen(g_patterns[id]))
		if (g_patterns[id][x] == '#')
			p[x / 4 + t->y][x % 4 + t->x] = t->letter;
}

void	print_board(t_board *board)
{
	char	**ret;
	int		x;
	t_etris	*tet;
	t_list	*p;

	ret = (char **)ft_memalloc(sizeof(char *) * board->size);
	x = -1;
	while (++x < board->size)
	{
		ret[x] = ft_strnew(board->size);
		ft_memset(ret[x], '.', board->size);
	}
	p = board->pieces;
	while (p)
	{
		tet = (t_etris *)p->content;
		if (tet->x != -1)
			add_to_print(ret, tet);
		p = p->next;
	}
	ft_putendl(ft_strcjoin("\n", ret, board->size));
}

t_board	*gen_board(int size, t_list *tetris)
{
	t_board *b;

	b = (t_board *)ft_memalloc(sizeof(t_board));
	b->board = (long *)ft_memalloc(sizeof(long) * 32);
	b->size = size;
	b->pieces = tetris;
	return (b);
}

int		place(t_board *b, t_etris *p, int y_origin, int x_origin)
{
	int y;

	y = -1;
	while (++y < p->height)
		if (b->board[y_origin + y] & p->piece[y] << (28 - x_origin))
			return (0);
	y = -1;
	while (++y < p->height)
		b->board[y_origin + y] += p->piece[y] << (28 - x_origin);
	p->x = x_origin;
	p->y = y_origin;
	return (1);
}

void	unplace(t_board *b, t_etris *p, int y_origin, int x_origin)
{
	int y;

	y = -1;
	while (++y < p->height)
		b->board[y_origin + y] ^= p->piece[y] << (28 - x_origin);
}
