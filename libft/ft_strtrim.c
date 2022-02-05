/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 17:00:44 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 17:00:46 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"
#define NUL_CHR 1

// allocates and returns a copy of 's1' with the characters
// specified in 'set' removed from the beginning and
// the end of the string.
char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p_ret;
	size_t	cnt_front;
	size_t	cnt_back;
	size_t	alloc_size;

	if (s1 == NULL || set == NULL)
		return (NULL);
	cnt_front = 0;
	cnt_back = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[cnt_front]) != NULL && s1[cnt_front] != '\0')
		cnt_front++;
	while (ft_strrchr(set, s1[cnt_back]) != NULL && cnt_back > 0)
		cnt_back--;
	if (cnt_front == ft_strlen(s1))
		return (ft_strdup(""));
	alloc_size = sizeof(char) * (cnt_back - cnt_front + 1 + NUL_CHR);
	p_ret = (char *)malloc(alloc_size);
	if (p_ret == NULL)
		return (NULL);
	ft_strlcpy(p_ret, &s1[cnt_front], alloc_size);
	return (p_ret);
}
