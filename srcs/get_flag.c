/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 19:59:08 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 11:31:22 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_flag(char c)
{
	return ((c == '#' || c == '0' || c == '-' || c == '+' || c == ' ') ? 1 : 0);
}

void	get_flag(const char **format, t_print *param)
{
	while (is_flag(**format))
	{
		if (**format == '#')				
			param->sharp_prefix = 1;
		else if (**format == '0')
			param->zero_pad = 1;
		else if (**format == '-')
			param->minus_left = 1;
		else if (**format == '+')
			param->sign = 1;
		else if (**format == ' ')
			param->blank = 1;
		if (param->sign == 1 && param->blank == 1)
			param->blank = 0;
		(*format)++;
	}
}
