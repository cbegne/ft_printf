/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/14 18:04:22 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 19:21:19 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		is_length(char c)
{
	return ((c == 'h' || c == 'l' || c == 'j' || c == 'z') ? 1 : 0);
}

/** For signed index (dDi) :
*** none = int (4 bytes), hh = signed char (1 byte), h = signed short (2 bytes), 
*** l = signed long (8 bytes), ll = signed long long (8 bytes), 
*** j = intmax_t (max size), z = ssize_t (8 bytes)
*** Size in bytes are just for info and depends on systems
*** For unsigned index (uUoOxX) :
*** none = unsigned int, hh = unsigned char, h = unsigned short, l = unsigned long, 
*** ll = unsigned long long, j = uintmax_t, z = size_t
*** For c : none = char, l = wint_t
*** For C : none = wint_t
*** For s : none = char*, l = wchar_t*
*** For S : none = wchar_t*
**/ 

void	get_length(const char **format, t_print *param)
{
	while (is_length(**format))
	{
		if (**format == 'h')
		{
			if (param->length_h <= 2)
				param->length_h++;
		}
		else if (**format == 'l')
		{
			if (param->length_l <= 2)
				param->length_l++;
		}
		else if (**format == 'L')
			param->length_l = 2;
		else if (**format == 'j')
			param->length_j = 1;
		else if (**format == 'z')
			param->length_z = 1;
		(*format)++;
	}
}
