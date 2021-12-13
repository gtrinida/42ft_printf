/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_s.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:52:47 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 16:32:40 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_printf_s(va_list *arg, int *len)
{
	char	*str;
	int		i;

	i = 0;
	str = va_arg(*arg, char *);
	if (str == NULL)
		*len = *len + write(1, "(null)", 6);
	else
	{
		while (str[i] != '\0')
		{
			write (1, &str[i], 1);
			++(*len);
			i++;
		}
	}
}
