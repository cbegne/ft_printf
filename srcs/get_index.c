/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:40:18 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 19:24:01 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_char_index(char c)
{
	if (c == 'c' || c == 'C' || c == 's' || c == 'S' || c == '%')
		return (1);
	if (is_index(c) == 0)
		return (1);
	return (0);
}

/** s = string of chars, S = unicode string of chars, p = printable chars of a void*, 
*** d or i = signed int, D = signed long int (same as ld), o = octal, 
*** O = long octal (same as lo), u = unsigned int, U = unsigned long int (same as lu), 
*** x = hexadecimal with lower letters, X = hexadecimal with upper letters, 
*** c = char, C = unicode char, % = print one %
**/

int		is_index(char c)
{
	if (c == 's' || c == 'S' || c == 'p' || c == 'd' || c == 'D' || c == 'i' || c == 'o' || c == 'O' || c == 'u' || c == 'U' || c == 'x' || c == 'X' || c == 'c' || c == 'C' || c == '%')
		return (1);
	return (0);
}

/** Any letter other than index above works as index c, with the letter being the char to print
*** Same behaviour of index 'i' and 'd'
**/

void	get_index(const char **format, t_print *param)
{
	if (ft_isalpha(**format) || **format == '%')
	{
		if (**format == 'i')
			param->index = 'd';
		else
			param->index = **format;
		(*format)++;
	}
}
