/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:31:07 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/16 20:31:47 by cbegne           ###   ########.fr       */
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
			out = convert_and_apply(ap, param);
			ft_putstr(out);
			//count
		}
		else
		{
			ft_putchar(*format);
			format++;
			nb++;
		}
	//	printf("f %c\n", *format);
	}
	va_end(ap);
	return (nb);
}
