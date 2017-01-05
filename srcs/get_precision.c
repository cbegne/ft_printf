/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_precision.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 16:03:41 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 17:19:03 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Precision = minimum number of digits to print for index dDioOuUxX (padded with '0'), 
*** maximum number of characters to print for index sS
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
