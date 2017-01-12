/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:20:57 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 11:46:34 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void			adjust_param(t_print *param, intmax_t arg)
{
	if (arg < 0)
	{
		param->sign = '-';
		param->blank = 0;
	}
	else if (param->sign == 1)
		param->sign = '+';
}

static intmax_t		signed_convert(va_list ap, t_print *param)
{
	intmax_t	arg;

	if (param->length_j == 1)
		arg = va_arg(ap, intmax_t);
	else if (param->length_l == 2)
		arg = va_arg(ap, long long int);
	else if (param->length_z == 1)
		arg = va_arg(ap, size_t);
	else if (param->length_l == 1 || param->index == 'D')
		arg = va_arg(ap, long int);
	else if (param->length_h == 1)
		arg = (short)va_arg(ap, int);
	else if (param->length_h == 2)
		arg = (char)va_arg(ap, int);
	else
		arg = va_arg(ap, int);
	adjust_param(param, arg);
	return (arg);
}

static int			count_size(intmax_t value, int base)
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

char				*itoa_base_signed(va_list ap, t_print *param, int base)
{
	char		*tab;
	char		*out;
	int			nb;
	int			new_nb;
	intmax_t	arg;

	tab = "0123456789";
	arg = signed_convert(ap, param);
	nb = count_size(arg, base);
	new_nb = check_param_signed(param, nb, arg);
	if (!(out = ft_strcnew(new_nb, '0')))
		return (NULL);
	if (param->precision == -2)
		nb = 0;
	param->minus_left == 0 ? signed_no_minus(param, out, new_nb - nb) \
	: signed_minus(param, out, nb, &new_nb);
	while (nb--)
	{
		out[--new_nb] = tab[ft_abs(arg % base)];
		arg = arg / base;
	}
	return (out);
}
