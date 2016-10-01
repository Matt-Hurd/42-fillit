/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:44:55 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/29 23:47:36 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void		clean(char **p)
{
	int x;
	int y;
	int x_min;
	int y_min;

	x = -1;
	x_min = -1;
	y_min = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (p[x][y] == '#')
			{
				x_min = (x < x_min || x_min == -1) ? x : x_min;
				y_min = (y < y_min || y_min == -1) ? y : y_min;
			}
		}
	}
	x = -1;
	while (++x < 4)
	{
		if (x + x_min < 4)
			ft_strcpy(p[x], p[x + x_min] + y_min);
		else
			ft_strclr(p[x]);
	}
}

int			valid_piece(char **p)
{
	int x;
	int y;
	int count;

	count = 0;
	x = -1;
	while (++x < 4)
	{
		y = -1;
		while (++y < 4)
		{
			if (p[x][y] == '#')
			{
				if (!((x > 0 && p[x - 1][y] == '#')
					|| (x < 3 && p[x + 1][y] == '#')
					|| (y > 0 && p[x][y - 1] == '#')
					|| (y < 3 && p[x][y + 1] == '#')))
					return (0);
				count++;
			}
		}
	}
	if (count == 4)
	{
		clean(p);
		return (1);
	}
	return (0);
}

int			valid_array(char **p)
{
	int x;
	int y;

	x = -1;
	if (!p || !*p)
		return (0);
	while (++x < 4)
	{
		y = -1;
		if (!p[x] || ft_strlen(p[x]) != 4)
			return (0);
		while (++y < 4)
			if (!p[x][y] || (p[x][y] != '.' && p[x][y] != '#'))
				return (0);
	}
	return (valid_piece(p));
}

t_list		*parse_file(int fd)
{
	char		**buffer;
	int			result;
	char		*read_buff;
	t_list		*ret;

	read_buff = ft_strnew(20);
	while ((result = read(fd, read_buff, 20)) > 0)
	{
		buffer = ft_strsplit(read_buff, '\n');
		if (valid_array(buffer) && result == 20)
		{
			if (ret)
				ft_lstadd(&ret, ft_lstnew(buffer, sizeof(char *) * 4));
			else
				ret = ft_lstnew(buffer, sizeof(char *) * 4);
			ft_strclr(read_buff);
			result = read(fd, read_buff, 1);
			if (result < 0 || (result == 1 && !ft_strequ(read_buff, "\n")))
				throw_error("error", -1, fd);
		}
		else
			throw_error("error", -1, fd);
	}
	if (!ret || result < 0 || ft_strequ(read_buff, "\n"))
		throw_error("error", -1, fd);
	return (ret);
}
