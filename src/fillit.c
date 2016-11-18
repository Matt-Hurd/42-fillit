/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/30 19:15:27 by mfernand          #+#    #+#             */
/*   Updated: 2016/10/05 16:18:02 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char g_file_open_error[] = "error";

void	run_fillit(const char *file_path)
{
	t_list	*pieces;
	t_board	*b;
	int		read_from;

	if ((read_from = open(file_path, O_RDONLY)) == -1)
	{
		ft_putendl_fd(g_file_open_error, 1);
		return ;
	}
	pieces = parse_file(read_from);
	close(read_from);
	b = solve(pieces);
	print_board(b);
}
