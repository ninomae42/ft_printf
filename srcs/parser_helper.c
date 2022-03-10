/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_helper.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:38:12 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:38:13 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info	*info_new(int cnt)
{
	t_info	*new;

	new = (t_info *)calloc(1, sizeof(t_info));
	if (new == NULL)
		return (NULL);
	new->alternate = false;
	new->sign = false;
	new->sign_space = false;
	new->zero_padding = false;
	new->left_align = false;
	new->min_width = DEFAULT;
	new->precision = DEFAULT;
	new->conv_specifier = '\0';
	new->cnt = cnt;
	return (new);
}

bool	is_flag(const char flag)
{
	if (ft_strchr("-0# +", flag) != NULL)
		return (true);
	return (false);
}

bool	is_conv_specifier(const char c)
{
	if (ft_strchr("cspdiuxX%", c) != NULL)
		return (true);
	return (false);
}
