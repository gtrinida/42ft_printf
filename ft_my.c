#include <stdio.h>
#include <stdarg.h>

int ft_print(va_list *arg, int num)
{
	int sym;
	sym = va_arg(*arg, int);
	printf("%d", sym);
	return(0);
}

int ft_printf(int num, ...)
{
	int i = 0;
    va_list ap;
    va_start(ap, num);
    while (num > i)
	{
		ft_print(&ap, num);
		i++;
	}
	va_end(ap);
	return(0);
}
int main()
{
    int fl;
    fl = ft_printf(5, 1, 5, 4, 5, 6);
}