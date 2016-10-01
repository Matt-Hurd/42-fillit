/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:34:06 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 21:30:06 by mhurd            ###   ########.fr       */
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

t_list	*make_piece(char **p, int count)
{
	t_etris	*tetris;
	int		z;

	tetris = (t_etris *)ft_memalloc(sizeof(t_etris));
	tetris->piece = (char **)ft_memalloc(sizeof(char *) * 4);
	ft_memcpy(tetris->piece, p, sizeof(char *) * 4);
	tetris->width = 0;
	tetris->height = 0;
	z = -1;
	while (++z < 16)
		if (p[z / 4][z % 4] == '#')
		{
			tetris->width = MAX(tetris->width, (z % 4) + 1);
			tetris->height = MAX(tetris->height, (z / 4) + 1);
		}
	tetris->letter = 'A' - 1 + count;
	return (ft_lstnew(tetris, sizeof(t_etris)));
}