NAME := libftprintf.a
SRCDIR := ./src/
SRCS := ft_putchar_fd_cnt.c \
		ft_putfmt.c \
		ft_putnbr_base_fd_cnt.c \
		ft_putstr_fd_cnt.c \
		is_linelong.c

SRCS := $(addprefix $(SRCDIR), $(SRCS))
SRCS += ./ft_printf.c

OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE := make
INCDIR := ../include
AR := ar
ARFLAGS := rcs
RM := rm -f

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -I . -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(MAKE) -C ./libft
	cp libft/libft.a $(NAME)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(MAKE) clean -C ./libft
	$(RM) $(OBJS)

fclean: clean
	$(MAKE) fclean -C ./libft
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
