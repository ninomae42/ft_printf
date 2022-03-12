/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tashimiz <tashimiz@stdent.42tokyo.jp>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/10 19:37:16 by tashimiz          #+#    #+#             */
/*   Updated: 2022/03/12 23:54:50 by tashimiz         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

static ssize_t	put_arg(t_info *info, va_list *ap);
static int		put_til_percent(char **fmt, int cnt);

int	ft_printf(const char *fmt, ...)
{
	int		cnt;
	va_list	ap;
	t_info	*info;

	if (fmt == NULL)
		return (ERROR);
	cnt = 0;
	va_start(ap, fmt);
	while (*fmt != '\0' && cnt != ERROR)
	{
		if (*fmt == '%')
		{
			info = parse_flag(&fmt, &ap, cnt);
			if (info == NULL)
				return (ERROR);
			if (put_arg(info, &ap) != ERROR)
				cnt += info->cnt;
			else
				cnt = info->cnt;
			free(info);
		}
		else
			cnt = put_til_percent((char **)&fmt, cnt);
	}
	return (cnt);
}

static ssize_t	put_arg(t_info *info, va_list *ap)
{
	ssize_t	res;

	if (info->conv_specifier == 'c')
		res = put_c((unsigned char)va_arg(*ap, int), info);
	else if (info->conv_specifier == 's')
		res = put_s(va_arg(*ap, char *), info);
	else if (info->conv_specifier == 'd' || info->conv_specifier == 'i')
		res = put_di(va_arg(*ap, int), info);
	else if (info->conv_specifier == 'p')
		res = put_p((unsigned long long int)va_arg(*ap, void *), info);
	else if (info->conv_specifier == 'u')
		res = put_u(va_arg(*ap, unsigned int), info);
	else if (info->conv_specifier == 'x')
		res = put_x(va_arg(*ap, unsigned int), info, BASE_16_L);
	else if (info->conv_specifier == 'X')
		res = put_x(va_arg(*ap, unsigned int), info, BASE_16_U);
	else if (info->conv_specifier == '%')
		res = put_percent('%', info);
	else
		res = ERROR;
	info->cnt = res;
	return (res);
}

static int	put_til_percent(char **fmt, int cnt)
{
	size_t	len;
	ssize_t	ret;

	len = 0;
	while ((*fmt)[len] != '\0' && (*fmt)[len] != '%')
		len++;
	if ((size_t)INT_MAX < len || (size_t)INT_MAX < (size_t)cnt + len)
		return (ERROR);
	ret = write(1, *fmt, len);
	if (ret != -1)
		(*fmt) += ret;
	ret = ret + (ssize_t)cnt;
	return ((int)ret);
}
