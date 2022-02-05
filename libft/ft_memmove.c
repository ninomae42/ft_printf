/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:57:13 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 16:57:19 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	is_overlap(const void *s1, const void *s2, size_t n)
{
	const char	*p_s1;
	const char	*p_s2;
	size_t		cnt;

	p_s1 = (const char *)s1;
	p_s2 = (const char *)s2;
	cnt = 0;
	while (cnt < n)
	{
		if (p_s1 + cnt == p_s2 || p_s2 + cnt == p_s1)
			return (1);
		cnt++;
	}
	return (0);
}

static void	*move(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	const char	*p_src;

	p_dst = (char *)dst;
	p_src = (const char *)src;
	p_dst = p_dst + (len - 1);
	p_src = p_src + (len - 1);
	while (len)
	{
		*p_dst = *p_src;
		p_dst--;
		p_src--;
		len--;
	}
	return (dst);
}

// copy byte string
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	char		*p_dst;
	const char	*p_src;

	if (len == 0)
		return (dst);
	p_dst = (char *)dst;
	p_src = (const char *)src;
	if (!is_overlap(dst, src, len))
		ft_memcpy(dst, src, len);
	else
	{
		if (p_dst <= p_src)
			ft_memcpy(dst, src, len);
		else
			return (move(dst, src, len));
	}
	return (dst);
}
