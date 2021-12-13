/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_x.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:57:10 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 17:50:00 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_crutch(unsigned int res, int *len)
{
	if (res < 10)
	{	
		res += '0';
		write (1, &res, 1);
	}
	else if (res == 10)
		write (1, "a", 1);
	else if (res == 11)
		write (1, "b", 1);
	else if (res == 12)
		write (1, "c", 1);
	else if (res == 13)
		write (1, "d", 1);
	else if (res == 14)
		write (1, "e", 1);
	else if (res == 15)
		write (1, "f", 1);
	++(*len);
	return ;
}

char	ft_hex_x(int res)
{
	if (res < 10)
		return (res + '0');
	else if (res == 10)
		return ('a');
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
	return (0);
}

void	ft_write_x(char *res, int i, int *len)
{
	char	tmp;

	i = 0;
	while (res[i] != '\0')
	{
		tmp = res[i];
		write (1, &tmp, 1);
		i++;
		++(*len);
	}
	free(res);
	res = 0;
}

int	ft_check_len_x(unsigned int num, int *len)
{
	int	i;

	i = 0;
	if (num == 0)
	{
		write(1, "0", 1);
		++(*len);
		return (0);
	}
	if (num >= 1 && num <= 15)
	{	
		ft_crutch(num, len);
		return (0);
	}
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i - 1);
}

void	ft_printf_x(va_list *arg, int *len)
{
	unsigned int	num;
	unsigned int	rem;
	char			*res;
	char			tmp;
	int				i;

	num = va_arg(*arg, unsigned int);
	i = ft_check_len_x(num, len);
	if (!i)
		return ;
	res = malloc(sizeof(char) * (i + 1));
	res[++i] = '\0';
	i--;
	while (num > 0)
	{
		rem = num % 16;
		tmp = ft_hex_x(rem);
		res[i] = tmp;
		num = num / 16;
		i--;
	}
	ft_write_x(res, i, len);
}
