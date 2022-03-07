SRCS := ft_printf.c \
		parser.c \
		parser_helper.c
CC := cc

t: $(SRCS)
	$(CC) $(SRCS)
	./a.out

.PHONY: test
