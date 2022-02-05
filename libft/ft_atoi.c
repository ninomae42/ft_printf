/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:53:38 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/30 10:27:22 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// white-space character test
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

// convert ASCII string to integer
int	ft_atoi(const char *str)
{
	long	num;
	int		sign;

	num = 0;
	sign = 1;
	while (ft_isspace(*str))
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (ft_isdigit(*str))
	{
		if ((num * 10 + (*str - '0')) / 10 != num)
		{
			if (sign == -1)
				return (0);
			else
				return (-1);
		}
		num = num * 10 + (*str - '0');
		str++;
	}
	return ((int)num * sign);
}
