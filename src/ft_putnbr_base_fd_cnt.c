#include "../ft_printf.h"

static int	is_same_char_twice(const char *base)
{
	size_t	i;

	i = 0;
	while (base[i] != '\0' && base[i + 1] != '\0')
	{
		if (ft_strchr(&base[i + 1], base[i]) != NULL)
			return (1);
		i++;
	}
	return (0);
}

static int	is_invalid_base(const char *base)
{
	if (ft_strlen(base) == 0 || ft_strlen(base) == 1)
		return (1);
	else if (ft_strchr(base, '+') || ft_strchr(base, '-'))
		return (1);
	else if (is_same_char_twice(base))
		return (1);
	else
		return (0);
}

void	ft_putnbr_base_fd_cnt(long long nbr, char *base, int fd, size_t *cnt)
{
	size_t				len_base;
	unsigned long long	n;

	len_base = ft_strlen(base);
	if (is_invalid_base(base))
		return ;
	n = nbr;
	if (nbr < 0)
	{
		ft_putchar_fd('-', fd);
		*cnt += 1;
		n = -nbr;
	}
	if (n / len_base)
		ft_putnbr_base_fd_cnt(n / len_base, base, fd, cnt);
	*cnt += 1;
	ft_putchar_fd(base[n % len_base], fd);
}
