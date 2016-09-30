/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_handlers.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 21:34:06 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/28 21:34:11 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

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
