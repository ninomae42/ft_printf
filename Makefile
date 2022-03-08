SRCS := ft_printf.c \
		ft_putsome.c \
		parser.c \
		parser_helper.c \
		print_helper.c \
		put_c.c

CC := cc

t: $(SRCS)
	$(CC) $(SRCS)
	./a.out

.PHONY: test
