#include "ft_printf.h"

/** for %, c and unofficial index (ie any other letter)
*** width, minus_left and zero_pad have an impact
*** flag '0' is ignored when flag '-' is present
*** ==> gérer lc avec C <==
**/

static int	char_convert(va_list ap, t_print *param)
{
	int	arg;

	arg = param->index;
//	if (param->index == 'c' && param->length_l == 1)
//		arg = va_arg(ap, wint_t); //go C ?
	if (param->index == 'c')
		arg = va_arg(ap, int);
	return (arg);
}

/** if minus_left, no blank
**/

static	void	adjust_param(t_print *param)
{
	if (param->minus_left == 1)
		param->blank = 0;
}

char	*only_write(va_list ap, t_print *param)
{
	char 	*out;
	int 	i;
	int	arg;
	
	arg = char_convert(ap, param);
	adjust_param(param);
	i = (param->width > 0 ? param->width : 1);
	if (!(out = ft_strnew(i)))
		return (NULL);
	param->count = i;
	i = (param->minus_left == 1 ? i : 0);
//	printf("i %d\n", i);
	if (i > 0)
	{
		while (i > 0)
			out[--i] = ' ';
	}	
	else if (i == 0)
	{
//		printf("zero %d\n", param->zero_pad);
		while (i < param->width - 1)
			out[i++] = (param->zero_pad == 0 ? ' ' : '0');
	}
	out[i] = arg;
	return (out);
}

static char	*string_convert(va_list ap)
{
	char	*arg;

//	if (param->length_l == 1)
//		arg = va_arg(ap, wchar_t*); //go S
	arg = va_arg(ap, char*);
	if (arg == NULL)
		arg = "(null)";
	return (arg);
}

char	*string_write(va_list ap, t_print *param)
{
	char	*out;
	char	*arg;
	int	nb;
	
	arg = string_convert(ap);
	nb = check_param_string(param, arg);
	adjust_param(param);
	if (!(out = param->zero_pad == 1 ? ft_strcnew(nb, '0') : ft_strcnew(nb, ' ')))
		return (NULL);
//	printf("%s\n", out);
	out = param->minus_left == 0 ? string_no_minus_left(param, out, arg, nb) : string_minus_left(param, out, arg);
	return (out);
}
