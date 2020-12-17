#include  "../ft_printf.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


void
foo2(char *fmt, ...)
{
    va_list ap;
    int d;
    char c, *s;

    va_start(ap, fmt);
    while (*fmt)
        switch (*fmt ++) {
        case's':              /* chaîne */
            s = va_arg (ap, char *);
            printf("chaîne %s\n", s);
            break;
        case 'd':              /* entier */
            d = va_arg (ap, int);
            printf("int %d\n", d);
            break;
        case 'c':              /* caractère */
            /* need a cast here since va_arg only
               takes fully promoted types */
            c = va_arg (ap, int);
            printf("char %c\n", c);
            break;
        }
    va_end(ap);
}



int main(void)
{
	ft_printf("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
	printf   ("<Nb: %-*.*d, nb2=%*d, Hello:%sFIN>\n", 20, 10, 500, 10, 1, "Coucou");
	printf("---------------------------------------");
	return (0);
}
