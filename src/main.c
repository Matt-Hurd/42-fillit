/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:28 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/28 19:37:08 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"




#include <stdio.h>
#include <time.h>


int	main(int ac, char **av)
{
	t_list	*pieces;

	if (ac == 2)
	{
		clock_t begin = clock();
		pieces = parse_file(av[1]);
		while (pieces)
		{
			ft_printjoin("\n", (char **)(pieces->content), 4);
			ft_putstr("\n\n");
			pieces = pieces->next;
		}
		clock_t end = clock();
		double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
		printf("%f\n", time_spent);
	}
	else
		ft_putendl("usage: ./fillit pieces_file");
	return (0);
}
