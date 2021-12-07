#include "ft_printf.h"

char ft_hex_upX(int res)
{
	if (res < 10)
		return (res + '0');
	else if (res == 10)
		return('A');
	else if (res == 11)
		return ('B');
	else if (res == 12)
		return ('C');
	else if (res == 13)
		return ('D');
	else if (res == 14)
		return ('E');
	else if (res == 15)
		return ('F');
}
void ft_write_upX(char *res, int i)
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
int ft_check_len_upX(unsigned num)
{
	int i;
	
	i = 0;
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i - 1);
}
void	ft_printf_upX(va_list *arg, int *len)
{
	unsigned int	num;
	unsigned int	rem;
	char			*res;
	char			tmp;
	int				i;

	num = (unsigned int)va_arg(*arg, unsigned int);
	i = ft_check_len_upX(num);
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
		tmp = ft_hex_upX(rem);
		res[i] = tmp;
		num = num / 16;
		i--;
	}
	ft_write_upX(res, i);
}
