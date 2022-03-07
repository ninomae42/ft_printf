#include "header.h"

void	put_padded_address(
	char *s_nbr, size_t padding_len, size_t padding_len_num, t_finfo *info)
{
	if (info->minus_flag)
	{
		ft_putstr("0x");
		while (padding_len_num--)
			ft_putchar('0');
		ft_putstr(s_nbr);
		put_padding(padding_len, info);
	}
	else
	{
		if (info->zero_flag)
		{
			ft_putstr("0x");
			put_padding(padding_len, info);
			ft_putstr(s_nbr);
		}
		else
		{
			put_padding(padding_len, info);
			ft_putstr("0x");
			while (padding_len_num--)
				ft_putchar('0');
			ft_putstr(s_nbr);
		}
	}
}

void	put_address(char *s_nbr, size_t padding_len, t_finfo *info)
{
	if (info->minus_flag)
	{
		ft_putstr("0x");
		ft_putstr(s_nbr);
		put_padding(padding_len, info);
	}
	else
	{
		if (info->zero_flag)
		{
			ft_putstr("0x");
			put_padding(padding_len, info);
			ft_putstr(s_nbr);
		}
		else
		{
			put_padding(padding_len, info);
			ft_putstr("0x");
			ft_putstr(s_nbr);
		}
	}
}

void	put_p(unsigned long long int nbr, t_finfo *info)
{
	char	*s_nbr;
	size_t	padding_len;
	size_t	padding_len_num;

	s_nbr = ulonglong_toa_base(nbr, BASE_16L);
	if (s_nbr == NULL)
	{
		info->total_len = ERROR;
		return ;
	}
	padding_len = get_padding_len(get_print_len_num(s_nbr, info) + 2, info);
	padding_len_num = get_padding_len_num(ft_strlen(s_nbr), info);
	if (is_overflow(padding_len + 2 + padding_len_num + ft_strlen(s_nbr), info))
	{
		info->total_len = ERROR;
		return ;
	}
	info->total_len += padding_len + 2 + padding_len_num + ft_strlen(s_nbr);
	if (padding_len_num > 0)
		put_padded_address(s_nbr, padding_len, padding_len_num, info);
	else
		put_address(s_nbr, padding_len, info);
	free(s_nbr);
}
