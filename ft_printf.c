#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

 	i = 0;
 	if (!s)
 		return ;
 	while (s[i] != '\0')
 	{
 		write(1, &s[i], 1);
 		i++;
	}
}

int	ft_format(va_list *arg, int *len, const char *format)
{	
	// if (*format == 'c')
	// 	ft_printf_c(arg, len);
	// if (*format == 's')
	// 	ft_printf_s(arg, len);
	if (*format == 'p')
		ft_printf_p(arg, len);
	// if (*format == 'd' || *format == 'i')
	// 	ft_printf_d(arg, len);
	// if (*format == 'u')
	// 	ft_printf_u(arg, len);
	// if (*format == 'x')
	// 	ft_printf_x(arg, len);
	//  if (*format == 'X')
 	// 	ft_printf_upX(arg, len);
 	// if (*format == '%')
 	// 	ft_printf_percent(arg, len);
}

int	ft_printf(const char *format, ...)
{
 	int		len;
 	va_list	ap;

 	len = 0;
 	va_start(ap, format);
 	if (!format)
 		return(-1);
 	while (*format != '\0')
 	{
 		if (*format == '%')
 		{
 			format++;
 			ft_format(&ap, &len, format);
 		}
 		else
 		{
 			ft_putchar(*format);
 			len++;
 		}
 		format++;
 	}
 	return (len);
}

int main (void)
{
	int len2;
	int len;
	int a = 0;
	len = ft_printf ("%p\n", a);
	// len2 = printf ("%p\n", a);
		
	printf ("My print len: %d\n", len);
	// printf ("Original len: %d\n", len2);
}
