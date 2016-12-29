#include "ft_printf.h"

static int		count_size(intmax_t value, int base)
{
	int	nb;

	nb = 0;
	if (value == 0)
		return (1);
	while (value != 0)
	{
		value = value / base;
		nb++;
	}
	return (nb);
}

/** For signed conv -> base 10
*** out is filled with '0' when created, used for precision
*** sign = -1 if must not print 0
**/

char	*itoa_base_signed(va_list ap, t_print *param, int base)
{
	char		*tab;
	char		*out;
	int		nb;
	int		new_nb;
	intmax_t	arg;

	tab = "0123456789";
	arg = signed_convert(ap, param);
	nb = count_size(arg, base);
	new_nb = check_param_signed(param, nb, arg);
	if (!(out = ft_strcnew(new_nb, '0')))
		return (NULL);
	if (param->precision == -2)
		nb = 0;
	param->minus_left == 0 ? signed_no_minus_left(param, out, new_nb - nb) : signed_minus_left(param, out, nb, &new_nb);
//	printf("nb %d new_nb %d\n", nb, new_nb);
	while (nb--)
	{
		out[--new_nb] = tab[ft_abs(arg % base)];
	//	printf("out[%d] = %c\n", new_nb, out[new_nb]);
		arg = arg / base;
	}
	return (out);
}
