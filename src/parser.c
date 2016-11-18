/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:44:55 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/05 14:26:19 by mhurd            ###   ########.fr       */
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

const int	g_values[] = {
	0xE200,
	0x44C0,
	0x8E00,
	0xC880,
	0xE800,
	0xC440,
	0x2E00,
	0x88C0,
	0xE400,
	0x4C40,
	0x4E00,
	0x8C80,
	0x6C00,
	0x8C40,
	0xC600,
	0x4C80,
	0xF000,
	0x8888,
	0xCC00
};

int			clean(char **p)
{
	int		x;
	char	*joined;

	joined = ft_strcjoin("", p, 4);
	x = -1;
	while (++x < 19)
		if (ft_strstr(joined, g_patterns[x]))
		{
			free(joined);
			return (g_values[x]);
		}
	return (0);
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
		return (count_islands(p));
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
	char		**buf;
	int			result;
	char		*r_buf;
	t_list		*ret;
	int			count;

	ret = NULL;
	r_buf = ft_strnew(20);
	count = 0;
	while ((result = read(fd, r_buf, 20)) > 0 && ++count)
	{
		if (valid_array((buf = ft_strsplit(r_buf, '\n'))) && result == 20)
		{
			add_piece(&ret, buf, &count);
			validate_next_line(r_buf, fd, &result);
		}
		else
			throw_error("error", -1, fd);
		free(buf);
	}
	if (!ret || result < 0 || ft_strequ(r_buf, "\n"))
		throw_error("error", -1, fd);
	return (ret);
}
