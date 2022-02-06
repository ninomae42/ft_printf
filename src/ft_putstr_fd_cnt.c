#include "../ft_printf.h"

void	ft_putstr_cnt(char *s, size_t *cnt)
{
	if (s == NULL)
		return ;
	*cnt += ft_strlen(s);
	write(1, s, ft_strlen(s));
}
