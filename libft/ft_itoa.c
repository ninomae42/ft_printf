/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:54:59 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 16:55:06 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

static size_t	count_digit(int n)
{
	size_t	cnt;

	cnt = 0;
	if (n <= 0)
		cnt = 1;
	while (n != 0)
	{
		n /= 10;
		cnt++;
	}
	return (cnt);
}

static void	set_numbers(int nbr, char *s, size_t cnt)
{
	unsigned int	u_nbr;

	if (nbr < 0)
	{
		u_nbr = nbr * -1;
		if (u_nbr == 2147483648)
		{
			set_numbers(u_nbr / 10, s, cnt - 1);
			set_numbers(u_nbr % 10, s, cnt);
		}
		else
			set_numbers(u_nbr, s, cnt);
		s[0] = '-';
	}
	else if (nbr >= 10)
	{
		set_numbers(nbr / 10, s, cnt - 1);
		set_numbers(nbr % 10, s, cnt);
	}
	else
		s[cnt] = nbr + '0';
}

// Allocates and returns a string representing the integer received
// as an argument. Negative numbers must be handled.
char	*ft_itoa(int n)
{
	char	*p_ret;

	p_ret = (char *)ft_calloc(count_digit(n) + 1, sizeof(char));
	if (p_ret == NULL)
		return (NULL);
	if (n != 0)
		set_numbers(n, p_ret, count_digit(n) - 1);
	else
		p_ret[0] = '0';
	return (p_ret);
}
