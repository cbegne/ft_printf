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

/** apply flags to tab : first characters
*** out is filled with '0' when created
*** Precision wins on width => number of ' ' = width - precision
*** If #x, '0x' wins on width => must adjust number of spaces
*** If '#o', must leave one charater for '0'
**/

void	apply_param_unsigned(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	i = 0;
	space = param->width - param->precision;
	if (param->sharp_prefix == 2 && size == 2)
		space = 0; 
	else if (param->sharp_prefix == 2)
		space = space - 2;
	else if (param->sharp_prefix == 1)
		size-- ;
	while (i < space && i < size)
		out[i++] = ' ';
	if (param->sharp_prefix == 2)
	{
		out[i++] = '0';
		out[i++] = 'x';
	}
}
