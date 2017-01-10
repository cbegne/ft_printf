/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_signed.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:20:57 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 15:54:43 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Sign = '+' if arg is positive or '-' if negative, directly
*** No blank if value is negative
**/

static void		adjust_param(t_print *param, intmax_t arg)
{
	if (arg < 0)
	{
		param->sign = '-';
		param->blank = 0;
	}
	else if (param->sign == 1)
		param->sign = '+';
}

/** for i, d and D, get argument and apply length
*** Put in max length, ie intmax_t
**/

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

static int		count_size(intmax_t value, int base)
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

/** For signed conv -> base 10
*** Steps : get argument ('arg'), get size according to arg and check_params.c
*** (width, precision, size and blank), create string to be printed ('out'),
*** fill in 'out'
*** according to params, fill in 'out' with arg
*** Nb = size of arg, new_nb = size of arg according to params
*** Out is filled with '0' when created, used for precision
*** Precision = -2 if must not print when arg = 0 (see check_params.c)
**/

char			*itoa_base_signed(va_list ap, t_print *param, int base)
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
