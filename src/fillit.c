/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 19:15:27 by mfernand          #+#    #+#             */
/*   Updated: 2016/09/30 22:16:47 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char g_file_open_error[] = "Could not open the file";

void	run_fillit(const char *file_path)
{
	t_list	*pieces;
	t_board	*b;
	int		read_from;

	if ((read_from = open(file_path, O_RDONLY)) == -1)
	{
		ft_putendl_fd(g_file_open_error, 2);
		return ;
	}
	pieces = parse_file(read_from);
	close(read_from);
	b = solve(pieces);
	ft_printjoin("\n", b->board, b->size);
	ft_putendl("");
}
