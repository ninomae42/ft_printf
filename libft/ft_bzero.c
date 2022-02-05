/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@student.42tokyo.jp      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/27 16:53:53 by tashimiz          #+#    #+#             */
/*   Updated: 2022/01/27 16:53:56 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/libft.h"

// write zeroes to a byte string
void	ft_bzero(void *s, size_t n)
{
	if (n == 0)
		return ;
	else
		ft_memset(s, 0, n);
}
