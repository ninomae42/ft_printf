/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:38:04 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/10 19:57:46 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

t_info	*parse_flag(const char **fmt, va_list *ap, int cnt)
{
	t_info	*info;

	info = info_new(cnt);
	if (info == NULL)
		return (NULL);
	(*fmt)++;
	while (is_flag(**fmt))
		set_flag((*(*fmt)++), info);
	if (ft_isdigit(**fmt) || **fmt == '*')
		set_min_width(fmt, info, ap);
	if (**fmt == '.' && *(*fmt + 1) == '*')
		set_precision(fmt, info, ap);
	else if (**fmt == '.')
		set_precision(fmt, info, NULL);
	if (is_conv_specifier(**fmt))
		info->conv_specifier = *((*fmt)++);
	if (info->cnt == ERROR)
	{
		free(info);
		return (NULL);
	}
	return (info);
}

void	set_flag(const char flag, t_info *info)
{
	if (flag == '-')
	{
		info->left_align = true;
		info->zero_padding = false;
	}
	else if (flag == '0' && !info->left_align)
		info->zero_padding = true;
	else if (flag == '+')
	{
		info->sign = true;
		info->sign_space = false;
	}
	else if (flag == ' ' && !info->sign)
		info->sign_space = true;
	else if (flag == '#')
		info->alternate = true;
}

void	set_min_width(const char **fmt, t_info *info, va_list *ap)
{
	int	min_width;

	if (**fmt == '*')
	{
		min_width = va_arg(*ap, int);
		if (min_width == INT_MIN)
			info->cnt = ERROR;
		else if (min_width < 0)
		{
			set_flag('-', info);
			info->min_width = -min_width;
		}
		else
			info->min_width = min_width;
		(*fmt)++;
	}
	else
	{
		info->min_width = ft_atoi(*fmt);
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}

void	set_precision(const char **fmt, t_info *info, va_list *ap)
{
	int	precision;

	if (ap != NULL)
	{
		precision = va_arg(*ap, int);
		if (precision >= 0)
			info->precision = precision;
		else
			info->precision = DEFAULT;
		(*fmt) += 2;
	}
	else
	{
		(*fmt)++;
		precision = ft_atoi(*fmt);
		if (precision >= 0)
			info->precision = precision;
		else
			info->precision = DEFAULT;
		while (ft_isdigit(**fmt))
			(*fmt)++;
	}
}
