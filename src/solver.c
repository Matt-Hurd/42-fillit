/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:14:50 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/01 06:48:23 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		backtrack(t_board *b, t_list *tetris)
{
	int		x;
	int		y;
	t_etris	*t;

	if (!tetris)
		return (1);
	t = (t_etris *)tetris->content;
	y = -1;
	while (++y <= b->size - t->height)
	{
		x = -1;
		while (++x <= b->size - t->width)
			if (place(b, t, y, x))
			{
				if (backtrack(b, tetris->next))
					return (1);
				else
					unplace(b, t, y, x);
			}
	}
	return (0);
}

t_board	*solve(t_list *tetris)
{
	t_board	*b;
	int		count;
	int		size;
	t_list	*counter;

	counter = tetris;
	count = 0;
	while (counter)
	{
		count++;
		counter = counter->next;
	}
	size = 2;
	while (size * size < count * 4)
		size++;
	b = gen_board(size, tetris);
	while (!backtrack(b, tetris))
	{
		size++;
		b = gen_board(size, tetris);
	}
	return (b);
}
