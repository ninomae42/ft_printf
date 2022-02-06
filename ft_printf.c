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
			ft_putchar_fd_cnt(*fmt++, 1, &cnt);
			continue ;
		}
		if (*(++fmt) == 'c')
			ft_putchar_fd_cnt((unsigned char)va_arg(ap, int), 1, &cnt);
		else if (*fmt == 's')
			ft_putstr_fd_cnt(va_arg(ap, char *), 1, &cnt);
		else if (*fmt == 'd' || *fmt == 'i')
			ft_putnbr_base_fd_cnt(va_arg(ap, int), "0123456789", 1, &cnt);
		else
			ft_putchar_fd_cnt(*fmt, 1, &cnt);
		fmt++;
	}
	va_end(ap);
	return ((int)cnt);
}
