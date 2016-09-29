/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:44:55 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/28 19:44:58 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <fcntl.h>
#include <unistd.h>

int			valid_piece(char **p)
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
	return (1);
}

/*
** TODO: Close file
** TODO: Change errors to print "error"
*/

t_list		*parse_file(char *file)
{
	int			fd;
	char		**buffer;
	int			result;
	char		*read_buff;
	t_list		*ret;

	fd = open(file, O_RDONLY);
	read_buff = ft_strnew(20);
	if (fd < 1)
			throw_error("Error opening file", -1);
	while ((result = read(fd, read_buff, 20)) > 0)
	{
		buffer = ft_strsplit(read_buff, '\n');
		if (valid_piece(buffer))
		{
			if (!ret)
				ret = ft_lstnew(dup_array(buffer), sizeof(char *) * 4);
			else
				ft_lstadd(&ret, ft_lstnew(dup_array(buffer), sizeof(char *) * 4));
			ft_strclr(read_buff);
			result = read(fd, read_buff, 1);
			if (result < 0 || (result == 1 && !ft_strequ(read_buff, "\n")))
				throw_error("Bad input file", -1);
		}
		else
			throw_error("Bad input file", -1);
	}
	if (result < 0)
		throw_error("Error reading file", -1);
	return (ret);
}