#include "ft_printf.h"

char ft_hex_p(int res)
{
	if (res < 10)
		return (res + '0');
	else if (res == 10)
		return('a');
	else if (res == 11)
		return ('b');
	else if (res == 12)
		return ('c');
	else if (res == 13)
		return ('d');
	else if (res == 14)
		return ('e');
	else if (res == 15)
		return ('f');
}
void ft_write_p(char *res, int i)
{
	char	tmp;

	i = 0;
	while(res[i] != '\0')
	{
		tmp = res[i];
		write (1, &tmp, 1);
		i++;
	}
	free(res);
	res = 0;
}
int ft_check_len_p(unsigned num)
{
	int i;
	
	i = 0;
	write(1, "0x", 2); //либо писать это в функции ft_write_p, тогда выведет просто 0, а не 0х0.
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i - 1);
}
void	ft_printf_p(va_list *arg, int *len)
{
	unsigned int	num;
	unsigned int	rem;
	char			*res;
	char			tmp;
	int				i;

	num = (unsigned int)va_arg(*arg, unsigned int);
	i = ft_check_len_p(num);
	if (num == 0)
	{
		write(1, "0", 1);
		return;
	}
	res = malloc(sizeof(char) * (i + 1));
	res[++i] = '\0';
	i--;
	while (num > 0)
	{
		rem = num % 16;
		tmp = ft_hex_p(rem);
		res[i] = tmp;
		num = num / 16;
		i--;
	}
	ft_write_p(res, i);
}
