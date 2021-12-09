#include "ft_printf.h"

void	ft_printf_percent(va_list *arg, int *len)
{
	char	percent;

	percent = '%';
	write (1, &percent, 1);
	++(*len);
}
