/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_helper.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:38:20 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:52:14 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

bool	is_fmt_long(size_t current_len, t_info *info)
{
	if ((size_t)info->cnt + current_len > (size_t)INT_MAX)
		return (true);
	return (false);
}

char	get_pad_char(t_info *info)
{
	if (info->zero_padding && !info->left_align && info->precision >= 0)
		return (' ');
	else if (info->zero_padding && !info->left_align)
		return ('0');
	else
		return (' ');
}

size_t	get_padding_len(size_t print_len, t_info *info)
{
	size_t	padding_len;

	padding_len = 0;
	if (info->min_width >= 0 && (size_t)info->min_width > print_len)
		padding_len = info->min_width - print_len;
	return (padding_len);
}

size_t	get_print_len(char *s, t_info *info)
{
	size_t	print_len;

	if (s == NULL)
		print_len = ft_strlen(NULL_STR);
	else
		print_len = ft_strlen(s);
	if (info->precision >= 0 && print_len > (size_t)info->precision)
		print_len = info->precision;
	return (print_len);
}

char	*create_padding(size_t padding_len, char padding_char)
{
	char	*pad;

	pad = (char *)ft_calloc(padding_len + 1, sizeof(char));
	if (pad == NULL)
		return (NULL);
	ft_memset(pad, padding_char, padding_len);
	return (pad);
}
