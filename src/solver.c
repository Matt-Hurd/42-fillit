/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/29 23:14:50 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 01:18:50 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"





#include <stdio.h>


int count = 0;


int		backtrack(t_board *b, t_list *tetris)
{
	int x;
	int y;

	if (!tetris)
		return (1);
	y = -1;
	while (++y < b->size)
	{
		x = -1;
		while (++x < b->size)
		{
			if (place(b, (char **)tetris->content, y, x))
			{
				if (backtrack(b, tetris->next) == 1)
					return (1);
				else
				{
					unplace(b, (char **)tetris->content, y, x);
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
	// printf("AAYYY\n");
	return (b);
}