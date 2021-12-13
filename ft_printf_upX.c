/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_upX.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:54:27 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 17:53:20 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_crutch_upx(unsigned int res, int *len)
{
	if (res < 10)
	{	
		res += '0';
		write (1, &res, 1);
	}
	else if (res == 10)
		write (1, "A", 1);
	else if (res == 11)
		write (1, "B", 1);
	else if (res == 12)
		write (1, "C", 1);
	else if (res == 13)
		write (1, "D", 1);
	else if (res == 14)
		write (1, "E", 1);
	else if (res == 15)
		write (1, "F", 1);
	++(*len);
	return ;
}

char	ft_hex_upx(int res)
{
	if (res < 10)
		return (res + '0');
	else if (res == 10)
		return ('A');
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
	return (0);
}

void	ft_write_upx(char *res, int i, int *len)
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

int	ft_check_len_upx(unsigned int num, int *len)
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
		ft_crutch_upx(num, len);
		return (0);
	}
	while (num > 0)
	{
		num = num / 16;
		i++;
	}
	return (i - 1);
}

void	ft_printf_upx(va_list *arg, int *len)
{
	unsigned int	num;
	unsigned int	rem;
	char			*res;
	char			tmp;
	int				i;

	num = (unsigned int)va_arg(*arg, unsigned int);
	i = ft_check_len_upx(num, len);
	if (!i)
		return ;
	res = malloc(sizeof(char) * (i + 1));
	res[++i] = '\0';
	i--;
	while (num > 0)
	{
		rem = num % 16;
		tmp = ft_hex_upx(rem);
		res[i] = tmp;
		num = num / 16;
		i--;
	}
	ft_write_upx(res, i, len);
}
