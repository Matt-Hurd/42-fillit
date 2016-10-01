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
	int		fd;

	if (ac == 2)
	{
		clock_t begin = clock();
		pieces = parse_file((fd = open(av[1], O_RDONLY)));
		close(fd);
		t_board *b = solve(pieces);
		clock_t end = clock();
		ft_printjoin("\n", b->board, b->size);
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("\n%f\n", time_spent);
	}
	else
		ft_putendl("usage: ./fillit pieces_file");
	return (0);
}
