#include "header.h"

size_t	get_print_len_num(char *s, t_finfo *info)
{
	size_t	print_len_num;

	print_len_num = ft_strlen(s);
	if (info->precision >= 0 && info->precision > print_len_num)
		print_len_num = info->precision;
	return (print_len_num);
}

size_t	get_padding_len_num(size_t len, t_finfo *info)
{
	size_t	padding_len_num;

	padding_len_num = 0;
	if (info->precision >= 0 && info->precision > len)
		padding_len_num = info->precision - len;
	return (padding_len_num);
}
