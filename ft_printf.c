#include "ft_printf.h"
#include "include/libft.h"

int	ft_printf(const char *fmt, ...)
{
	size_t	cnt;
	va_list	ap;
	char	*str;

	va_start(ap, fmt);
	cnt = 0;
	while (*fmt != '\0')
	{
		if (*fmt != '%')
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
			cnt++;
			continue ;
		}
		if (*(++fmt) == 'c')
		{
			ft_putchar_fd((unsigned char)va_arg(ap, int), 1);
			cnt++;
			fmt++;
		}
		else if (*fmt == 's')
		{
			str = va_arg(ap, char *);
			ft_putstr_fd(str, 1);
			cnt += ft_strlen(str);
			fmt++;
		}
		else
		{
			ft_putchar_fd(*fmt, 1);
			fmt++;
			cnt++;
		}
	}
	va_end(ap);
	return ((int)cnt);
}
