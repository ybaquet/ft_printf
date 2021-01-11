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

void pprint(char *fmt, void *p)
{
	   printf(fmt, p);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, p);
	   printf("\n");
}

void xprint(char *fmt, long u)
{
	   printf(fmt, u);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, u);
	   printf("\n");
}

void cprint(char *fmt, char c)
{
	   printf(fmt, c);
	   printf("\n");
	   fflush(stdout);
	ft_printf(fmt, c);
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

int main__(void)
{
	   printf("<%d>\n", -2147483647);
	ft_printf("<%d>\n", -2147483648);

	cprint("%-10c", '0');
	cprint("%c", '0');
	cprint("<%-2c>", '0');

	   printf("<%*c>\n", -2, '0');
	ft_printf("<%*c>\n", -2, '0');

	xprint("%x", 4294u);
	xprint("%x", 4294967294u);
	   printf("<%05%>\n");
	ft_printf("<%05%>\n");
	   printf("<%5c>\n", 52);
	ft_printf("<%5c>\n", 52);
	   printf("<%0-5%>\n");
	ft_printf("<%0-5%>\n");
	   printf("hello, %s.\n", "gavin");
	ft_printf("hello, %s.\n", "gavin");
	   printf("<%-05%>\n");
	ft_printf("<%-05%>\n");
	   printf("<%p>\n", NULL);
	ft_printf("<%p>\n", NULL);
	   printf("<%X>\n", 0);
	ft_printf("<%X>\n", 0);
	   printf("<%d>\n", 0);
	ft_printf("<%d>\n", 0);

	for(int i=0;i<1000;i++)
		ft_printf("%s%s", "hello", "world");

	int n = 254;
	printf ("%010X hexadecimal with upper case letters.\n", n);
	printf ("%x hexadecimal with lower case letters.\n", n);
	char *pt = "une chaine";
	pprint("<%020p>", pt);
	pprint("<%-020p>", pt);
	iprint("<%020d>", 10);
	iprint("<%-020d>", 10);
	ft_printf("%10%");

		int i = 0xFFFFFFFF;
	int j = 24;

	printf("x:%x.\n", -1);

	printf("d:%x.\n", i ^ (j - 1));

	printf("<%*.*d>\n", 10, 5, -18);
	printf("<%*.*X>\n", 10, 5, -18);
	printf("<%*.*X>\n", 10, 5, 18);
	printf("<%*.*x>\n", 10, 5, -18);
	printf("<%*.*x>\n", 10, 5, 18);
	printf("<%*.*x>\n", 10, 5, -18);
	printf("<%*.*x>\n", 10, 5, 18);
	   printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));

		ft_printf("ret = %d\n", printf("%%p::[%010d]\n", -8473));

	ft_printf(" %-3.2d %10.42d ", 10, -10);
	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 30, 21, -18);
	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);
	ft_printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);
	iprint("%.0d", 0);
	iprint("%.0d", 0);
	iprint("%0++8.3i", 8375);
	iprint("%0+8.3i", -8375);
	iprint("%0+8.5i", 8375);
	iprint("%0+8.5i", -8375);
	iprint("<%010d>", 2563);
	iprint("<%010d>", -2563);
	iprint("<%-10.8d>", -2550);
	iprint("<%10.8d>", -2551);
	iprint("<%5.8d>", -2552);
	iprint("<%0-8.5d>", 34);
	iprint("<%0-8.5d>", -34);
	iprint("<%-8.5d>", 34);
	iprint("<%-8.5d>", -34);
	iprint("<%-5d>", -2561);
	iprint("<%-10.8d>", -2562);
	iprint("<%010d>", -2563);
	iprint("<%010d>", 2564);
	iprint("<%10d>", 2565);
	iprint("<%15d>", -2566);
	iprint("<%-15d>", -2567);


		ft_printf("%-5d", -2562);
	ft_printf("%-5d", -2562);
	ft_printf("%-5d", -2562);
	ft_printf("%-5d", -2562);
	ft_printf("%-5d", -2562);
	ft_printf("%-5d", -2562);
	iprint("%-5d", -2562);
	iprint("%07d", -54);
	iprint("%05.1d", 43);
	iprint("%05d", 43);
	iprint("this %d number", 17);
	iprint2(" %-3.2d %10.42d ", 1, -1);
	iprint("%10.6d ", 10);
	iprint2(" %-3.2d %10.42d ", 10, -10);
	iprint("%.d", 1);



	   printf(" <%s>\n", "");

	ft_printf(" <%s>\n", "");

	   printf("%s", "0");
	   fflush(stdout);
	ft_printf("%s", "0");

	printf("%s %s\n", "", "");
	   fflush(stdout);
	   ft_printf("%s %s\n", "", "");

	   printf("%s %s\n", "", "");
	   fflush(stdout);
	ft_printf("%s %s\n", "", "");

	   printf(" %1s %1s ", "123", "4567");
	   fflush(stdout);
	ft_printf(" %1s %1s ", "123", "4567");



	printf("1: %7.5s.\n", "12345678");
	printf("2: %7.0s.\n", "12345678");
	printf("3: %7.s.\n", "12345678");
	printf("4: %.7s.\n", "12345678");

	sprint("this %s is empty", "");
	sprint("%-32s", "abc");
	sprint("%-32s", "abc");
	sprint("%.7s", "hello");
	sprint("%.3s", "hello");
	sprint("<%.s>", "hello");
	sprint("<%.s>", "hello");


		sprint2("%.5s%7s", "yo", "boi");
	sprint("%32s", "abc");
	sprint("%-7.3s", "yolo");
	sprint("%s", NULL);
	sprint("%7.5s", NULL);

		   printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	   printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	ft_printf(" *%-*.*d* *%*.*d* ", 6, 2, 102, 10, 21, -101);
	   printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101);
	ft_printf(" 0*%0-*.*d*0 0*%0*.*d*0 ", 6, 2, 102, 10, 21, -101);

	ft_printf("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
	   printf("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
	printf("---------------------------------------");

//	char *pt = "Ceci est une chaine";
//	   printf("%*s\n", 10, "coucous");
//	   fflush(stdout);
//	ft_printf("%*s\n", 10, "coucous");
//	   fflush(stdout);
//	   printf("<%p>, <%s>, <%10,15%>\n", pt, pt);
	ft_printf("<%p>, <%s>, <%10,5%>\n", pt, pt);
//	while(1);
	write(2, "FIN\n", 4);
	return (0);
}
