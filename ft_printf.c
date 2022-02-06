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
		ft_putfmt(&fmt, &ap, &cnt);
	}
	va_end(ap);
	return ((int)cnt);
}
