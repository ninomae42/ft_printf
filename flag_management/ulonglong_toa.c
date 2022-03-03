#include "header.h"

size_t	count_digit_ulonglong_base(unsigned long long int n, char *base)
{
	size_t	cnt;
	size_t	base_len;

	cnt = 0;
	base_len = strlen(base);
	if (n == 0)
		cnt = 1;
	while (n != 0)
	{
		n /= base_len;
		cnt++;
	}
	return (cnt);
}

static void	set_ulonglong_nbr(
	unsigned long long int nbr, char *s, size_t cnt, char *base)
{
	size_t	len_base;

	len_base = strlen(base);
	s[cnt] = base[nbr % len_base];
	if (nbr / len_base)
		set_ulonglong_nbr(nbr / len_base, s, --cnt, base);
}

char	*ulonglong_toa_base(unsigned long long int nbr, char *base)
{
	char	*p_ret;
	size_t	digits;

	digits = count_digit_ulonglong_base(nbr, base);
	p_ret = (char *)calloc(digits + 1, sizeof(char));
	if (p_ret == NULL)
		return (NULL);
	if (nbr == 0)
		p_ret[0] = '0';
	else
		set_ulonglong_nbr(nbr, p_ret, digits - 1, base);
	return (p_ret);
}
