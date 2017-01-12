/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_itoa_base_unsigned.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 19:07:49 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 13:02:24 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static uintmax_t	unsigned_convert(va_list ap, t_print *param)
{
	uintmax_t	arg;

	if (param->length_j == 1)
		arg = va_arg(ap, uintmax_t);
	else if (param->length_l == 2)
		arg = va_arg(ap, unsigned long long int);
	else if (param->length_z == 1 || param->index == 'p')
		arg = va_arg(ap, ssize_t);
	else if (param->length_l == 1 || param->index == 'U' || param->index == 'O')
		arg = va_arg(ap, unsigned long int);
	else if (param->length_h == 1)
		arg = (unsigned short)va_arg(ap, unsigned int);
	else if (param->length_h == 2)
		arg = (unsigned char)va_arg(ap, unsigned int);
	else
		arg = va_arg(ap, unsigned int);
	return (arg);
}

static int			count_size(uintmax_t value, int base)
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

char				*itoa_base_unsigned(va_list ap, t_print *param, int base)
{
	char		*tab;
	char		*out;
	int			nb;
	int			new_nb;
	uintmax_t	arg;

	tab = "0123456789abcdef";
	arg = unsigned_convert(ap, param);
	nb = count_size(arg, base);
	new_nb = check_param_unsigned(param, nb, arg);
	param->count = new_nb;
	if (!(out = ft_strcnew(new_nb, '0')))
		return (NULL);
	if (param->precision == -2)
		nb = 0;
	param->minus_left == 0 ? unsigned_no_minus(param, out, new_nb - nb) \
	: unsigned_minus(param, out, nb, &new_nb);
	while (nb--)
	{
		out[--new_nb] = tab[ft_abs(arg % base)];
		arg = arg / base;
	}
	if (param->index == 'X')
		ft_strupper(out);
	return (out);
}
