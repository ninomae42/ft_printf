/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_x.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:39:18 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:39:19 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static bool	is_precision_nbr_zero(char *nbr, t_info *info)
{
	if (info->precision == 0)
	{
		if (info->conv_specifier == 'x'
			&& ft_atoi_base_4byte_u(nbr, BASE_16_L) == 0)
			return (true);
		if (info->conv_specifier == 'X'
			&& ft_atoi_base_4byte_u(nbr, BASE_16_U) == 0)
			return (true);
	}
	return (false);
}

ssize_t	put_zero_pad_x(char *nbr, t_info *info, size_t padding_len_num)
{
	char	*pad;
	size_t	ret;

	if (is_precision_nbr_zero(nbr, info))
		return (0);
	pad = create_padding(padding_len_num, '0');
	if (pad == NULL)
		return (-1);
	ret = 0;
	if (is_alter_valid(nbr, info) && info->conv_specifier == 'x')
		ret = ft_putstr_cnt("0x");
	else if (is_alter_valid(nbr, info) && info->conv_specifier == 'X')
		ret = ft_putstr_cnt("0X");
	if (padding_len_num > 0)
		ret += ft_putstr_cnt(pad);
	ret += ft_putstr_cnt(nbr);
	free(pad);
	return (ret);
}

ssize_t	put_pad_x(char *nbr,
		t_info *info, size_t padding_len, size_t padding_len_num)
{
	char	*pad;
	size_t	ret;

	if (is_alter_valid(nbr, info) && info->zero_padding
		&& info->precision == -1)
		return (put_zero_pad_x(nbr, info, padding_len));
	pad = create_padding(padding_len, get_pad_char(info));
	if (pad == NULL)
		return (-1);
	if (info->left_align)
	{
		ret = put_zero_pad_x(nbr, info, padding_len_num);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += put_zero_pad_x(nbr, info, padding_len_num);
	}
	free(pad);
	return (ret);
}

ssize_t	put_x(unsigned int n, t_info *info, char *base)
{
	char	*nbr;
	size_t	ret;
	size_t	padding_len;
	size_t	padding_len_num;

	nbr = itoa_base_8byte_u(n, base);
	if (nbr == NULL)
		return (-1);
	padding_len = get_padding_len(get_print_len_hex(n, nbr, info), info);
	padding_len_num = get_zero_pad_len(nbr, info);
	if (is_fmt_long(padding_len + get_print_len_hex(n, nbr, info), info))
	{
		free(nbr);
		return (-1);
	}
	if (padding_len > 0)
		ret = put_pad_x(nbr, info, padding_len, padding_len_num);
	else
		ret = put_zero_pad_x(nbr, info, padding_len_num);
	free(nbr);
	return (ret);
}
