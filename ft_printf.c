#include "ft_printf.h"
#include "include/libft.h"

int	ft_printf(const char *fmt, ...)
{
	size_t	cnt;
	va_list	ap;

	va_start(ap, fmt);
	cnt = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_putchar_cnt(*fmt++, &cnt);
			continue ;
		}
		if (*(++fmt) == 'c')
			ft_putchar_cnt((unsigned char)va_arg(ap, int), &cnt);
		else if (*fmt == 's')
			ft_putstr_cnt(va_arg(ap, char *), &cnt);
		else if (*fmt == 'd' || *fmt == 'i')
			ft_putnbr_base_cnt(va_arg(ap, int), "0123456789", &cnt);
		else if (*fmt == 'u')
			ft_putnbr_base_cnt(va_arg(ap, unsigned int), "0123456789", &cnt);
		else
			ft_putchar_cnt(*fmt, &cnt);
		fmt++;
	}
	va_end(ap);
	return ((int)cnt);
}
