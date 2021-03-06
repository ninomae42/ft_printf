/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_u.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:39:12 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 20:00:16 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	put_zero_pad_u(char *nbr, size_t padding_len_num, t_info *info)
{
	char	*pad;
	size_t	ret;

	if (info->precision == 0 && ft_atoi(nbr) == 0)
		return (0);
	pad = (char *)ft_calloc(padding_len_num + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	ft_memset(pad, '0', padding_len_num);
	if (padding_len_num > 0)
	{
		ret = ft_putstr_cnt(pad);
		ret += ft_putstr_cnt(nbr);
	}
	else
		ret = ft_putstr_cnt(nbr);
	free(pad);
	return (ret);
}

ssize_t	put_pad_u(char *nbr,
		t_info *info, size_t padding_len, size_t padding_len_num)
{
	char	*pad;
	size_t	ret;

	pad = (char *)ft_calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	ft_memset(pad, get_pad_char(info), padding_len);
	if (info->left_align)
	{
		ret = put_zero_pad_u(nbr, padding_len_num, info);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += put_zero_pad_u(nbr, padding_len_num, info);
	}
	free(pad);
	return (ret);
}

ssize_t	put_u(unsigned int n, t_info *info)
{
	char	*nbr;
	size_t	ret;
	size_t	padding_len;
	size_t	padding_len_num;

	nbr = itoa_base_8byte_u(n, BASE_10);
	if (nbr == NULL)
		return (-1);
	padding_len = get_padding_len(get_print_len_n(nbr, info), info);
	padding_len_num = get_zero_pad_len(nbr, info);
	if (is_fmt_long(padding_len + get_print_len_n(nbr, info), info))
	{
		free(nbr);
		return (-1);
	}
	if (padding_len > 0)
		ret = put_pad_u(nbr, info, padding_len, padding_len_num);
	else
		ret = put_zero_pad_u(nbr, padding_len_num, info);
	free(nbr);
	return (ret);
}
