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

/**
*** Precision wins on width => number of ' ' = width - precision
*** If #x, '0x' wins on width => must adjust number of spaces
*** If '#o', must leave one charater for '0'
**/

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

void	apply_no_minus_left(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	if (param->minus_left == 0)
	{
		i = 0;
		space = (param->precision == -1 ? param->width : param->width - param->precision);
	//	printf("space %d size %d\n", space, size);
		if (param->sharp_prefix == 2 && size == 2)
			space = 0; 
		else if (param->sharp_prefix == 2)
		{
			space = space - 2;
			size = size - 2;
		}
		else if (param->sharp_prefix == 1)
			size-- ;
		while (i < space && i < size && param->zero_pad == 0)
			out[i++] = ' ';
	//	printf("zero %d\n", param->zero_pad);
	//	printf("out %s\n", out);
		apply_sharp_prefix(param, out, i);
	//	printf("out %s\n", out);
	}
}

void	apply_minus_left(t_print *param, char *out, int nb, int *new_nb)
{
	int 	space;
	int	size;
	int	i;

	if (param->minus_left == 1)
	{	
	//	printf("new %d nb %d\n", *new_nb, nb);
		i = apply_sharp_prefix(param, out, 0);
		size = *new_nb - nb - i;
		space = (param->precision == -1 ? param->width - i : param->width - param->precision - i);
		space = (space > size ? size : space);
	//	printf("space %d\n", space);
		while (space > 0)
		{
			out[--(*new_nb)] = ' ';
			space--;
		}
		*new_nb = (space > 0 ? *new_nb - space : *new_nb);
	}
}
