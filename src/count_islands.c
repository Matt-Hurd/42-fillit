/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   count_islands.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 13:29:22 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/05 14:06:15 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	undo(char **p)
{
	int x;
	int y;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (p[y][x] == '@')
				p[y][x] = '#';
	}
}

int		spread(char **p, int x, int y)
{
	int res;

	if (p[y][x] == '#')
	{
		p[y][x] = '@';
		res = 1;
		if (y < 3)
			res += spread(p, x, y + 1);
		if (y > 0)
			res += spread(p, x, y - 1);
		if (x < 3)
			res += spread(p, x + 1, y);
		if (x > 0)
			res += spread(p, x - 1, y);
	}
	else
		res = 0;
	return (res);
}

int		count_islands(char **p)
{
	int x;
	int y;
	int res;

	y = -1;
	while (++y < 4)
	{
		x = -1;
		while (++x < 4)
			if (p[y][x] == '#')
			{
				res = spread(p, x, y);
				undo(p);
				return (res == 4);
			}
	}
	return (0);
}
