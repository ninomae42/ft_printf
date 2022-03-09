#include "ft_printf.h"

size_t	count_digit(int n)
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

static void	set_number(long int nbr, char *s, size_t cnt)
{
	if (nbr < 0)
	{
		nbr *= -1;
		s[0] = '-';
	}
	s[cnt] = "0123456789"[nbr % 10];
	if (nbr / 10)
		set_number(nbr / 10, s, --cnt);
}

char	*ft_itoa(int n)
{
	char	*p_ret;

	p_ret = (char *)calloc(count_digit(n) + 1, sizeof(char));
	if (p_ret == NULL)
		return (NULL);
	if (n == 0)
		p_ret[0] = '0';
	else
		set_number(n, p_ret, count_digit(n) - 1);
	return (p_ret);
}
