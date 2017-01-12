/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   convert_and_apply.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/16 18:46:13 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/12 13:02:21 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char			*convert_and_apply(va_list ap, t_print *param)
{
	char		*out;

	if (param->index == 'd' || param->index == 'D')
		out = itoa_base_signed(ap, param, 10);
	else if (param->index == 'u' || param->index == 'U')
		out = itoa_base_unsigned(ap, param, 10);
	else if (param->index == 'o' || param->index == 'O')
		out = itoa_base_unsigned(ap, param, 8);
	else if (param->index == 'x' || param->index == 'X' || param->index == 'p')
		out = itoa_base_unsigned(ap, param, 16);
	else if (param->index == 'S' || (param->index == 's' \
				&& param->length_l == 1))
		out = wstring_write(ap, param);
	else if (param->index == 's')
		out = string_write(ap, param);
	else if (param->index == 'C' || (param->index == 'c' \
				&& param->length_l == 1))
		out = wchar_write(ap, param);
	else if (param->index == 'b')
		out = itoa_base_unsigned(ap, param, 2);
	else if (param->index != 0)
		out = only_write(ap, param);
	else
		out = NULL;
	return (out);
}
