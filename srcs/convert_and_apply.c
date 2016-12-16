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

char	*convert_and_apply(va_list ap, t_print *param)
{
	char	*out;
	
//	if (param->index == 'i' || param->index == 'd' || param->index == 'D')
		//apply (intmax_t)
	if (param->index == 'u')
		out = apply_itoa_base_unsigned(ap, param, 10);
	else if (param->index == 'o' || param->index == 'O')	
		out = apply_itoa_base_unsigned(ap, param, 8);
	else if (param->index == 'x' || param->index == 'X')
		out = apply_itoa_base_unsigned(ap, param, 16);
//	else if (param->index == 's' || param->index == 'p')
		// apply (char*)
//	else if (param->index == 'S')
		//apply (wchar_t*)
//	else if (param->index == 'c')
		//apply (char)
//	else if (param->index == 'C')
		// apply (wchar_t)
	return (out);
}

/** for i, d and D **/
/*
intmax_t	signed_convert(va_list ap, t_print *param)
{
	intmax_t	arg;
	
	arg = va_arg(ap, intmax_t);
	if (param->length_z == 1)
		arg = (size_t)arg;
	else if (param->length_l == 2)
		arg = (long long int)arg;
	else if (param->length_l == 1)
		arg = (long int)arg;
	else if (param->length_h == 1)
		arg = (short int)arg;
	else if (param->length_h == 2)
		arg = (char)arg;
	return (arg);
}
*/
/** for u, o, O, x and X **/

uintmax_t	unsigned_convert(va_list ap, t_print *param)
{
	uintmax_t	arg;

	arg = va_arg(ap, uintmax_t);
	if (param->length_z == 1)
		arg = (ssize_t)arg;
	else if (param->length_l == 2)
		arg = (unsigned long long int)arg;
	else if (param->length_l == 1)
		arg = (unsigned long int)arg;
	else if (param->length_h == 1)
		arg = (unsigned short int)arg;
	else if (param->length_h == 2)
		arg = (unsigned char)arg;
	return (arg);
}
