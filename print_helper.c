#include "ft_printf.h"

bool	is_fmt_long(size_t current_len, t_info *info)
{
	if ((size_t)info->cnt + current_len > (size_t)INT_MAX)
		return (true);
	return (false);
}

char	get_pad_char(t_info *info)
{
	if (info->zero_padding && !info->left_align)
		return ('0');
	else
		return (' ');
}

size_t	get_padding_len(size_t print_len, t_info *info)
{
	size_t	padding_len;

	padding_len = 0;
	if (info->min_width >= 0 && info->min_width > print_len)
		padding_len = info->min_width - print_len;
	return (padding_len);
}

size_t	get_print_len(char *s, t_info *info)
{
	size_t	print_len;

	if (s == NULL)
		print_len = ft_strlen(NULL_STR);
	else
		print_len = ft_strlen(s);
	if (info->precision >= 0 && print_len > info->precision)
		print_len = info->precision;
	return (print_len);
}
