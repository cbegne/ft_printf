/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_wchar_string.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 15:25:36 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/10 18:28:02 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			wchar_size(wint_t c)
{
	if (c >= 0 && c <= 0x7f)
		return (1);
	if (c >= 0x80 && c <= 0x7ff)
		return (2);
	if ((c >= 0x800 && c <= 0xd7ff) || (c >= 0xe000 && c <= 0xffff))
		return (3);
	if (c >= 0x10000 && c <= 0x10ffff)
		return (4);
	return (0);
}

int			wstring_size(wchar_t *arg)
{
	int		i;
	int		w_size;

	i = 0;
	w_size = 0;
	while (arg[i])
		w_size = w_size + wchar_size(arg[i++]);
	return (w_size);
}

char		*wchar_write(va_list ap, t_print *param)
{
	wint_t	arg;
	char	*out;
	int		w_size;
	int		i;

	arg = va_arg(ap, wint_t);
	if ((w_size = wchar_size(arg)) == 0)
	{
		param->count = -1;
		return (NULL);
	}
	i = (w_size > param->width ? w_size : param->width);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(i, '0') \
					: ft_strcnew(i, ' '))))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 0 ? i - w_size : 0);
	wchar_create(arg, out, i);
	return (out);
}

char		*wstring_write(va_list ap, t_print *param)
{
	wchar_t	*arg;
	char	*out;
	int		w_size;
	int		nb;

	arg = va_arg(ap, wchar_t*);
	nb = 0;
	if (arg == NULL)
		arg = L"(null)";
	w_size = wstring_size(arg);
	nb = check_param_wstring(param, w_size, arg);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(nb, '0') \
					: ft_strcnew(nb, ' '))))
		return (NULL);
	out = param->minus_left == 0 ? wstring_no_minus(param, out, arg, nb) \
		  : wstring_minus(param, out, arg);
	return (out);
}
