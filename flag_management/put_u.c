#include "header.h"

void	put_padded_number(
		char *s_nbr, size_t padding_len, size_t padding_len_num, t_finfo *info)
{
	if (info->minus_flag)
	{
		while (padding_len_num--)
			ft_putchar('0');
		ft_putstr(s_nbr);
		put_padding(padding_len, info);
	}
	else
	{
		put_padding(padding_len, info);
		while (padding_len_num--)
			ft_putchar('0');
		ft_putstr(s_nbr);
	}
}

void	put_number(char *s_nbr, size_t padding_len, t_finfo *info)
{
	if (info->minus_flag)
	{
		ft_putstr(s_nbr);
		put_padding(padding_len, info);
	}
	else
	{
		put_padding(padding_len, info);
		ft_putstr(s_nbr);
	}
}

void	put_u(unsigned int nbr, t_finfo *info)
{
	char	*s_nbr;
	size_t	padding_len;
	size_t	padding_len_num;

	s_nbr = ulonglong_toa_base(nbr, BASE_10);
	if (s_nbr == NULL)
	{
		info->is_error = true;
		return ;
	}
	padding_len = get_padding_len(get_print_len_num(s_nbr, info), info);
	padding_len_num = get_padding_len_num(ft_strlen(s_nbr), info);
	if (padding_len_num > 0)
		put_padded_number(s_nbr, padding_len, padding_len_num, info);
	else
		put_number(s_nbr, padding_len, info);
	free(s_nbr);
}
