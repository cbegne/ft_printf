/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:40:18 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 19:24:01 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_index(char c)
{
	return ((c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || \
				c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'x' || \
				c == 'X' || c == 'c' || c == 'C') ? 1 : 0);
}

void	get_index(const char **format, t_print *param)
{
	if (is_index(**format))
	{
		param->index = **format;
		(*format)++;
	}
}
