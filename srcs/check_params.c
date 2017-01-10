/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_params.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/19 11:48:00 by cbegne            #+#    #+#             */
/*   Updated: 2017/01/10 13:53:08 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/** If precision = 0 and arg = 0, printf may write nothing (not even 0)
*** Param->precision = -2 if must not print 0 nor flag_prefix
*** Must always print sharp_prefix with index 'p'
**/

static int	weird_precision_zero(t_print *param)
{
	if (param->precision == 0)
	{
		if (param->index == 'x' || param->index == 'X' || \
		((param->index == 'o' || param->index == 'O') && \
param->sharp_prefix == 0) || param->index == 'd' || param->index == 'D' || \
		param->index == 'u' || param->index == 'U')
		{
			param->precision = -2;
			param->sharp_prefix = 0;
			param->count = param->width;
			return (param->count);
		}
		else if (param->index == 'p')
			param->precision = -2;
	}
	return (-1);
}

/** Nb is the minimum size, no matter the width or precision.
*** Max is the maximum size, according to width or precision.
*** Must add sharp prefix to the min size.
*** If #x and width - precision >=2, enough space for '0x' on width
*** If #x and width - precision < 2, not enough space for '0x'
*** 	=> must add enough space
*** No impact of other flags
**/

int			check_param_unsigned(t_print *param, int nb, uintmax_t arg)
{
	int		max;

	if (arg == 0 && (max = weird_precision_zero(param)) != -1)
		return (max);
	max = ft_max(param->width, param->precision);
	if (param->sharp_prefix == 1)
	{
		if ((param->index == 'o' || param->index == 'O') && arg != 0)
			nb++;
		else if (param->index == 'p' || \
				((param->index == 'x' || param->index == 'X') && arg != 0))
		{
			if (param->index == 'p' && param->precision == -2)
				nb = 0;
			if (param->width - param->precision == 1)
				max = max + 1;
			else if (param->width - param->precision < 1)
				max = max + 2;
			nb = nb + 2;
			param->sharp_prefix = 2;
		}
		else
			param->sharp_prefix = 0;
	}
	return (max > nb ? max : nb);
}

/** Must add sign and/or blank ' ' no matter the width or precision
*** No addition if width is > 0 or bigger than precision
*** No impact of other flags
**/

int			check_param_signed(t_print *param, int nb, intmax_t arg)
{
	int		max;

	if (arg == 0 && (max = weird_precision_zero(param)) != -1)
		return (max);
	max = ft_max(param->width, param->precision);
	if (param->sign != 0)
		nb++;
	if (param->sign != 0 && (param->width == 0 \
				|| param->width <= param->precision))
		max++;
	if (param->blank == 1)
		nb++;
	if (param->blank == 1 && (param->width == 0 \
				|| param->width <= param->precision))
		max++;
	nb = (max > nb ? max : nb);
	param->count = nb;
	return (nb);
}

/** If precision, string shorted
*** If no precision, width or size of string
*** No impact of other flags
**/

int			check_param_string(t_print *param, int len)
{
	int		nb;

	if (param->precision != -1 && len > param->precision)
		nb = ft_max(param->width, param->precision);
	else
		nb = ft_max(param->width, len);
	param->count = nb;
	return (nb);
}

/** If precision, string shorted. Tricky part: the size of one wchar_t
*** varies from 1 to 4.
*** If a wchar_t is too big for the precision allowed, do not print
*** wchar_t and stop at the previous one (if any).
*** If no precision, width or size of string (same as normal string)
**/

int			check_param_wstring(t_print *param, int w_size, wchar_t *arg)
{
	int		nb;

	if (param->precision != -1 && w_size > param->precision)
	{
		nb = 0;
		while (nb <= param->precision \
				&& wchar_size(*arg) <= param->precision - nb)
			nb = nb + wchar_size(*arg++);
		if (param->width > nb)
			nb = nb + (param->width - nb);
	}
	else
		nb = ft_max(param->width, w_size);
	param->count = nb;
	return (nb);
}
