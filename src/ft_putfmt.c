#include "../ft_printf.h"

void	ft_putfmt(const char **fmt, va_list *ap, size_t *cnt, int *err_flag)
{
	(*fmt)++;
	if (**fmt == 'c')
		ft_putchar_cnt((unsigned int)va_arg(*ap, int), cnt);
	else if (**fmt == 's')
		ft_putstr_cnt(va_arg(*ap, char *), cnt, err_flag);
	else if (**fmt == 'd' || **fmt == 'i')
		ft_putnbr_base_cnt(va_arg(*ap, int), "0123456789", cnt);
	else if (**fmt == 'u')
		ft_putnbr_base_uint_cnt(va_arg(*ap, unsigned int), "0123456789", cnt);
	else if (**fmt == 'x')
		ft_putnbr_base_uint_cnt(va_arg(*ap, unsigned int), "0123456789abcdef", cnt);
	else if (**fmt == 'X')
		ft_putnbr_base_uint_cnt(va_arg(*ap, unsigned int), "0123456789ABCDEF", cnt);
	else if (**fmt == 'p')
	{
		ft_putstr_cnt("0x", cnt, err_flag);
		ft_putnbr_base_uint_cnt((unsigned long long)va_arg(*ap, void *),
			"0123456789abcdef", cnt);
	}
	else
		ft_putchar_cnt(**fmt, cnt);
	if (*err_flag == -1)
		return ;
	(*fmt)++;
}
