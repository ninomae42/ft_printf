#include "../ft_printf.h"

void	ft_putchar_cnt(char c, size_t *cnt)
{
	*cnt += 1;
	write(1, &c, 1);
}
