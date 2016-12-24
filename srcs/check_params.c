/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:48:00 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 17:41:29 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** nb is the minimum size, no matter the width or precision.
*** max is the maximum size, according to width or precision.
*** Must add sharp prefix to the min size.
*** If #x and param->width - param->precision >=2, enough space for '0x' on width
*** If #x and param->width - param->precision < 2, not enough space for '0x' 
*** 	=> must add enough space
*** No impact of other flags.
**/
static int	weird_precision_zero(t_print *param, uintmax_t arg)
{
	if (arg == 0 && param->precision == 0)
	{
		if (param->index == 'x' || param->index == 'X' || \
			(param->index == 'o' && param->sharp_prefix == 0))
		{
			param->sharp_prefix = -1;
			param->count = param->width;
			return (param->width);
		}
	}
	return (-1);
}

int		check_param_unsigned(t_print *param, int nb, uintmax_t arg)
{
	int		max;
	
	if ((max = weird_precision_zero(param, arg)) != -1)
		return (max);
	max = ft_max(param->width, param->precision);
	if (param->sharp_prefix == 1)
	{
		if (param->index == 'o' && arg != 0)
			nb++;
		else if ((param->index == 'x' || param->index == 'X') && arg != 0)
		{
			if (param->width - param->precision == 1)
				max = max + 1;	
			else if (param->width - param->precision < 2)
				max = max + 2;
			nb = nb + 2;
			param->sharp_prefix = 2;
		}
		else
			param->sharp_prefix = 0;
	}
	nb = (max > nb ? max : nb);
	param->count = nb;
	return (nb);
}
