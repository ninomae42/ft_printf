NAME := ft_printf.a
SRCS := printf.c \
		parser.c \
		parser_util.c \
		itoa.c \
		ulonglong_toa.c \
		strutils.c \

OBJS := $(SRCS:.c=.o)

CC := cc
#CFLAGS := -Wall -Wextra -Werror
AR := ar
ARFLAGS := rcs
RM := rm -f

.c.o:
	$(CC) -c $< -o $(<:.c=.o)

$(NAME): $(OBJS)
	$(AR) $(ARFLAGS) $(NAME) $(OBJS)

all: $(NAME)

clean:
	$(RM) a.out
#$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

t:
	$(CC) $(SRCS)
	./a.out

.PHONY: all clean fclean re bonus t
