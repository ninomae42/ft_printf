#include "header.h"

static bool	is_numeric_conversion(t_finfo *info)
{
	char	conv_specifier;

	conv_specifier = info->conv_specifier;
	if (strchr("diuxX", conv_specifier) != NULL)
		return (true);
	return (false);
}

char	get_padding_char(t_finfo *info)
{
	char	padding_char;

	padding_char = ' ';
	if (info->zero_flag && !is_numeric_conversion(info))
		padding_char = '0';
	return (padding_char);
}

size_t	get_padding_len(size_t len, t_finfo *info)
{
	size_t	padding_len;

	padding_len = 0;
	if (info->min_field_width >= 0 && info->min_field_width > len)
		padding_len = info->min_field_width - len;
	return (padding_len);
}

void	put_padding(size_t padding_len, t_finfo *info)
{
	while (padding_len--)
		ft_putchar(get_padding_char(info));
}

size_t	get_print_len(char *s, t_finfo *info)
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
