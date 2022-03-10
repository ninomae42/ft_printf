/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_p.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:38:50 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:53:37 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

ssize_t	put_pad_p(char *p, t_info *info, size_t padding_len)
{
	char	*pad;
	size_t	ret;

	pad = (char *)ft_calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (-1);
	ft_memset(pad, ' ', padding_len);
	if (info->left_align)
	{
		ret = ft_putstr_cnt("0x");
		ret += ft_putstr_cnt(p);
		ret += ft_putstr_cnt(pad);
	}
	else
	{
		ret = ft_putstr_cnt(pad);
		ret += ft_putstr_cnt("0x");
		ret += ft_putstr_cnt(p);
	}
	free(pad);
	return (ret);
}

ssize_t	put_p(unsigned long long int addr, t_info *info)
{
	char	*p;
	ssize_t	ret;
	size_t	padding_len;

	p = itoa_base_8byte_u(addr, BASE_16_L);
	if (p == NULL)
		return (-1);
	padding_len = get_padding_len(get_print_len(p, info) + 2, info);
	if (is_fmt_long(padding_len + ft_strlen(p) + 2, info))
	{
		free(p);
		return (-1);
	}
	if (padding_len > 0)
		ret = put_pad_p(p, info, padding_len);
	else
	{
		ret = ft_putstr_cnt("0x");
		ret += ft_putstr_cnt(p);
	}
	free(p);
	return (ret);
}
