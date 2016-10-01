/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   board.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:04:22 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 01:08:50 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // Delete

t_board	*gen_board(int size)
{
	t_board *b;
	int		x;

	b = (t_board *)ft_memalloc(sizeof(t_board));
	b->board = (char **)ft_memalloc(sizeof(char *) * size);
	x = -1;
	while (++x < size)
	{
		b->board[x] = ft_strnew(size);
		ft_memset((void *)b->board[x], '.', size);
	}
	b->size = size;
	return (b);
}

int		place(t_board *b, char **piece, int y_origin, int x_origin)
{
	int y;
	int x;

	x = -1;
	y = -1;
	while (++y < 4 && piece[y])
	{
		x = -1;
		while (++x < 4 && piece[y][x])
		{
			if (piece[y][x] == '#')
			{
				if (y_origin + y >= b->size || x_origin + x >= b->size 
					|| b->board[y_origin + y][x_origin + x] == '#')
				{
					return (0);
				}
			}
		}
	}
	x = -1;
	while (++x < 16)
			if (piece[x/4][x%4] == '#')
				b->board[y_origin + x/4][x_origin + x%4] = '#';
	return (1);
}

void	unplace(t_board *b, char **piece, int y_origin, int x_origin)
{
	int y;
	int x;

	x = -1;
	y = -1;
	while (++y < 4 && piece[y])
	{
		x = -1;
		while (++x < 4 && piece[y][x])
			if (piece[y][x] == '#')
				b->board[y_origin + y][x_origin + x] = '.';
	}
}
