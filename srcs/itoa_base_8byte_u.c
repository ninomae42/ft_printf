/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   itoa_base_8byte_u.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:37:52 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:37:53 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static size_t	count_digit_base_u(unsigned long long int n, char *base);
static void		set_number_base_u(unsigned long long int n,
					char *s, size_t cnt, char *base);

char	*itoa_base_8byte_u(unsigned long long int n, char *base)
{
	char	*p_ret;

	p_ret = (char *)calloc(count_digit_base_u(n, base) + 1, sizeof(char));
	if (p_ret == NULL)
		return (NULL);
	if (n == 0)
		p_ret[0] = '0';
	else
		set_number_base_u(n, p_ret, count_digit_base_u(n, base) - 1, base);
	return (p_ret);
}

static size_t	count_digit_base_u(unsigned long long int n, char *base)
{
	size_t	cnt;
	size_t	len_base;

	cnt = 0;
	len_base = ft_strlen(base);
	if (n == 0)
		cnt = 1;
	while (n != 0)
	{
		n /= len_base;
		cnt++;
	}
	return (cnt);
}

static void	set_number_base_u(unsigned long long int n,
		char *s, size_t cnt, char *base)
{
	size_t	len_base;

	len_base = ft_strlen(base);
	s[cnt] = base[n % len_base];
	if (n / len_base)
		set_number_base_u(n / len_base, s, --cnt, base);
}
