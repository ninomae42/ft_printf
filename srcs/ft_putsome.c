/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putsome.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:37:43 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:37:44 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

size_t	ft_putchar_cnt(const char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_putstr_cnt(const char *s)
{
	size_t	len;
	size_t	ret;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	ret = len;
	while (INT_MAX < len)
	{
		write(1, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	write(1, s, len);
	return (ret);
}

size_t	ft_putstr_len_cnt(const char *s, size_t max_len)
{
	size_t	len;
	size_t	ret;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	if (len > max_len)
		len = max_len;
	ret = len;
	while (INT_MAX < len)
	{
		write(1, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	write(1, s, len);
	return (ret);
}
