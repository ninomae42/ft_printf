#include "../ft_printf.h"

void	ft_putstr_cnt(char *s, size_t *cnt)
{
	if (s == NULL)
	{
		write(1, NULL_STR, ft_strlen(NULL_STR));
		*cnt += ft_strlen(NULL_STR);
	}
	else
	{
		*cnt += ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
}
