/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_param_unsigned.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:35:54 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 11:42:48 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	apply_sharp_prefix(t_print *param, char *out, int i)
{
	if (param->sharp_prefix == 2)
	{
		out[i++] = '0';
		out[i++] = 'x';
	}
	if (param->sharp_prefix == 1)
		out[i++] = '0';
	return (i);
}

void		unsigned_no_minus(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	i = 0;
	if (param->precision <= -1)
		space = param->width;
	else
		space = param->width - param->precision;
	if (param->sharp_prefix == 2 && size == 2)
		space = 0;
	else if (param->sharp_prefix == 2)
	{
		space = space - 2;
		size = size - 2;
	}
	else if (param->sharp_prefix == 1)
		size--;
	while (i < space && i < size && param->zero_pad == 0)
		out[i++] = ' ';
	apply_sharp_prefix(param, out, i);
}

void		unsigned_minus(t_print *param, char *out, int nb, int *new_nb)
{
	int space;
	int	size;
	int	i;

	i = apply_sharp_prefix(param, out, 0);
	size = *new_nb - nb - i;
	if (param->precision <= -1)
		space = param->width - i;
	else
		space = param->width - param->precision - i;
	space = (space > size ? size : space);
	while (space > 0)
	{
		out[--(*new_nb)] = ' ';
		space--;
	}
	*new_nb = (space > 0 ? *new_nb - space : *new_nb);
}
