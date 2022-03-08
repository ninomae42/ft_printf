#include "ft_printf.h"

ssize_t	put_pad_s(char *s, t_info *info, size_t padding_len, size_t print_len)
{
	char	*pad;
	size_t	ret;

	pad = (char *)calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	memset(pad, ' ', padding_len);
	if (s == NULL)
		s = NULL_STR;
	if (info->left_align)
	{
		ret = ft_putstr_len_cnt(s, print_len);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += ft_putstr_len_cnt(s, print_len);
	}
	free(pad);
	return (ret);
}

ssize_t	put_s(char *s, t_info *info)
{
	ssize_t	ret;
	size_t	padding_len;
	size_t	print_len;

	print_len = get_print_len(s, info);
	padding_len = get_padding_len(print_len, info);
	if (is_fmt_long(print_len + padding_len, info))
		return (-1);
	if (padding_len > 0)
		ret = put_pad_s(s, info, padding_len, print_len);
	else
	{
		if (s == NULL)
			s = NULL_STR;
		ret = ft_putstr_len_cnt(s, print_len);
	}
	return (ret);
}
