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

void	get_precision(const char **format, t_print *param, va_list ap)
{
	if (**format == '.')
	{
		(*format)++;
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
