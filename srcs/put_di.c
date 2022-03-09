#include "ft_printf.h"

static char	get_sign_char(t_info *info)
{
	if (info->sign_space)
		return (' ');
	else if (info->sign)
		return ('+');
	return ('+');
}

static bool	is_sign_flag_valid(char *nbr, t_info *info)
{
	int	n;

	n = atoi(nbr);
	if ((info->sign_space || info->sign) && n >= 0)
		return (true);
	return (false);
}

ssize_t	put_zero_pad_di(char *nbr, t_info *info, size_t padding_len_num)
{
	char	*pad;
	size_t	ret;

	pad = create_padding(padding_len_num, '0');
	if (pad == NULL)
		return (-1);
	ret = 0;
	if (is_sign_flag_valid(nbr, info))
		ret = ft_putchar_cnt(get_sign_char(info));
	if (padding_len_num > 0)
		ret += ft_putstr_cnt(pad);
	ret += ft_putstr_cnt(nbr);
	free(pad);
	return (ret);
}

ssize_t	put_pad_di(char *nbr,
		t_info *info, size_t padding_len, size_t padding_len_num)
{
	char	*pad;
	size_t	ret;

	if (is_sign_flag_valid(nbr, info) && info->zero_padding
		&& info->precision == -1)
		return (put_zero_pad_di(nbr, info, padding_len));
	pad = create_padding(padding_len, get_pad_char(info));
	if (pad == NULL)
		return (-1);
	if (info->left_align)
	{
		ret = put_zero_pad_di(nbr, info, padding_len_num);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += put_zero_pad_di(nbr, info, padding_len_num);
	}
	free(pad);
	return (ret);
}

ssize_t	put_di(int n, t_info *info)
{
	char	*nbr;
	size_t	ret;
	size_t	padding_len;
	size_t	padding_len_num;

	nbr = ft_itoa(n);
	if (nbr == NULL)
		return (-1);
	padding_len = get_padding_len(get_print_len_di(n, nbr, info), info);
	padding_len_num = get_zero_pad_len(nbr, info);
	if (is_fmt_long(padding_len + get_print_len_di(n, nbr, info), info))
	{
		free(nbr);
		return (-1);
	}
	if (padding_len > 0)
		ret = put_pad_di(nbr, info, padding_len, padding_len_num);
	else
		ret = put_zero_pad_di(nbr, info, padding_len_num);
	free(nbr);
	return (ret);
}
