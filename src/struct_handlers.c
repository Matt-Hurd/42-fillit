/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:34:06 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/01 06:49:17 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	ft_lstadd_back(t_list **alst, t_list *new)
{
	t_list *iter;

	if (!new || !alst)
		return ;
	iter = *alst;
	while (iter->next)
		iter = iter->next;
	iter->next = new;
}

char	**dup_array(char **in)
{
	int		x;
	char	**ret;

	ret = (char **)ft_memalloc(sizeof(char *) * 4);
	x = -1;
	while (++x < 4)
		ret[x] = ft_strdup(in[x]);
	return (ret);
}

void	add_bits(t_etris *t, int p)
{
	int		x;

	x = -1;
	t->piece = (long *)ft_memalloc(sizeof(long) * 4);
	while (++x < 4)
		t->piece[x] = ((p >> ((3 - x) * 4) & 0xF));
}

t_list	*make_piece(int p, int count)
{
	t_etris	*tetris;
	int		z;
	int		x;

	tetris = (t_etris *)ft_memalloc(sizeof(t_etris));
	add_bits(tetris, p);
	tetris->width = 0;
	tetris->height = 0;
	tetris->p = p;
	z = 4;
	while (--z >= 0)
		if (p >> z * 4)
		{
			x = -1;
			while (++x < 4)
				if ((0x8 >> x) & (p >> z * 4))
					tetris->width = MAX(tetris->width, x + 1);
			if ((p >> z * 4) & 0xF)
				tetris->height++;
		}
	tetris->letter = 'A' - 1 + count;
	tetris->x = -1;
	tetris->y = -1;
	return (ft_lstnew(tetris, sizeof(t_etris)));
}
