/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 17:05:39 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 13:19:39 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	is_legit(const char *format)
{
	if (is_flag(*format) || ft_isdigit(*format) || *format == '.' \
			|| is_length(*format) || ft_isalpha(*format) || *format == '%' \
			|| *format == '*')
		return (1);
	return (0);
}

static void	adjust_param(t_print *param)
{
	if (param->precision != -1 && is_char_index(param->index) == 0)
		param->zero_pad = 0;
	if (param->sign == 1)
		param->blank = 0;
	if (param->minus_left == 1)
		param->zero_pad = 0;
	if (param->index == 'p')
		param->sharp_prefix = 1;
}

void		parse(const char **format, va_list ap, t_print *param)
{
	ft_bzero(param, sizeof(t_print));
	(param)->precision = -1;
	while (is_legit(*format) == 1 && (param)->index == 0)
	{
		get_flag(format, param);
		get_width(format, param, ap);
		get_precision(format, param, ap);
		get_length(format, param);
		get_index(format, param);
	}
	adjust_param(param);
}
