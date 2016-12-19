/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_param_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 15:35:07 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 19:00:21 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*apply_param_unsigned(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	i = 0;
//	printf("prec %d\n", param->precision);
	space = param->width - param->precision;
//	printf("space %d\n", space);
	if (param->sharp_prefix == 2)
		space = space - 2;
	while (i < space && i < size)
		out[i++] = ' ';
	if (param->sharp_prefix == 2)
	{
		out[i++] = '0';
		out[i++] = 'x';
	}
	return (out);
}
