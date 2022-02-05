#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./include/libft.h"

int		ft_printf(const char *fmt, ...);

void	ft_putchar_fd_cnt(char c, int fd, size_t *cnt);
void	ft_putstr_fd_cnt(char *s, int fd, size_t *cnt);

#endif
