#include "header.h"

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
			print_flag_info(finfo);
			if (finfo->is_error)
			{
				ret = ERROR;
				free(finfo);
				break ;
			}
			free(finfo);
		}
		else
			putchar(*fmt++);
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
	ret = do_printf(fmt, &ap);
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int	ret;

	//ret = printf("%*.*d\n", INT_MIN, 1, 10);
	//ret = ft_printf("%*.*d\n", INT_MIN, 1, 10);
	//printf("ret: %d\n", ret);
	ft_printf("%+-4.2 0.8 #1 *.* dhogehoge\n", 42, 42);
	//ft_printf("%04.12d%%hoge\n");
}
