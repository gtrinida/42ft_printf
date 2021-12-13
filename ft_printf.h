/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gtrinida <gtrinida@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:00:57 by gtrinida          #+#    #+#             */
/*   Updated: 2021/12/13 14:29:52 by gtrinida         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int		ft_printf(const char *format, ...);
void	ft_printf_s(va_list *arg, int *len);
void	ft_printf_d(va_list *arg, int *len);
void	ft_printf_u(va_list *arg, int *len);
void	ft_printf_c(va_list *arg, int *len);
void	ft_printf_p(va_list *arg, int *len);
void	ft_printf_percent(int *len);
void	ft_printf_x(va_list *arg, int *len);
void	ft_printf_upx(va_list *arg, int *len);

#endif