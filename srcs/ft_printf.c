/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:31:07 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/10 17:12:36 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	printf_no_arg(const char **format, char **s, int len_s)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = *s;
	while (**format && **format != '%')
	{
		i++;
		(*format)++;
	}
	*s = ft_strnnjoin(*s, *format - i, len_s, i);
	free(tmp);
	return (i);
}

/** Starting printf. Variable number of arguments '...' => use of va_list
*** Printf returns number of char written (param->count)
*** Every argument starts with a %, else write
*** Const char, so send &format
*** Steps : parsing data (flags, length, width, precision), converting va_arg
*** and applying
**/

static int	printf_arg(const char **format, va_list ap, char **s, int len_s)
{
	t_print param;
	char	*out;
	char	*tmp;
	int		len_out;

	parse(format, ap, &param);
	out = convert_and_apply(ap, &param);
	len_out = param.count;
	if (param.count != -1)
	{
		tmp = *s;
		*s = ft_strnnjoin(*s, out, len_s, len_out);
		free(tmp);
		free(out);
	}
	return (len_out);
}

int			ft_printf(const char *format, ...)
{
	va_list ap;
	int		nb;
	char	*s;
	int		count;

	va_start(ap, format);
	if (!(s = ft_strdup("")))
		return (-1);
	nb = 0;
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if ((count = printf_arg(&format, ap, &s, nb)) != -1)
				nb = nb + count;
			else
				break ;
		}
		else
		{
			nb = nb + printf_no_arg(&format, &s, nb);
		}
	}
	write(1, s, nb);
	free(s);
	va_end(ap);
	return (count == -1 ? -1 : nb);
}
