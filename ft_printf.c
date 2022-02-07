#include "ft_printf.h"
#include "include/libft.h"

int	ft_printf(const char *fmt, ...)
{
	size_t	cnt;
	va_list	ap;
	int		is_err;

	va_start(ap, fmt);
	cnt = 0;
	is_err = 0;
	while (*fmt != '\0' && is_err != -1)
	{
		if (*fmt != '%' && !is_line_long(&is_err, cnt, 1))
		{
			ft_putchar_cnt(*fmt++, &cnt);
			continue ;
		}
		ft_putfmt(&fmt, &ap, &cnt, &is_err);
	}
	va_end(ap);
	if (is_err == -1)
		return (is_err);
	return ((int)cnt);
}
