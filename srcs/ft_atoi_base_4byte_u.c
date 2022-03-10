/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base_4byte_u.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:37:09 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:37:10 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static int	ft_isspace(int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	if (uc == '\t' || uc == '\n' || uc == '\v' || uc == '\f'
		|| uc == '\r' || uc == ' ')
		return (1);
	else
		return (0);
}

static unsigned int	base_to_uint(char c, char *base)
{
	unsigned int	cnt;

	cnt = 0;
	while (base[cnt] != '\0')
	{
		if (c == base[cnt])
			return (cnt);
		cnt++;
	}
	return (0);
}

unsigned int	ft_atoi_base_4byte_u(const char *str, char *base)
{
	unsigned int	num;
	size_t			base_len;

	num = 0;
	base_len = ft_strlen(base);
	while (ft_isspace(*str))
		str++;
	while (*str != '\0' && ft_strchr(base, *str))
	{
		num = num * base_len + base_to_uint(*str, base);
		str++;
	}
	return (num);
}
