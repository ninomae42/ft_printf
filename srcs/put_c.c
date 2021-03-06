/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_c.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:38:36 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:58:49 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	put_pad_c(unsigned char c, size_t padding_len, t_info *info)
{
	char	*pad;
	size_t	ret;

	pad = (char *)ft_calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	ft_memset(pad, ' ', padding_len);
	if (info->left_align)
	{
		ret = ft_putchar_cnt(c);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += ft_putchar_cnt(c);
	}
	free(pad);
	return (ret);
}

ssize_t	put_c(unsigned char c, t_info *info)
{
	size_t	padding_len;
	size_t	ret;

	padding_len = get_padding_len(1, info);
	if (is_fmt_long(padding_len + 1, info))
		return (-1);
	if (padding_len > 0)
		ret = put_pad_c(c, padding_len, info);
	else
		ret = ft_putchar_cnt(c);
	return (ret);
}

ssize_t	put_percent(unsigned char c, t_info *info)
{
	size_t	padding_len;
	size_t	ret;

	padding_len = get_padding_len(1, info);
	if (is_fmt_long(padding_len + 1, info))
		return (-1);
	if (padding_len > 0)
		ret = put_pad_percent(c, padding_len, info);
	else
		ret = ft_putchar_cnt(c);
	return (ret);
}

ssize_t	put_pad_percent(unsigned char c, size_t padding_len, t_info *info)
{
	char	*pad;
	size_t	ret;

	pad = (char *)ft_calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	ft_memset(pad, get_pad_char(info), padding_len);
	if (info->left_align)
	{
		ret = ft_putchar_cnt(c);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += ft_putchar_cnt(c);
	}
	free(pad);
	return (ret);
}
