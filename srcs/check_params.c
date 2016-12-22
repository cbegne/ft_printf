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

int		check_param_unsigned(t_print *param, int nb)
{
	int		max;
	
	max = 0;
	if (param->width != 0 || param->precision != -1)
		max = ft_max(param->width, param->precision);
	if (param->sharp_prefix == 1)
	{
		if (param->index == 'o')
			nb++;
		else if (param->index == 'x' || param->index == 'X')
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
