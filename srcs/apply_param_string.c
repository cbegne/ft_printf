#include "ft_printf.h"

/**width, precision, zero_pad, minus
**/

char	*string_no_minus_left(t_print *param, char *out, char *arg, int nb)
{
	int	len;
	int	i;

	len = ft_strlen(arg);	
	if (param->precision != -1 && len > param->precision)
	{
		i = nb - param->precision;	
		ft_strncpy(out + i, arg, param->precision);
	}
	else
	{
		i = nb - len;
		ft_strcpy(out + i, arg);
	}	
	return (out);
}

char	*string_minus_left(t_print *param, char *out, char *arg)
{
	int	len;

	len = ft_strlen(arg);	
	if (param->precision != -1 && len > param->precision)
		ft_memcpy(out, arg, param->precision);
	else
		ft_memcpy(out, arg, len);
	return (out);
}

char	*wstring_no_minus_left(t_print *param, char *out, wchar_t *arg, int nb)
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
		while (w_size <= param->precision && wchar_size(arg[i]) <= param->precision - w_size)
			w_size = w_size + wchar_size(arg[i++]);
		i = nb - w_size;
//		printf("i %i\n", i);
		while (i < nb)
		{
			i = wchar_create(*arg++, out, i);
//			w_size = w_size + wchar_size(*arg);
		}
	}
	else
	{
		i = nb - w_size;
		while (i < nb)
			i = wchar_create(*arg++, out, i);
	}
	return (out);
}

char	*wstring_minus_left(t_print *param, char *out, wchar_t *arg)
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
