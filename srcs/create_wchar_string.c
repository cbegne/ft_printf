#include "ft_printf.h"

int	wchar_size(wint_t c)
{
	if (c <= 0x7F)
		return (1);
	if (c <= 0x7FF)
		return (2);
	if (c <= 0xFFFF)
		return (3);
	if (c <= 0x10FFFF)
		return (4);
	return (0);
}

int	wstring_size(wchar_t *arg)
{
	int	i;
	int	w_size;
	
	i = 0;
	w_size = 0;
	while (arg[i])
		w_size = w_size + wchar_size(arg[i++]);
	return (w_size);
}

int	wchar_create(wint_t c, char *out, int i)
{		
	if (c <= 0x7F)
		out[i++] = c;
	else if (c <= 0x7FF)
	{
		out[i++] = ((c >> 6) | 0xC0);
		out[i++] = ((c & 0x3F) | 0x80);
	}
	else if (c <= 0xFFFF)
	{
		out[i++] = ((c >> 12) | 0xE0);
		out[i++] = (((c >> 6) & 0x3F) | 0x80);
		out[i++] = ((c & 0x3F) | 0x80);
	}
	else if (c <= 0x10FFFF)
	{
		out[i++] = ((c >> 18) | 0xF0);
		out[i++] = (((c >> 12) & 0x3F) | 0x80);
		out[i++] = (((c >> 6) & 0x3F) | 0x80);
		out[i++] = ((c & 0x3F) | 0x80);
	}
	return (i);
}

char	*wchar_write(va_list ap, t_print *param)
{
	wint_t	arg;
	char	*out;
	int	w_size;
	int	i;

	arg = va_arg(ap, wint_t);
//	printf("arg %i\n", arg);
	w_size = wchar_size(arg);
//	printf("w %i\n", w_size);
	i = (w_size > param->width ? w_size : param->width);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(i, '0') : ft_strcnew(i, ' '))))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 0 ? i - w_size : 0);
	wchar_create(arg, out, i);
	return (out);
}

char	*wstring_write(va_list ap, t_print *param)
{
	wchar_t	*arg;
	char	*out;
	int	w_size;
	int	nb;

	arg = va_arg(ap, wchar_t*);
	if (arg == NULL)
		arg = L"(null)";
	w_size = wstring_size(arg);
	nb = check_param_wstring(param, w_size, arg);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(nb, '0') : ft_strcnew(nb, ' '))))
		return (NULL);
	out = param->minus_left == 0 ? wstring_no_minus_left(param, out, arg, nb) : wstring_minus_left(param, out, arg);
	return (out);
}
