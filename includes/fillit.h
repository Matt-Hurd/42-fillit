/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/09/28 19:37:52 by mhurd             #+#    #+#             */
/*   Updated: 2016/09/28 19:38:07 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H
# include "libft.h"
#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>

void			throw_error(char *text, int num, int fd);
t_list			*parse_file(int fd);
char			**dup_array(char **in);

#endif
