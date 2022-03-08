#include "ft_printf.h"

ssize_t	put_arg(t_info *info, va_list *ap)
{
	ssize_t	res;

	if (info->conv_specifier == 'c')
		res = put_c((unsigned char)va_arg(*ap, int), info);
	else if (info->conv_specifier == 's')
		res = put_s(va_arg(*ap, char *), info);
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

	ret1 = printf("[%-7.6s]\n", (char *) NULL);
	ret2 = ft_printf("[%-7.6s]\n", NULL);
	printf("\nret1: %d, ret2: %d\n", ret1, ret2);

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
