#include "ft_printf.h"

void	ft_putchar_cnt(const char c, int *cnt)
{
	write(1, &c, 1);
	*cnt += 1;
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
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			info = parse_flag(&fmt, &ap, cnt);
			if (info == NULL)
				return (ERROR);
			print_flag_info(info);
			cnt = info->cnt;
			free(info);
		}
		else
			ft_putchar_cnt(*fmt++, &cnt);
	}
	return (cnt);
}

int	main(void)
{
	int	ret;

	ret = ft_printf("hogehoge\n%-3.4chogehoge\n\n", 'A');
	printf("ret: %d\n", ret);

	/* ret = ft_printf("%-0*.*c\n\n", INT_MIN + 1, -INT_MAX, 'A'); */
	/* printf("ret: %d\n", ret); */

	/* ret = ft_printf("%-0*.*bc\n\n", INT_MIN, -INT_MAX, 'A'); */
	/* printf("ret: %d\n", ret); */
	/* ft_printf("%03.4c\n\n", 'c'); */
	/* ft_printf("%-03.4c\n\n", 'c'); */
	/* ft_printf("%0-3.4c\n\n", 'c'); */
}
