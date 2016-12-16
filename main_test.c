/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cbegne <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/11 14:27:24 by cbegne            #+#    #+#             */
/*   Updated: 2016/12/14 19:10:12 by cbegne           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <wchar.h>
#include <inttypes.h>
#include <locale.h>

int		main(void)
{
	char	*ptr = "abc";
	long int	c = -100000000000000000;
	int	d = 2560;
	int	x = 0xff;
	int number = -5;
	char *s = "little";
	
	setlocale(LC_ALL, "");
	printf("** precision **\n");
	printf("t %.5d\n", d);
	printf("t %.5s\n", s);
	printf("t %.5x\n", x);
	printf("%#.*X\n", 4, x);
	printf("%#.*X\n", -4, x);
	printf("t %.*s\n", -5, s);
	printf("t %.*d\n", -5, d);
	printf("t %.*x\n", -5, x);
	printf("%.*10d\n", 5, d);
	printf("%.-5s\n", s);
	printf("%.0s\n", s);
	printf("%.s\n", s);
	printf("%#.0x\n", 0);
	printf("%#x\n", 0);
	printf("%#10.+5d\n", number);
	
	printf("\n** caractères spéciaux **\n");
	printf("%C\n", 0xFF76);
	printf("%C\n", 547);
	
	printf("\n** width **\n");
	printf("%*d and a %10s word.\n", 5, number, s);
	printf("%10d\n", number);
	printf("%*d\n", -10, number);
	printf("%*0d\n", 10, number);
	printf("%-*5d\n", 10, number);
	printf("%*-d\n", 10, number);
	
	printf("\n** signed unsigned **\n");	
	printf("%d or %u\n", number, number);
	number = (unsigned int)number;
	printf("%d or %u\n", number, number);

	printf("\n** flags **\n");
	printf("%#x\n", x);
	printf("%#o\n", d);
	printf("%05x\n", x);
	printf("%010s\n", s);
	printf("% d\n", d);
	printf("%     d\n", d);
	printf("% d\n", number);
	printf("%+10d\n", d);
	printf("%-10d\n", d);
	printf("%-#10x\n", x);
	printf("%#-10x\n", x);
	printf("%.1s\n", s);
	printf("%.1d\n", d);
	printf("%-10s\n", s);
	printf("%+d\n", number);
	printf("%+d\n", d);
	printf("% + 05d\n", d);
	printf("%10+.+5 # d\n", d);

	printf("\n** length **\n");
	printf("ls %ls\n", s);
	printf("lls %jjs\n", s);
	printf("hs %hs\n", s);
	printf("ld %ld\n", d);
	printf("hd %hd\n", d);
	printf("hhd %hhd\n", d);
	printf("-ld %lu\n", -d);
	printf("-hd %hu\n", -d);
	printf("-hhd %hhu\n", -d);

	printf("\n** index **\n");	
	printf("%%%d%\n", d);
	printf("%+0%d%\n", d);
	printf("%p\n", ptr);
	printf("%zd\n", c);
	printf("%zu\n", c);
	c = (unsigned long int)c;
	printf("%ld\n", c);
	printf("%zu\n", c);
	printf("%lu\n", sizeof(wchar_t));
	printf("%lu\n", sizeof(wint_t));
	printf("%lu\n", sizeof(c));
	printf("%#+ .50yi\n", d);
	
	return (0);
}
