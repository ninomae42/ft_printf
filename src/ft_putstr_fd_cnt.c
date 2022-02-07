#include "../ft_printf.h"

void	ft_putstr_cnt(char *s, size_t *cnt, int *err_flag)
{
	if (s == NULL && !is_line_long(err_flag, *cnt, ft_strlen(NULL_STR)))
	{
		write(1, NULL_STR, ft_strlen(NULL_STR));
		*cnt += ft_strlen(NULL_STR);
	}
	else if (is_line_long(err_flag, *cnt, ft_strlen(s)))
		return ;
	else
	{
		*cnt += ft_strlen(s);
		write(1, s, ft_strlen(s));
	}
}
