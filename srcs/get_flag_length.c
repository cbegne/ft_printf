/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_flag_length.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 17:20:57 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 11:41:22 by cbegne           ###   ########.fr       */
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
		(*format)++;
	}
}

int		is_length(char c)
{
	return ((c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 1 : 0);
}

void	get_length(const char **format, t_print *param)
{
	while (is_length(**format))
	{
		if (**format == 'h')
		{
			if (param->length_h <= 2)
				param->length_h++;
		}
		else if (**format == 'l')
		{
			if (param->length_l <= 2)
				param->length_l++;
		}
		else if (**format == 'L')
			param->length_l = 2;
		else if (**format == 'j')
			param->length_j = 1;
		else if (**format == 'z')
			param->length_z = 1;
		(*format)++;
	}
}
