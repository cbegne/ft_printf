/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:05:39 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 16:05:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_print		*parse(const char **format, va_list ap, t_print **param)
{
	ft_bzero(*param, sizeof(t_print));
	(*param)->precision = -1;
	while ((is_flag(**format) || ft_isdigit(**format) || **format == '.' || is_length(**format) || is_index(**format)) && (*param)->index == 0)
	{
		get_flag(format, *param);
		get_width(format, *param, ap);
		get_precision(format, *param, ap);
		get_length(format, *param);
		get_index(format, *param);
	}
	if ((*param)->index == 0 && **format == '%')
	{
		ft_putchar(**format);
		(*param)->count++;
	}
	return (*param);
}
