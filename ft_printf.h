#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdio.h>

int	ft_printf_s(va_list *arg, int *len);
int ft_printf(const char *format, ...);
int	ft_printf_d(va_list *arg, int *len);
#endif