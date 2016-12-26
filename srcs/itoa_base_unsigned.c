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
	int	nb;

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
*** out is filled with '0' when created, used for precision
**/

char	*itoa_base_unsigned(va_list ap, t_print *param, int base)
{
	char		*tab;
	char		*out;
	int		nb;
	int		new_nb;
	uintmax_t	arg;

	tab = "0123456789abcdef";
	arg = unsigned_convert(ap, param);
	nb = count_size(arg, base);
	new_nb = check_param_unsigned(param, nb, arg);
	if (!(out = ft_strcnew(new_nb, '0')))
		return (NULL);
	if (param->sharp_prefix == -1)
		nb = 0;
	param->minus_left == 0 ? unsigned_no_minus_left(param, out, new_nb - nb) : unsigned_minus_left(param, out, nb, &new_nb);
//	printf("nb %d new_nb %d\n", nb, new_nb);
	while (nb--)
	{
		out[--new_nb] = tab[ft_abs(arg % base)];
//		printf("out[%d] = %c\n", new_nb, out[new_nb]);
		arg = arg / base;
	}
	if (param->index == 'X')
		ft_strupper(out);
	return (out);
}
