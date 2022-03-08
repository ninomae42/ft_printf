#include "ft_printf.h"

size_t	ft_putchar_cnt(const char c)
{
	write(1, &c, 1);
	return (1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (0);
	len = 0;
	while (s[len] != '\0')
		len++;
	return (len);
}

size_t	ft_putstr_cnt(const char *s)
{
	size_t	len;
	size_t	ret;

	if (s == NULL)
		return (0);
	len = ft_strlen(s);
	ret = len;
	while (INT_MAX < len)
	{
		write(1, s, INT_MAX);
		s += INT_MAX;
		len -= INT_MAX;
	}
	write(1, s, len);
	return (ret);
}
