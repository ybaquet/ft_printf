#include  "../ft_printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
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
//	   printf(" %-3.2d %10.42d ", 10, -10);
//	ft_printf(" %-3.2d %10.42d ", 10, -10);
//	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 30, 21, -18);
	   printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);
	ft_printf(" *%-*.*d* *%*.*d* \n", 4, 5, 10, 10, 21, -18);
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
	return (0);
}
