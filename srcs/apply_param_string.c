/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   apply_param_string.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/09 14:12:53 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/09 15:53:53 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**width, precision, zero_pad, minus
**/

char	*apply_string(t_print *param, char *out, char *arg, int nb)
{
	int	len;
	int	i;

	len = ft_strlen(arg);
	if (param->precision != -1 && len > param->precision)
	{
		i = (param->minus_left == 0 ? nb - param->precision : 0);
		ft_memcpy(out + i, arg, param->precision);
	}
	else
	{
		i = (param->minus_left == 0 ? nb - len : 0);
		ft_memcpy(out + i, arg, len);
	}
	return (out);
}

char	*wstring_no_minus(t_print *param, char *out, wchar_t *arg, int nb)
{
	int	w_size;
	int	i;

	w_size = wstring_size(arg);
	if (param->precision != -1 && w_size > param->precision)
	{
		i = 0;
		w_size = wchar_size(arg[i++]);
		if (w_size > param->precision)
			return (out);
		while (w_size <= param->precision \
				&& wchar_size(arg[i]) <= param->precision - w_size)
			w_size = w_size + wchar_size(arg[i++]);
		i = nb - w_size;
		while (i < nb)
			i = wchar_create(*arg++, out, i);
	}
	else
	{
		i = nb - w_size;
		while (i < nb)
			i = wchar_create(*arg++, out, i);
	}
	return (out);
}

char	*wstring_minus(t_print *param, char *out, wchar_t *arg)
{
	int	w_size;
	int	i;

	i = 0;
	w_size = wstring_size(arg);
	if (param->precision != -1 && w_size > param->precision)
	{
		w_size = wchar_size(*arg);
		while (w_size <= param->precision)
		{
			i = wchar_create(*arg++, out, i);
			w_size = w_size + wchar_size(*arg);
		}
	}
	else
	{
		while (i < w_size)
			i = wchar_create(*arg++, out, i);
	}
	return (out);
}
