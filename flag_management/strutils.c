#include "header.h"

void	ft_putchar(const char c)
{
	write(1, &c, 1);
}

size_t	ft_strlen(const char *s)
{
	size_t	len;

	len = 0;
	if (s != NULL)
		while (s[len] != '\0')
			len++;
	return (len);
}

void	ft_putstr(const char *s)
{
	if (s != NULL)
		write(1, s, ft_strlen(s));
	else
		ft_putstr(NULL_STR);
}

void	ft_putstr_len(const char *s, size_t max_len)
{
	size_t	len;

	if (s != NULL)
	{
		len = ft_strlen(s);
		if (len > max_len)
			len = max_len;
		write(1, s, len);
	}
	else
		ft_putstr_len(NULL_STR, max_len);
}
