#include "../includes/ft_printf.h"

ssize_t	put_arg(t_info *info, va_list *ap)
{
	ssize_t	res;

	if (info->conv_specifier == 'c')
		res = put_c((unsigned char)va_arg(*ap, int), info);
	else if (info->conv_specifier == 's')
		res = put_s(va_arg(*ap, char *), info);
	else if (info->conv_specifier == 'd' || info->conv_specifier == 'i')
		res = put_di(va_arg(*ap, int), info);
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
