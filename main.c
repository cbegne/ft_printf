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

int		main(void)
{
	int i;
	int j;	

	i = ft_printf("1me %5.o\n", 0);
	j = printf("1it %5.o\n", 0);
	printf("%d %d\n", i, j);
	i = ft_printf("2me %5.0o\n", 0);
	j = printf("2it %5.0o\n", 0);
	printf("%d %d\n", i, j);
	i = ft_printf("3me %5.x\n", 0);
	j = printf("3it %5.x\n", 0);
	printf("%d %d\n", i, j);
	i = ft_printf("4me %5.0x\n", 0);
	j = printf("4it %5.0x\n", 0);
	printf("%d %d\n", i, j);
	return (0);
}
