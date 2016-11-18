/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhurd <mhurd@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/05 14:18:59 by mhurd             #+#    #+#             */
/*   Updated: 2016/10/05 14:26:33 by mhurd            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

void	add_piece(t_list **ret, char **buf, int *count)
{
	if (*ret)
		ft_lstadd_back(ret, make_piece(clean(buf), *count));
	else
		*ret = make_piece(clean(buf), *count);
}

void	validate_next_line(char *r_buf, int fd, int *result)
{
	ft_strclr(r_buf);
	*result = read(fd, r_buf, 1);
	if (*result < 0 || (*result == 1 && !ft_strequ(r_buf, "\n")))
		throw_error("error", -1, fd);
}
