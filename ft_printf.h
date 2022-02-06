#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "./include/libft.h"

int		ft_printf(const char *fmt, ...);

void	ft_putchar_cnt(char c, size_t *cnt);
void	ft_putstr_cnt(char *s, size_t *cnt);
void	ft_putnbr_base_cnt(long long nbr, char *base, size_t *cnt);

#endif
