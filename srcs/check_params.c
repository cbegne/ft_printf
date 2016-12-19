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

int		check_param_unsigned(t_print *param, int nb)
{
	int		max;
	
	max = -1;
	if (param->width != 0 || param->precision != -1)
		max = (param->width >= param->precision ? param->width : param->precision);
	if (param->sharp_prefix == 1)
	{
		if (param->index == 'o' && max < nb)
			nb++;
		else if (param->index == 'x' || param->index == 'X')
		{
			nb = nb + 2;
			max = max + 2;
			param->sharp_prefix = 2;
		}
		else 
			param->sharp_prefix = 0;
	}
	nb = (max > nb ? max : nb);
	param->count = nb;
	return (nb);
}
