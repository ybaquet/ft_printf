#include  "../ft_printf.h"

#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

void sprint(char *fmt, char *str)
{
	   printf(fmt, str);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, str);
	   printf("\n");
}

void sprint2(char *fmt, char *str1, char *str2)
{
	   printf(fmt, str1, str2);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, str1, str2);
	   printf("\n");
}

void iprint(char *fmt, int i)
{
	   printf(fmt, i);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, i);
	   printf("\n");
}


void iprint2(char *fmt, int i1, int i2)
{
	   printf(fmt, i1, i2);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, i1, i2);
	   printf("\n");
}

int main(void)
{
//	int i = 0xFFFFFFFF;
//	int j = 24;
//
//	printf("x:%x.\n", -1);
//
//	printf("d:%x.\n", i ^ (j - 1));

//	printf("<%*.*d>\n", 10, 5, -18);
//	printf("<%*.*X>\n", 10, 5, -18);
//	printf("<%*.*X>\n", 10, 5, 18);
//	printf("<%*.*x>\n", 10, 5, -18);
//	printf("<%*.*x>\n", 10, 5, 18);
//	printf("<%*.*x>\n", 10, 5, -18);
//	printf("<%*.*x>\n", 10, 5, 18);
//	   printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));

	//	ft_printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));
//
//	ft_printf(" %-3.2d %10.42d ", 10, -10);
//	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 30, 21, -18);
//	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);
//	ft_printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);

	iprint("%05.1d", 43);
	iprint("%05d", 43);
	iprint("this %d number", 17);
	iprint2(" %-3.2d %10.42d ", 1, -1);
	iprint("%10.6d ", 10);
	iprint2(" %-3.2d %10.42d ", 10, -10);
	iprint("%.d", 1);
//	   printf(" <%s>\n", "");

//	ft_printf(" <%s>\n", "");

//	   printf("%s", "0");
//	   fflush(stdout);
//	ft_printf("%s", "0");
//
//	printf("%s %s\n", "", "");
//	   fflush(stdout);
//	   ft_printf("%s %s\n", "", "");
//
//	   printf("%s %s\n", "", "");
//	   fflush(stdout);
//	ft_printf("%s %s\n", "", "");
//
//	   printf(" %1s %1s ", "123", "4567");
//	   fflush(stdout);
//	ft_printf(" %1s %1s ", "123", "4567");
//
//

//	printf("1: %7.5s.\n", "12345678");
//	printf("2: %7.0s.\n", "12345678");
//	printf("3: %7.s.\n", "12345678");
//	printf("4: %.7s.\n", "12345678");

//	sprint("this %s is empty", "");
//	sprint("%-32s", "abc");
//	sprint("%-32s", "abc");
//	sprint("%.7s", "hello");
//	sprint("%.3s", "hello");
//	sprint("<%.s>", "hello");
//	sprint("<%.s>", "hello");
//
	sprint2("%.5s%7s", "yo", "boi");
	sprint("%32s", "abc");
	sprint("%7.5s", "yolo");
	sprint("%s", NULL);
	sprint("%7.5s", NULL);

	//	   printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
//	ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
//	   printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
//	ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
//	   printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101);
//	ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101);

//	ft_printf("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
//	   printf("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
//	printf("---------------------------------------");

//	char *pt = "Ceci est une chaine";
//	   printf("%*s\n", 10, "coucous");
//	   fflush(stdout);
//	ft_printf("%*s\n", 10, "coucous");
//	   fflush(stdout);
///	   printf("<%p>, <%s>, <%10,15%>\n", pt, pt);
//	ft_printf("<%p>, <%s>, <%10,5%>\n", pt, pt);
//	while(1);
	write(2, "FIN\n", 4);
	return (0);
}
