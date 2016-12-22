/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 15:31:45 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 18:44:24 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

typedef struct		s_print
{
	int				sharp_prefix;
	int				zero_pad;
	int				minus_left;
	int				plus_sign;
	int				blank;

	int				length_h;
	int				length_l;
	int				length_j;
	int				length_z;

	int				width;
	int				precision;
	int				length;
	int				index;
	int				count;
}					t_print;

int		ft_printf(const char *format, ...);

t_print	*parse(const char **format, va_list ap, t_print **param);
int		is_flag(char c);
int		is_length(char c);
int		is_index(char c);
void	get_flag(const char **format, t_print *param);
void	get_width(const char **format, t_print *param, va_list ap);
void	get_precision(const char **format, t_print *param, va_list ap);
void	get_length(const char **format, t_print *param);
void	get_index(const char **format, t_print *param);

char	*convert_and_apply(va_list ap, t_print *param);
uintmax_t	unsigned_convert(va_list ap, t_print *param);
char	*apply_itoa_base_unsigned(va_list ap, t_print *param, int base);
int		check_param_unsigned(t_print *param, int nb);
void	apply_param_unsigned(t_print *param, char *out, int size);

void	ft_putchar(char c);
int		ft_atoi(char *s);
int		ft_isdigit(int n);
void	ft_bzero(void *s, size_t n);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_strcnew(size_t size, char c);
int		ft_abs(int n);
void	ft_putstr(char *s);
void		ft_strupper(char *s);
int	ft_max(int nb1, int nb2);

#endif
