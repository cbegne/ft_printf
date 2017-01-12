/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:40:18 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 11:40:50 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char_index(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		return (1);
	if (is_index(c) == 0)
		return (1);
	return (0);
}

int		is_index(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' \
			|| c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' \
			|| c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

void	get_index(const char **format, t_print *param)
{
	if (ft_isalpha(**format) || **format == '%')
	{
		if (**format == 'i')
			param->index = 'd';
		else
			param->index = **format;
		(*format)++;
	}
}
