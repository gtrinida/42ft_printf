/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 13:57:30 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 18:05:54 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return ;
	while (s[i] != '\0')
	{
		write(1, &s[i], 1);
		i++;
	}
}

void	ft_format(va_list *arg, int *len, const char *format)
{	
	if (*format == 'c')
		ft_printf_c(arg, len);
	if (*format == 's')
		ft_printf_s(arg, len);
	if (*format == 'p')
		ft_printf_p(arg, len);
	if (*format == 'd' || *format == 'i')
		ft_printf_d(arg, len);
	if (*format == 'u')
		ft_printf_u(arg, len);
	if (*format == 'x')
		ft_printf_x(arg, len);
	if (*format == 'X')
		ft_printf_upx(arg, len);
	if (*format == '%')
		ft_printf_percent(len);
}

int	ft_printf(const char *format, ...)
{
	int		len;
	va_list	ap;

	len = 0;
	va_start(ap, format);
	if (!format)
		return (-1);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			ft_format(&ap, &len, format);
		}
		else
		{
			ft_putchar(*format);
			len++;
		}
		format++;
	}
	va_end(ap);
	return (len);
}
