/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_p.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:51:05 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 18:27:58 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	ft_hex_p(int res)
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

void	ft_write_p(char *res, int i)
{
	char	tmp;

	i = 0;
	while (res[i] != '\0')
	{
		tmp = res[i];
		write (1, &tmp, 1);
		i++;
	}
	free(res);
	res = 0;
}

int	ft_check_len_p(unsigned long num, int *len)
{
	int	i;

	i = 0;
	write(1, "0x", 2);
	(*len) += 2;
	while (num > 0)
	{
		num = num / 16;
		i++;
		++(*len);
	}
	return (i - 1);
}

void	ft_printf_p(va_list *arg, int *len)
{
	unsigned long	num;
	unsigned int	rem;
	char			*res;
	char			tmp;
	int				i;

	num = va_arg(*arg, unsigned long);
	i = ft_check_len_p(num, len);
	if (num == 0)
	{
		write(1, "0", 1);
		(*len)++;
		return ;
	}
	res = malloc(sizeof(char) * (i + 2));
	res[i + 1] = '\0';
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
