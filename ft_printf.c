#include "ft_printf.h"

ssize_t	put_arg(t_info *info, va_list *ap)
{
	ssize_t	res;

	if (info->conv_specifier == 'c')
		res = put_c((unsigned char)va_arg(*ap, int), info);
	else if (info->conv_specifier == 's')
		res = put_s(va_arg(*ap, char *), info);
	else if (info->conv_specifier == 'p')
		res = put_p((unsigned long long int)va_arg(*ap, void *), info);
	else if (info->conv_specifier == 'u')
		res = put_u(va_arg(*ap, unsigned int), info);
	else if (info->conv_specifier == 'x')
		res = put_x(va_arg(*ap, unsigned int), info, BASE_16_L);
	else if (info->conv_specifier == 'X')
		res = put_x(va_arg(*ap, unsigned int), info, BASE_16_U);
	else if (info->conv_specifier == '%')
		res = put_percent('%', info);
	else
		res = ERROR;
	info->cnt = res;
	return (res);
}

int	ft_printf(const char *fmt, ...)
{
	int		cnt;
	va_list	ap;
	t_info	*info;

	if (fmt == NULL)
		return (ERROR);
	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != '\0' && cnt != ERROR)
	{
		if (*fmt == '%')
		{
			info = parse_flag(&fmt, &ap, cnt);
			if (info == NULL)
				return (ERROR);
			if (put_arg(info, &ap) != -1)
				cnt += info->cnt;
			else
				cnt = info->cnt;
			free(info);
		}
		else
			cnt += ft_putchar_cnt(*fmt++);
	}
	return (cnt);
}

int	main(void)
{
	int	ret1;
	int	ret2;

	ret1 = printf("[%#05X]\n", 0);
	ret2 = ft_printf("[%#05X]\n", 0);
	printf("\nret1: %d, ret2: %d\n", ret1, ret2);

	ret1 = printf("[%#05X]\n", 42);
	ret2 = ft_printf("[%#05X]\n", 42);
	printf("\nret1: %d, ret2: %d\n", ret1, ret2);

	ret1 = printf("[%#5X]\n", 42);
	ret2 = ft_printf("[%#5X]\n", 42);
	printf("\nret1: %d, ret2: %d\n", ret1, ret2);

	/* ret1 = printf("[%#05x]\n", 42); */
	/* ret2 = ft_printf("[%#05x]\n", 42); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%#5x]\n", 42); */
	/* ret2 = ft_printf("[%#5x]\n", 42); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%04.3u]\n", 42); */
	/* ret2 = ft_printf("[%04.3u]\n", 42); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%-13p]\n", NULL); */
	/* ret2 = ft_printf("[%-13p]\n", NULL); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%-02.10%]\n"); */
	/* ret2 = ft_printf("[%-02.10%]\n"); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("[%-7.6s]\n", (char *) NULL); */
	/* ret2 = ft_printf("[%-7.6s]\n", NULL); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret1 = printf("hoge[%-*c]moge\n", 10, '/'); */
	/* ret2 = ft_printf("hoge[%-*c]moge\n", 10, '/'); */
	/* printf("\nret1: %d, ret2: %d\n", ret1, ret2); */

	/* ret = ft_printf("%-0*.*c\n\n", INT_MIN + 1, -INT_MAX, 'A'); */
	/* printf("ret: %d\n", ret); */

	/* ret = ft_printf("%-0*.*bc\n\n", INT_MIN, -INT_MAX, 'A'); */
	/* printf("ret: %d\n", ret); */
	/* ft_printf("%03.4c\n\n", 'c'); */
	/* ft_printf("%-03.4c\n\n", 'c'); */
	/* ft_printf("%0-3.4c\n\n", 'c'); */
}
