#include "ft_printf.h"

void	ft_printf_s(va_list *arg, int *len)
{
	char	*str;
	int		i;

	i = 0;
	str = (char *)va_arg(*arg, int);
	while (str[i] != '\0')
	{
		write (1, &str[i], 1);
		++*(len);
		i++;
	}
}
