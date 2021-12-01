#include "ft_printf.h"

// int	ft_len(int n)
// {
// 	int long	number;
// 	int			i;

// 	i = 0;
// 	number = n;
// 	if (number < 0)
// 	{
// 		number = number * (-1);
// 		i++;
// 	}
// 	else if (number == 0)
// 		i++;
// 	while (number > 0)
// 	{
// 		number = number / 10;
// 		i++;
// 	}
// 	return (i);
// }

// char	*ft_itoa(int n)
// {
// 	int long	number;
// 	int			len;
// 	char		*nbr;

// 	number = n;
// 	len = ft_len(n);
// 	nbr = malloc(sizeof(char) * (len + 1));
// 	if (!nbr)
// 		return (0);
// 	nbr[len--] = '\0';
// 	if (number < 0)
// 	{
// 		nbr[0] = '-';
// 		number = number * (-1);
// 	}
// 	else if (number == 0)
// 		nbr[len] = '0';
// 	while (number > 0)
// 	{
// 		nbr[len--] = '0' + (number % 10);
// 		number = number / 10;
// 	}
// 	return (nbr);
// }

int	ft_nlen(int n)
{
	long long int	number;
	int				count;

	count = 0;
	number = n;
	if (number < 0)
	{
		number = number * (-1);
		count++;
	}
	if (number == 0)
		count++;
	while (number > 0)
	{
		number = number / 10;
		count++;
	}
	return (count);
}

void	ft_putnbr_fd(int n, int fd)
{
	int				i;
	int				len;
	char			num[10000];
	long long int	number;

	number = n;
	i = 0;
	len = ft_nlen(n);
	num[len--] = '\0';
	if (number < 0)
	{
		num[0] = '-';
		number = number * (-1);
	}
	else if (number == 0)
		num[0] = '0';
	while (number > 0)
	{
		num[len--] = '0' + (number % 10);
		number = number / 10;
	}
	while (num[i] != '\0')
	{
		write(fd, &num[i++], 1);
	}
}
//не выводит len, доработать
int	ft_printf_d(va_list *arg, int *len)
{
	int n;

	n = va_arg(*arg, int);
	ft_putnbr_fd(n, 1);
	return (*len);
}
