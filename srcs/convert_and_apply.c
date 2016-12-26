/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:46:13 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/16 20:17:09 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** With %, impact of width and minus_left
**/

static char	*only_write(t_print *param)
{
	char 	*out;
	int 	i;
	
	i = (param->width > 0 ? param->width : 1);
	if (!(out = ft_strnew(i)))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 0 ? 0 : i);
//	printf("%d\n", i);
	if (i > 0)
	{
		while (i > 0)
			out[--i] = ' ';
	}	
	else
	{
		while (i < param->width - 1)
			out[i++] = ' ';
	}
	out[i] = '%';
	return (out);
}
	
char	*convert_and_apply(va_list ap, t_print *param)
{
	char *out;

	if (param->index == '%')
		out = only_write(param);
	else if (param->index == 'd' || param->index == 'D')
		out = itoa_base_signed(ap, param, 10);
	else if (param->index == 'u' || param->index == 'U')
		out = itoa_base_unsigned(ap, param, 10);
	else if (param->index == 'o' || param->index == 'O')	
		out = itoa_base_unsigned(ap, param, 8);
	else if (param->index == 'x' || param->index == 'X')
		out = itoa_base_unsigned(ap, param, 16);
//	else if (param->index == 's' || param->index == 'p')
		// apply (char*)
//	else if (param->index == 'S')
		//apply (wchar_t*)
//	else if (param->index == 'c')
		//apply (char)
//	else if (param->index == 'C')
		// apply (wchar_t)
//	else if (param->index == 0)
		//
	else
		out = NULL;
	return (out);
}

/** param->blank is effective only on positive values, already impacted on get_flag
*** param->sign = '+' or '-' directly
**/

static void	adjust_param(t_print *param, intmax_t arg)
{		
	if (arg < 0)
	{
		param->sign = '-';
		param->blank = 0;
	}
	else if (param->sign == 1)
		param->sign = '+';
}

/** for i, d and D **/

intmax_t	signed_convert(va_list ap, t_print *param)
{
	intmax_t	arg;
	
	if (param->length_j == 1)
		arg = va_arg(ap, intmax_t);
	else if (param->length_z == 1)
		arg = va_arg(ap, size_t);
	else if (param->length_l == 2)
		arg = va_arg(ap, long long int);
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

/** for u, U, o, O, x and X **/

uintmax_t	unsigned_convert(va_list ap, t_print *param)
{
	uintmax_t	arg;

	if (param->length_j == 1)
		arg = va_arg(ap, uintmax_t);
	else if (param->length_z == 1)
		arg = va_arg(ap, ssize_t);
	else if (param->length_l == 2)
		arg = va_arg(ap, unsigned long long int);
	else if (param->length_l == 1 || param->index == 'U' || param->index == 'O')
		arg = va_arg(ap, unsigned long int);
	else if (param->length_h == 1)
		arg = (short)va_arg(ap, unsigned int);
	else if (param->length_h == 2)
		arg = (char)va_arg(ap, unsigned int);
	else
		arg = va_arg(ap, unsigned int);
	return (arg);
}
