#include "ft_printf.h"

/**
*** Precision wins on width => number of ' ' = width - precision
*** If #x, '0x' wins on width => must adjust number of spaces
*** If '#o', must leave one charater for '0'
**/

void	signed_no_minus_left(t_print *param, char *out, int size)
{
	int	i;
	int	space;

	i = 0;
	space = (param->precision == -1 ? param->width : param->width - param->precision);
	if (space <= 0 && param->blank == 1)
		space = 1;
	while (i < space && i < size && param->zero_pad == 0)
		out[i++] = ' ';
//	printf("space %d size %d\n", space, size);
	i = (i > 0 ? i - 1 : i);
//	printf("i %d\n", i);
	if (param->sign != 0)
		out[i] = param->sign;
//	printf("out %s\n", out);
}

/** Sign or blank ' ' first, width ' ' at the end
**/

void	signed_minus_left(t_print *param, char *out, int nb, int *new_nb)
{
	int 	space;
	int	size;

//	printf("new %d nb %d\n", *new_nb, nb);
	size = *new_nb - nb;
	space = (param->precision == -1 ? param->width : param->width - param->precision);
	space = (space > size ? size : space);
//	printf("space %d\n", space);
	if (param->sign != 0)
	{	
		out[0] = param->sign;
		space--;
	}
	else if (param->blank == 1)
	{
		out[0] = ' ';
		space--;
	}
	while (space > 0)
	{
		out[--(*new_nb)] = ' ';
		space--;
	}
	*new_nb = (space > 0 ? *new_nb - space : *new_nb);
}
