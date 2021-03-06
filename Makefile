# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/10 19:36:22 by tashimiz          #+#    #+#              #
#    Updated: 2022/03/10 19:36:39 by tashimiz         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := libftprintf.a
SRCDIR := ./srcs/
SRCS := ft_printf.c \
		ft_putsome.c \
		ft_atoi_base_4byte_u.c \
		itoa_base_8byte_u.c \
		parser.c \
		parser_helper.c \
		print_helper.c \
		print_helper2.c \
		put_c.c \
		put_di.c \
		put_p.c \
		put_s.c \
		put_u.c \
		put_x.c

SRCS := $(addprefix $(SRCDIR), $(SRCS))
OBJS := $(SRCS:.c=.o)

CC := cc
CFLAGS := -Wall -Wextra -Werror
MAKE := make
INCDIR := ./includes
AR := ar
ARFLAGS := rcs
RM := rm -f

.c.o:
	$(CC) $(CFLAGS) -I $(INCDIR) -c $< -o $(<:.c=.o)

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

bonus: all

.PHONY: all clean fclean re bonus
