/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:44:55 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 22:12:04 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char	*g_patterns[] = {
	"###...#",
	".#...#..##",
	"#...###",
	"##..#...#",
	"###.#",
	"##...#...#",
	"..#.###",
	"#...#...##",
	"###..#",
	".#..##...#",
	".#..###",
	"#...##..#",
	".##.##",
	"#...##...#",
	"##...##",
	".#..##..#",
	"####",
	"#...#...#...#",
	"##..##"
};

void		clean(char **p)
{
	int		x;
	int		y;
	char	*joined;

	joined = ft_strcjoin("", p, 4);
	x = -1;
	while (++x < 19)
		if (ft_strstr(joined, g_patterns[x]))
		{
			y = -1;
			while (++y < 4)
			{
				ft_strclr(p[y]);
				if (y * 4 < (int)ft_strlen(g_patterns[x]))
					ft_strncpy(p[y], g_patterns[x] + (y * 4), 
						MIN(ft_strlen(g_patterns[x]) - (y * 4), 4));
			}
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
	int 		count;

	ret = NULL;
	read_buff = ft_strnew(20);
	count = 1;
	while ((result = read(fd, read_buff, 20)) > 0)
	{
		buffer = ft_strsplit(read_buff, '\n');
		if (valid_array(buffer) && result == 20)
		{
			if (ret)
				ft_lstadd_back(&ret, make_piece(buffer, count));
			else
				ret = make_piece(buffer, count);
			ft_strclr(read_buff);
			result = read(fd, read_buff, 1);
			if (result < 0 || (result == 1 && !ft_strequ(read_buff, "\n")))
				throw_error("error", -1, fd);
		}
		else
			throw_error("error", -1, fd);
		count++;
	}
	if (!ret || result < 0 || ft_strequ(read_buff, "\n"))
		throw_error("error", -1, fd);
	return (ret);
}
