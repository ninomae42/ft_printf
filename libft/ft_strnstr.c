/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:00:24 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/29 16:25:55 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// locate a substring in a string
char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	const char	*p_hs;
	size_t		len_ndl;

	len_ndl = ft_strlen(needle);
	if (len_ndl == 0)
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	p_hs = (const char *)haystack;
	while (*p_hs != '\0' && len >= len_ndl)
	{
		if (*p_hs == *needle
			&& ft_strncmp(p_hs, needle, len_ndl) == 0)
			return ((char *)p_hs);
		p_hs++;
		len--;
	}
	return (NULL);
}
