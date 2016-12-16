/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:04:22 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 19:21:19 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
		else if (**format == 'j')
			param->length_j = 1;
		else if (**format == 'z')
			param->length_z = 1;
		(*format)++;
	}
}
