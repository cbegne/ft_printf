/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/13 16:30:07 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/19 18:59:27 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <locale.h>

int		main(void)
{
	int i;
	int j;
	int k = 945;
	char *l = setlocale(LC_ALL, "");

//	i = ft_printf("me |%C\n", k);
//	j = printf("it |%C\n", k);
//	i = ft_printf("me |%\n");
//	j = printf("it |%\n");
	i = ft_printf("me |%ls\n", "hello");
	j = printf("it |%ls\n", L"hello");
//	i = ft_printf("me |%.4S\n", L"é1é2é3é");
//	j = printf("it |%.4S\n", L"é1é2é3é");
	printf("%d %d\n", i, j);
	return (0);
}
