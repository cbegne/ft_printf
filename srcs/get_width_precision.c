/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_precision.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:17:55 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 17:17:58 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Width = minimum number of digits / characters to print (padded with ' ')
*** Can be modified with zero_pad, to pad with '0'
*** When '*', size to be given in first va_arg (cannot have more than one '*')
**/

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

/** Precision = minimum number of digits to print for index dDioOuUxX
*** (padded with '0'), maximum number of characters to print for index sS
*** Size determined by number after '.'
*** When '*', size to be given in first va_arg
*** Precision cannot be negative
**/

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
