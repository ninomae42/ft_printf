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

bool	is_numeric_conversion(t_finfo *info)
{
	char	conv_specifier;

	conv_specifier = info->conv_specifier;
	if (strchr("diuxX", conv_specifier) != NULL)
		return (true);
	return (false);
}

char	get_padding_char(t_finfo *info)
{
	char	padding_char;

	padding_char = ' ';
	if (info->zero_flag && !is_numeric_conversion(info))
		padding_char = '0';
	return (padding_char);
}

size_t	get_padding_len(size_t len, t_finfo *info)
{
	size_t	padding_len;
	size_t	min_field_width;

	padding_len = 0;
	min_field_width = info->min_field_width;
	if (min_field_width >= 0 && min_field_width > len)
		padding_len = min_field_width - len;
	return (padding_len);
}

void	put_padding(size_t padding_len, t_finfo *info)
{
	while (padding_len--)
		ft_putchar(get_padding_char(info));
}

void	put_c(char c, t_finfo **info)
{
	size_t	pad_len;

	pad_len = get_padding_len(1, *info);
	if ((*info)->minus_flag)
	{
		ft_putchar(c);
		put_padding(pad_len, *info);
	}
	else
	{
		put_padding(pad_len, *info);
		ft_putchar(c);
	}
}

void	put_s(char *s, t_finfo **info)
{
	ft_putstr(s);
}

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
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_u(unsigned int nbr, t_finfo **info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_10);
	if (s_nbr == NULL)
	{
		(*info)->is_error = true;
		return ;
	}
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_x_lower(unsigned int nbr, t_finfo **info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_16L);
	if (s_nbr == NULL)
	{
		(*info)->is_error = true;
		return ;
	}
	if ((*info)->alter_flag && nbr != 0)
		ft_putstr("0x");
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_x_upper(unsigned int nbr, t_finfo **info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_16U);
	if (s_nbr == NULL)
	{
		(*info)->is_error = true;
		return ;
	}
	if ((*info)->alter_flag && nbr != 0)
		ft_putstr("0X");
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_p(unsigned long long int nbr, t_finfo **info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_16L);
	if (s_nbr == NULL)
	{
		(*info)->is_error = true;
		return ;
	}
	ft_putstr("0x");
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_fmt(t_finfo **info, va_list *ap)
{
	if ((*info)->conv_specifier == 'c' || (*info)->conv_specifier == '%')
		put_c((unsigned char)va_arg(*ap, int), info);
	else if ((*info)->conv_specifier == 's')
		put_s(va_arg(*ap, char *), info);
	else if ((*info)->conv_specifier == 'd'
		|| (*info)->conv_specifier == 'i')
		put_di(va_arg(*ap, int), info);
	else if ((*info)->conv_specifier == 'u')
		put_u(va_arg(*ap, unsigned int), info);
	else if ((*info)->conv_specifier == 'x')
		put_x_lower(va_arg(*ap, unsigned int), info);
	else if ((*info)->conv_specifier == 'X')
		put_x_upper(va_arg(*ap, unsigned int), info);
	else if ((*info)->conv_specifier == 'p')
		put_p(va_arg(*ap, unsigned long long int), info);
}

int	do_printf(const char *fmt, va_list *ap)
{
	int		ret;
	t_finfo	*finfo;

	ret = 0;
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			parse_flag(&fmt, &finfo, ap);
			if (finfo == NULL)
				return (ERROR);
			if (finfo->is_error)
			{
				free(finfo);
				return (ERROR);
			}
			put_fmt(&finfo, ap);
			free(finfo);
		}
		else
			ft_putchar(*fmt++);
	}
	return (ret);
}

int	ft_printf(const char *fmt, ...)
{
	int		ret;
	va_list	ap;

	ret = 0;
	if (fmt == NULL)
		return (ERROR);
	va_start(ap, fmt);
	ret = do_printf(fmt, &ap);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int	ret;

	printf("hoge[%-04c]\n", 'A');
	ft_printf("hoge[%-04c]\n", 'A');

	/* x with alter_flag */
	//printf("%#x\n", 0);
	//ft_printf("%#x\n", 0);

	//printf("%#x\n", 1);
	//ft_printf("%#x\n", 1);

	//printf("%#X\n", 0);
	//ft_printf("%#X\n", 0);

	//printf("%#X\n", 1);
	//ft_printf("%#X\n", 1);
	////////////////////////

	/* printf("%s\n", NULL); */
	/* ft_printf("%s\n", NULL); */

	/* printf("%chogehoge%c\n", '4', '2'); */
	/* ft_printf("%chogehoge%c\n", '4', '2'); */

	/* printf("%p\n", NULL); */
	/* ft_printf("%p\n", NULL); */
	/* printf("%X\n", UINT_MAX); */
	/* ft_printf("%X\n", UINT_MAX); */

	/* printf("%u\n", -2); */
	/* ft_printf("%u\n", -2); */

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
