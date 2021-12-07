#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int 	ft_printf(const char *format, ...);
int		ft_printf_s(va_list *arg, int *len);
int		ft_printf_d(va_list *arg, int *len);
int 	ft_printf_u(va_list *arg, int *len);
void	ft_printf_c(va_list *arg, int *len);
void	ft_printf_p(va_list *arg, int *len);
void	ft_printf_percent(va_list *arg, int *len);
void	ft_printf_x(va_list *arg, int *len);
void	ft_printf_upX(va_list *arg, int *len);

#endif