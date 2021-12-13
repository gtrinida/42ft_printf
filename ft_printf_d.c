/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_d.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:50:39 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 13:50:47 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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

void	ft_putnbr_fd(int n, int fd, int *len)
{
	int				i;
	int				lenght;
	char			num[10000];
	long long int	number;

	number = n;
	i = 0;
	lenght = ft_nlen(n);
	*len += lenght;
	num[lenght--] = '\0';
	if (number < 0)
	{
		num[0] = '-';
		number = number * (-1);
	}
	else if (number == 0)
		num[0] = '0';
	while (number > 0)
	{
		num[lenght--] = '0' + (number % 10);
		number = number / 10;
	}
	while (num[i] != '\0')
		write(fd, &num[i++], 1);
}

void	ft_printf_d(va_list *arg, int *len)
{
	int	n;

	n = va_arg(*arg, int);
	ft_putnbr_fd(n, 1, len);
}
