/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:57:27 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 16:57:28 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// fill a byte string with a byte value
void	*ft_memset(void *b, int c, size_t len)
{
	size_t			cnt;
	unsigned char	*p_b;

	if (len == 0)
		return (b);
	cnt = 0;
	p_b = (unsigned char *)b;
	while (cnt < len)
	{
		*p_b = (unsigned char)c;
		p_b++;
		cnt++;
	}
	return (b);
}
