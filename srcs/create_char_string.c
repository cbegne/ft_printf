/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_char_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:02:53 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 17:41:24 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** For %, c and unofficial index (ie any other letter)
*** Width, minus_left and zero_pad have an impact
*** Flag '0' is ignored when flag '-' is present
**/

char	*only_write(va_list ap, t_print *param)
{
	char			*out;
	int				i;
	unsigned char	arg;

	arg = param->index;
	if (param->index == 'c')
		arg = (unsigned char)va_arg(ap, int);
	i = (param->width > 0 ? param->width : 1);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(i, '0') \
					: ft_strcnew(i, ' '))))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 0 ? i - 1 : 0);
	out[i] = (char)arg;
	return (out);
}

/** For index 's'
*** If arg = 0, write '(null)'. Can be cut with width or precision
*** (eg '00000(nu')
*** Width, precision, zero_pad and minus_left
*** Flag '0' is ignored when flag '-' is present
**/

char	*string_write(va_list ap, t_print *param)
{
	char	*out;
	char	*arg;
	int		nb;
	int		len;

	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	len = ft_strlen(arg);
	nb = check_param_string(param, len);
	if (!(out = param->zero_pad == 1 ? ft_strcnew(nb, '0') \
				: ft_strcnew(nb, ' ')))
		return (NULL);
	out = apply_string(param, out, arg, nb);
	return (out);
}
