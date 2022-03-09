SRCS := ft_printf.c \
		ft_putsome.c \
		itoa_base_8byte.c \
		itoa_base_8byte_u.c \
		parser.c \
		parser_helper.c \
		print_helper.c \
		print_helper2.c \
		put_c.c \
		put_p.c \
		put_s.c \
		put_u.c \
		put_x.c

CC := cc

t: $(SRCS)
	$(CC) $(SRCS)
	./a.out

.PHONY: test
