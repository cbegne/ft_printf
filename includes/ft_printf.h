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
# include <wchar.h>
# include <unistd.h>

typedef struct		s_print
{
	int				sharp_prefix;
	int				zero_pad;
	int				minus_left;
	int				sign;
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
int		is_char_index(char c);
int		is_index(char c);
void	get_flag(const char **format, t_print *param);
void	get_width(const char **format, t_print *param, va_list ap);
void	get_precision(const char **format, t_print *param, va_list ap);
void	get_length(const char **format, t_print *param);
void	get_index(const char **format, t_print *param);

char	*convert_and_apply(va_list ap, t_print *param);
uintmax_t	unsigned_convert(va_list ap, t_print *param);
intmax_t	signed_convert(va_list ap, t_print *param);
char	*itoa_base_unsigned(va_list ap, t_print *param, int base);
char	*itoa_base_signed(va_list ap, t_print *param, int base);
int		check_param_unsigned(t_print *param, int nb, uintmax_t arg);
int		check_param_signed(t_print *param, int nb, intmax_t arg);
void	unsigned_no_minus_left(t_print *param, char *out, int size);
void	unsigned_minus_left(t_print *param, char *out, int nb, int *new_nb);
void	signed_no_minus_left(t_print *param, char *out, int size);
void	signed_minus_left(t_print *param, char *out, int nb, int *new_nb);
char	*only_write(va_list ap, t_print *param);
char	*string_write(va_list ap, t_print *param);
char	*wchar_write(va_list ap, t_print *param);
char	*wstring_write(va_list ap, t_print *param);
int	check_param_string(t_print *param, int len);
int	check_param_wstring(t_print *param, int w_size, wchar_t *arg);
char	*string_no_minus_left(t_print *param, char *out, char *arg, int nb);
char	*string_minus_left(t_print *param, char *out, char *arg);
int	wchar_size(wint_t c);
int	wstring_size(wchar_t *arg);
int	wchar_create(wint_t c, char *out, int i);
char	*wstring_no_minus_left(t_print *param, char *out, wchar_t *arg, int nb);
char	*wstring_minus_left(t_print *param, char *out, wchar_t *arg);

int		ft_atoi(char *s);
int		ft_isdigit(int n);
void	ft_bzero(void *s, size_t n);
char	*ft_strncpy(char *dst, char *src, size_t len);
char	*ft_strcpy(char *dst, char *src);
char	*ft_strcnew(size_t size, char c);
int		ft_abs(int n);
void		ft_strupper(char *s);
int	ft_max(int nb1, int nb2);
void	*ft_memalloc(size_t size);
int	ft_isalpha(int c);
size_t	ft_strlen(char *s);
void	*ft_memcpy(void *dst, const void *src, size_t nb);
char	*ft_strdup(const char *s);

#endif
