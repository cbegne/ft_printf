/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_param_signed.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 13:11:03 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 15:06:23 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Precision wins on width => number of ' ' = width - precision
*** If blank and zero_pad, must have one space first
**/

void	signed_no_minus(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	i = 0;
	space = (param->precision == -1 ? param->width : \
			param->width - param->precision);
	if ((param->zero_pad == 1 || space <= 0) && param->blank == 1)
		out[i++] = ' ';
	while (i < space && i < size && param->zero_pad == 0)
		out[i++] = ' ';
	i = (i > 0 ? i - 1 : i);
	if (param->sign != 0)
		out[i] = param->sign;
}

/** Size = number of char to print that is not arg
*** Space = number of space to be printed (width, width - precision or size)
*** Sign or blank first, width at the end
*** Must change new_nb to copy arg in itoa_base_signed.c
**/

void	signed_minus(t_print *param, char *out, int nb, int *new_nb)
{
	int	space;
	int	size;

	size = *new_nb - nb;
	space = (param->precision == -1 ? param->width : \
			param->width - param->precision);
	space = (space > size ? size : space);
	if (param->sign != 0)
	{
		out[0] = param->sign;
		space--;
	}
	else if (param->blank == 1)
	{
		out[0] = ' ';
		space--;
	}
	while (space > 0)
	{
		out[--(*new_nb)] = ' ';
		space--;
	}
	*new_nb = (space > 0 ? *new_nb - space : *new_nb);
}
