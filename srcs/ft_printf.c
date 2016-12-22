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

int		ft_printf(const char *format, ...)
{
	va_list ap;
	int		nb;
	t_print	*param;
	char	*out;
	
	va_start(ap, format);
	nb = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			param = parse(&format, ap, &param);
			if ((out = convert_and_apply(ap, param)))
				ft_putstr(out);
			nb = nb + param->count;
		}
		else
		{
			ft_putchar(*format);
			nb++;
			format++;
		}
	}
	va_end(ap);
	return (nb);
}
