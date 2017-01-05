/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:31:07 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/16 20:51:17 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** Starting printf. Variable number of arguments '...' => use of va_list
*** Printf returns number of char written (param->count)
*** Every argument starts with a %, else write
*** Const char, so send &format
*** Steps : parsing data (flags, length, width, precision), converting va_arg and applying
**/

static int	start_printf(const char **format, va_list ap)
{
	t_print *param;
	char	*out;
	int	nb;

	param = parse(format, ap, &param);
	out = convert_and_apply(ap, param);
	write(1, out, param->count);
	nb = param->count;
	free(out);
	free(param);
	return (nb);
}

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int	nb;
	
	va_start(ap, format);
	nb = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			nb = nb + start_printf(&format, ap);
		}
		else
		{
			write(1, format++, 1);
			nb++;
		}
	}
	va_end(ap);
	return (nb);
}
