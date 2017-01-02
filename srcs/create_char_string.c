#include "ft_printf.h"

/** if minus_left, no blank


static	void	adjust_param(t_print *param)
{
	if (param->minus_left == 1)
		param->blank = 0;
}
**/
/** for %, c and unofficial index (ie any other letter)
*** width, minus_left and zero_pad have an impact
*** flag '0' is ignored when flag '-' is present
*** ==> gérer lc avec C <==
**/

char	*only_write(va_list ap, t_print *param)
{
	char 	*out;
	int 	i;
	int	arg;
	
	arg = param->index;
	if (param->index == 'c')
		arg = va_arg(ap, int);
//	adjust_param(param);
	i = (param->width > 0 ? param->width : 1);
	if (!(out = (param->zero_pad == 1 ? ft_strcnew(i, '0') : ft_strcnew(i, ' '))))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 0 ? i - 1 : 0);
//	printf("i %d\n", i);
	out[i] = arg;
	return (out);
}

/** for s index
*** if arg = 0, write '(null)'. Can be cut with width or precision (eg '00000(nu')
*** width, precision, zero_pad and minus_left
*** flag '0' is ignored when flag '-' is present
**/

char	*string_write(va_list ap, t_print *param)
{
	char	*out;
	char	*arg;
	int	nb;
	int	len;
	
	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	len = ft_strlen(arg);
	nb = check_param_string(param, len);
//	adjust_param(param);
	if (!(out = param->zero_pad == 1 ? ft_strcnew(nb, '0') : ft_strcnew(nb, ' ')))
		return (NULL);
//	printf("%s\n", out);
	out = param->minus_left == 0 ? string_no_minus_left(param, out, arg, nb) : string_minus_left(param, out, arg);
	return (out);
}
