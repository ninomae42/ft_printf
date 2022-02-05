#include "../ft_printf.h"

void	ft_putstr_fd_cnt(char *s, int fd, size_t *cnt)
{
	if (s == NULL)
		return ;
	*cnt += ft_strlen(s);
	write(fd, s, ft_strlen(s));
}
