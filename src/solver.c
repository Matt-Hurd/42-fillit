/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:14:50 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 21:37:31 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int count = 0;

int		backtrack(t_board *b, t_list *tetris)
{
	int x;
	int y;
	t_etris *t;

	if (!tetris)
		return (1);
	t = (t_etris *)tetris->content;
	y = -1;
	while (++y < b->size - t->height + 1)
	{
		x = -1;
		while (++x < b->size - t->width + 1)
		{
			if (place(b, t, y, x))
			{
				if (backtrack(b, tetris->next) == 1)
				{
					return (1);
				}
				else
				{
					unplace(b, t, y, x);
				}
			}
		}
	}
	return (0);
}

t_board	*solve(t_list *tetris)
{
	t_board	*b;
	int		size;

	size = 2;
	while (!backtrack((b = gen_board(size)), tetris))
		size++;
	return (b);
}