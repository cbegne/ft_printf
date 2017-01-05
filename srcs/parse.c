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

/** No zero_pad '0' if precision >= 0, except for char_index
*** No zero_pad '0' if minus_left '-'
*** No blank ' ' if sign '+'
*** Always sharp_prefix '0x' if index 'p'
**/

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

/** Struct param to keep all parsing data. Everything = 0, except precision = -1
*** Save info until index is found : sSpdDioOuUxXcC or % or any letter
**/

t_print		*parse(const char **format, va_list ap, t_print **param)
{
	*param = ft_memalloc(sizeof(t_print));
	(*param)->precision = -1;
	while ((is_flag(**format) || ft_isdigit(**format) || **format == '.' || is_length(**format) || ft_isalpha(**format) || **format == '%' || **format == '*') && (*param)->index == 0)
	{
		get_flag(format, *param);
		get_width(format, *param, ap);
		get_precision(format, *param, ap);
		get_length(format, *param);
		get_index(format, *param);
	}
	adjust_param(*param);
	return (*param);
}
