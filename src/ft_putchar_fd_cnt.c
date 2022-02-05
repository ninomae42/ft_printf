#include "../ft_printf.h"

void	ft_putchar_fd(char c, int fd);

void	ft_putchar_fd_cnt(char c, int fd, size_t *cnt)
{
	*cnt += 1;
	write(fd, &c, 1);
}
