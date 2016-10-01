/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mfernand <mfernand@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:36:28 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/30 19:32:54 by mfernand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

const char g_usage_string[] = "usage: ./fillit <pieces_file>";
const char g_example_string[] =
"Example file:\n\n"
"....\n"
"##..\n"
".#..\n"
".#..\n\n"

"....\n"
"####\n"
"....\n"
"....\n\n"

"#...\n"
"###.\n"
"....\n"
"....\n\n"

"....\n"
"##..\n"
".##.\n"
"....\n\n";

int	main(int ac, char **av)
{
	if (ac == 2)
		run_fillit(av[1]);
	else
	{
		ft_putendl(g_usage_string);
		ft_putstr(g_example_string);
	}
	return (0);
}
