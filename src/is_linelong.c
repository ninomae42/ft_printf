#include "../ft_printf.h"

int	is_line_long(int *err_flag, size_t cur_cnt, size_t next_cnt)
{
	if (cur_cnt + next_cnt >= INT_MAX)
	{
		*err_flag = -1;
		return (1);
	}
	return (0);
}
