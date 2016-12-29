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
