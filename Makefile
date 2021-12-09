NAME = libftprintf.a
CC = gcc
CFLAGS = -Wall -Wextra -Werror -I.
RM = rm -f

INCLUDES = ft_printf.h

SRCS = ft_printf.c\
		ft_printf_s\
		ft_printf_d\
		ft_printf_u\
		ft_printf_c\
		ft_printf_p\
		ft_printf_percent\
		ft_printf_x\
		ft_printf_upX
OBJS = ${SRCS:.c=.o}

%.o: %.c $(INCLUDES)
	$(CC) $(CFLAGS) -c $<

$(NAME): $(OBJS)
	ar rcs $@ $^

all: $(NAME)

clean:
	$(RM) $(OBJS)

fclean:
	$(RM) $(NAME)

re: clean all
