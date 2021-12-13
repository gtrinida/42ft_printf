/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_u.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:53:01 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 14:56:12 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_len(unsigned int n)
{
	unsigned int	number;
	int				i;

	i = 0;
	number = n;
	if (number < 0)
	{
		number = number * (-1);
		i++;
	}
	else if (number == 0)
		i++;
	while (number > 0)
	{
		number = number / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(unsigned int n)
{
	unsigned int	number;
	int				len;
	char			*nbr;

	number = n;
	len = ft_len(n);
	nbr = malloc(sizeof(char) * (len + 1));
	if (!nbr)
		return (0);
	nbr[len--] = '\0';
	if (number == 0)
		nbr[len] = '0';
	while (number > 0)
	{
		nbr[len--] = '0' + (number % 10);
		number = number / 10;
	}
	return (nbr);
}

void	ft_printf_u(va_list *arg, int *len)
{
	unsigned int	u;
	char			*res;

	u = va_arg(*arg, unsigned int);
	res = ft_itoa(u);
	u = 0;
	while (res[u] != '\0')
	{
		write(1, &res[u], 1);
		u++;
		++(*len);
	}
	free(res);
	res = 0;
}
