/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:17:55 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 11:45:06 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	get_width(const char **format, t_print *param, va_list ap)
{
	if (ft_isdigit(**format))
	{
		param->width = ft_atoi((char*)*format);
		while (ft_isdigit(**format))
			(*format)++;
	}
	else if (**format == '*')
	{
		param->width = va_arg(ap, int);
		if (param->width < 0)
		{
			param->width = param->width * -1;
			param->minus_left = 1;
		}
		(*format)++;
	}
}

void	get_precision(const char **format, t_print *param, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
		param->precision = 0;
		if (**format == '*')
		{
			param->precision = va_arg(ap, int);
			if (param->precision < 0)
				param->precision = -1;
			(*format)++;
		}
		else if (ft_isdigit(**format))
		{
			param->precision = ft_atoi((char*)*format);
			while (ft_isdigit(**format))
				(*format)++;
		}
	}
}
