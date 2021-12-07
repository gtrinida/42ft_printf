#include "ft_printf.h"

void	ft_printf_c(va_list *arg, int *len)
{
	char	*result;
	result = (char *)va_arg(*arg, int);
		*len++;
	write(1, &result, 1);
}
