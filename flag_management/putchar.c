#include "header.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

size_t	get_padding_len(t_finfo *info, size_t len)
{
	size_t	padding_len;

	padding_len = 0;
	if (info->min_field_width >= 0)
	{
		if (info->min_field_width > len)
			padding_len = info->min_field_width - len;
	}
	return (padding_len);
}

char	get_padding_char(t_finfo *info)
{
	if (info->zero_flag && !(info->minus_flag))
		return ('0');
	else
		return (' ');
}

void	ft_putchar_padding(const char c, t_finfo *info)
{
	size_t	padding_len;
	char	padding_char;

	padding_len = get_padding_len(info, 1);
	padding_char = get_padding_char(info);
	while (padding_len--)
		ft_putchar(padding_char);
	ft_putchar(c);
}
