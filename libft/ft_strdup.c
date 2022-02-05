/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:58:54 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 16:58:55 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static char	*ft_strcpy(char *dst, const char *src)
{
	char	*p_dst;

	p_dst = (char *)dst;
	while (*src != '\0')
	{
		*p_dst = *src;
		p_dst++;
		src++;
	}
	*p_dst = '\0';
	return (dst);
}

// save a copy of a string
char	*ft_strdup(const char *s1)
{
	char	*p_ret;

	p_ret = (char *)ft_calloc(ft_strlen(s1) + 1, sizeof(char));
	if (p_ret == NULL)
	{
		errno = ENOMEM;
		return (NULL);
	}
	ft_strcpy(p_ret, s1);
	return (p_ret);
}
