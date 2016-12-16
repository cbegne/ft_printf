/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_itoa_base_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:07:49 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/16 20:38:53 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_size(uintmax_t value, int base)
{
	int	nb;

	nb = 0;
//	if (base == 10 && value < 0)
//		nb++;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		nb++;
	}
	return (nb);
}

/** for unsigned conv -> u base 10 || o and O base 8 || x and X base 16 **/

char	*apply_itoa_base_unsigned(va_list ap, t_print *param, int base)
{
	char	tab[16];
	char	*out;
	int		nb;
	uintmax_t	arg;

	arg = unsigned_convert(ap, param);
	if (param->index == 'X')
		ft_strncpy(tab, "0123456789ABCDEF", base);
	else
		ft_strncpy(tab, "0123456789abcdef", base);
	nb = count_size(arg, base);
	// nb = nb + check_param()
	if (!(out = ft_strnew(nb)))
		return (NULL);
	while (--nb >= 0)
{
		out[nb] = tab[ft_abs(arg % base)];
		arg = arg / base;
	}
	return (out);
}
