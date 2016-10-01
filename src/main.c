/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:28 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 00:31:43 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h> // Delete
#include <time.h> // Delete

int	main(int ac, char **av)
{
	t_list	*pieces;
	int		read_from;

	if (ac == 2)
	{
		if ((read_from = open(av[1], O_RDONLY)) == -1)
		{
			ft_putendl_fd("Could not open file");
			return (-1);
		}
		pieces = parse_file((read_from = open(av[1], O_RDONLY)));
		close(read_from);
		t_board *b = solve(pieces);
		ft_printjoin("\n", b->board, b->size);
	}
	else
		ft_putendl("usage: ./fillit pieces_file");
	return (0);
}
