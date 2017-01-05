/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 11:17:32 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 16:14:16 by cbegne           ###   ########.fr       */
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
