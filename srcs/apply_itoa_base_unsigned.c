/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_itoa_base_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:07:49 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 18:48:43 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		count_size(uintmax_t value, int base)
{
	size_t	nb;

	nb = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		nb++;
	}
	return (nb);
}

/** For unsigned conv -> u base 10 || o and O base 8 || x and X base 16 
*** out is filled with '0' when created, used for precision and #o
**/

char	*apply_itoa_base_unsigned(va_list ap, t_print *param, int base)
{
	char	tab[16];
	char	*out;
	size_t		nb;
	size_t		new_nb;
	uintmax_t	arg;

	arg = unsigned_convert(ap, param);
	ft_strncpy(tab, "0123456789abcdef", base);
	nb = count_size(arg, base);
	new_nb = check_param_unsigned(param, nb);
	if (!(out = ft_strcnew(new_nb, '0')))
		return (NULL);
	nb = new_nb - nb;
	if (nb > 0)
		apply_param_unsigned(param, out, nb);
	while (new_nb > nb)
	{
		new_nb--;
		out[new_nb] = tab[ft_abs(arg % base)];
		arg = arg / base;
	}
	nb = 0;
	if (param->index == 'X')
		ft_strupper(out);
	return (out);
}
