#include "header.h"

void	put_c(char c, t_finfo *info)
{
	size_t	pad_len;

	pad_len = get_padding_len(1, info);
	if (is_overflow(pad_len + 1, info))
	{
		info->total_len = ERROR;
		return ;
	}
	info->total_len += pad_len + 1;
	if (info->minus_flag)
	{
		ft_putchar(c);
		put_padding(pad_len, info);
	}
	else
	{
		put_padding(pad_len, info);
		ft_putchar(c);
	}
}

void	put_s(char *s, t_finfo *info)
{
	size_t	pad_len;
	size_t	print_len;

	print_len = get_print_len(s, info);
	pad_len = get_padding_len(print_len, info);
	if (is_overflow(pad_len + print_len, info))
	{
		info->total_len = ERROR;
		return ;
	}
	info->total_len += pad_len + print_len;
	if (info->minus_flag)
	{
		ft_putstr_len(s, print_len);
		put_padding(pad_len, info);
	}
	else
	{
		put_padding(pad_len, info);
		ft_putstr_len(s, print_len);
	}
}
