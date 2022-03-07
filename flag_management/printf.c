#include "header.h"

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

void	put_di(int nbr, t_finfo *info)
{
	char	*s_nbr;
	char	sign_char;

	s_nbr = ft_itoa(nbr);
	if (s_nbr == NULL)
	{
		info->is_error = true;
		return ;
	}
	if (info->plus_flag || info->space_flag)
	{
		sign_char = get_sign_char(info, nbr);
		if (sign_char != '\0')
			write(1, &sign_char, 1);
	}
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_x_lower(unsigned int nbr, t_finfo *info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_16L);
	if (s_nbr == NULL)
	{
		info->is_error = true;
		return ;
	}
	if (info->alter_flag && nbr != 0)
		ft_putstr("0x");
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_x_upper(unsigned int nbr, t_finfo *info)
{
	char	*s_nbr;

	s_nbr = ulonglong_toa_base(nbr, BASE_16U);
	if (s_nbr == NULL)
	{
		info->is_error = true;
		return ;
	}
	if (info->alter_flag && nbr != 0)
		ft_putstr("0X");
	ft_putstr(s_nbr);
	free(s_nbr);
}

void	put_fmt(t_finfo *info, va_list *ap, const char **fmt)
{
	if (info->conv_specifier == 'c' || info->conv_specifier == '%')
		put_c((unsigned char)va_arg(*ap, int), info);
	else if (info->conv_specifier == 's')
		put_s(va_arg(*ap, char *), info);
	else if (info->conv_specifier == 'd'
		|| info->conv_specifier == 'i')
		put_di(va_arg(*ap, int), info);
	else if (info->conv_specifier == 'u')
		put_u(va_arg(*ap, unsigned int), info);
	else if (info->conv_specifier == 'x')
		put_x_lower(va_arg(*ap, unsigned int), info);
	else if (info->conv_specifier == 'X')
		put_x_upper(va_arg(*ap, unsigned int), info);
	else if (info->conv_specifier == 'p')
		put_p(va_arg(*ap, unsigned long long int), info);
	else
		put_c(*(*fmt)++, info);
}

int	do_printf(const char *fmt, va_list *ap)
{
	int		ret;
	t_finfo	*finfo;

	ret = 0;
	while (*fmt != '\0' && ret != ERROR)
	{
		if (*fmt == '%')
		{
			parse_flag(&fmt, &finfo, ap, ret);
			if (finfo == NULL)
				return (ERROR);
			if (finfo->is_error)
			{
				free(finfo);
				return (ERROR);
			}
			put_fmt(finfo, ap, &fmt);
			ret = finfo->total_len;
			free(finfo);
		}
		else
		{
			ft_putchar(*fmt++);
			ret++;
		}
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
	int	ret1;
	int	ret2;

	ret1 = printf("[%-013.10p]\n", main);
	ret2 = ft_printf("[%-013.10p]\n", main);
	printf("\nret1: %d, ret2: %d\n", ret1, ret2);

	/* ret1 = printf("[%12p]\n", main); */
	/* ret2 = ft_printf("[%12p]\n", main); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */
	/* ret1 = printf("[%-12p]\n", main); */
	/* ret2 = ft_printf("[%-12p]\n", main); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%012p]\n", main); */
	/* ret2 = ft_printf("[%012p]\n", main); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */
	/* ret1 = printf("[%-012p]\n", main); */
	/* ret2 = ft_printf("[%-012p]\n", main); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("hogehoge: %c, %s\n", 'A', "hogemoge"); */
	/* ret2 = ft_printf("hogehoge: %c, %s\n", 'A', "hogemoge"); */
	/* printf("ret1: %d, ret2: %d\n", ret1, ret2); */

	/* printf("[%-4.3u][%.u][%04.3u][%11.3u]\n", 10, 10, 10, UINT_MAX); */
	/* ft_printf("[%-4.3u][%.u][%04.3u][%11.3u]\n", 10, 10, 10, UINT_MAX); */

	/* c with min_field_width, precision, and zero/minus flag. */
	//printf("[%*.3s][%-04.*s]\n", -4, NULL, 3, "hogehoge");
	//ft_printf("[%*.3s][%-04.*s]\n", -4, NULL, 3, "hogehoge");

	/* handle non-conversion char appear between % and conversion specifier */
	//printf("%-4b 2d\n", 10);
	//ft_printf("%-4b 2d\n", 10);

	/* c with min_field_width and zero/minus flag */
	//printf("hoge[%-04c]\n", 'A');
	//ft_printf("hoge[%-04c]\n", 'A');

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
