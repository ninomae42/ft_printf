#include "header.h"

/* typedef struct s_finfo { */
/* 	bool	alter_flag; */
/* 	bool	space_flag; */
/* 	bool	plus_flag; */
/* 	bool	zero_flag; */
/* 	bool	minus_flag; */
/* 	int		min_field_width; */
/* 	int		precision; */
/* 	char	conv_specifier; */
/* 	bool	is_error; */
/* }	t_finfo; */

char	get_sign_char(t_finfo *info, int nbr)
{
	if (nbr >= 0)
	{
		if (info->plus_flag)
			return ('+');
		return (' ');
	}
	else
		return ('\0');
}

	/* printf("%4.3d\n", 10); */
	/* ft_printf("%4.3d\n", 10); */

void	put_di(int nbr, t_finfo **info)
{
	char	*s_nbr;
	char	sign_char;

	s_nbr = ft_itoa(nbr);
	if (s_nbr == NULL)
	{
		(*info)->is_error = true;
		return ;
	}
	if ((*info)->plus_flag || (*info)->space_flag)
	{
		sign_char = get_sign_char(*info, nbr);
		if (sign_char != '\0')
			write(1, &sign_char, 1);
	}
	write(1, s_nbr, strlen(s_nbr));
}

int	do_printf(const char **fmt, va_list *ap)
{
	int		ret;
	t_finfo	*finfo;

	ret = 0;
	while (**fmt != '\0')
	{
		if (**fmt == '%')
		{
			parse_flag(fmt, &finfo, ap);
			if (finfo == NULL)
				return (ERROR);
			/* print_flag_info(finfo); */
			/* if (finfo->conv_specifier == 'c') */
			/* 	ft_putchar_padding((unsigned char)va_arg(*ap, int), finfo); */
			if (finfo->conv_specifier == 'd' || finfo->conv_specifier == 'i')
				put_di(va_arg(*ap, int), &finfo);
			if (finfo->is_error)
			{
				free(finfo);
				return (ERROR);
			}
			free(finfo);
		}
		else
			putchar(*(*fmt)++);
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	ret;
	va_list	ap;

	ret = 0;
	if (fmt == NULL)
		return (ERROR);
	va_start(ap, fmt);
	ret = do_printf(&fmt, &ap);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int	ret;

	printf("%4.3d\n", 10);
	ft_printf("%4.3d\n", 10);

//	printf("%+d\n", 2147483647);
//	printf("%+d\n", -2147483648);
//	printf("%+d\n", 0);
//	ft_printf("%+d\n", 2147483647);
//	ft_printf("%+d\n", -2147483648);
//	ft_printf("%+d\n", 0);

//	printf("% d\n", 2147483647);
//	printf("% d\n", -2147483648);
//	printf("% d\n", 0);
//	ft_printf("% d\n", 2147483647);
//	ft_printf("% d\n", -2147483648);
//	ft_printf("% d\n", 0);

//	printf("%+ d\n", 2147483647);
//	printf("%+ d\n", -2147483648);
//	printf("%+ d\n", 0);
//	ft_printf("%+ d\n", 2147483647);
//	ft_printf("%+ d\n", -2147483648);
//	ft_printf("%+ d\n", 0);

	/* printf("[%02c]\n", 'A'); */
	/* ft_printf("[%02c]\n", 'A'); */

	/* char */
//	printf("%2.0c\n", 'A'); // precision == 0 does not effect result.
//	ft_printf("%2.0c\n", 'A');

	//ret = printf("%*.*d\n", INT_MIN, 1, 10);
	//ret = ft_printf("%*.*d\n", INT_MIN, 1, 10);
	//printf("ret: %d\n", ret);

	/* test for get flag information. */
	//ft_printf("%+-4.2 0.8 #1 *.* dhogehoge\n", 42, 42);
	//ft_printf("%04.12d%%hoge\n");
}
