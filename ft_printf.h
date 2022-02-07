#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "./include/libft.h"
# define NULL_STR "(null)"

int		ft_printf(const char *fmt, ...);

void	ft_putfmt(const char **fmt, va_list *ap, size_t *cnt, int *err_flag);
void	ft_putchar_cnt(char c, size_t *cnt);
void	ft_putstr_cnt(char *s, size_t *cnt, int *err_flag);
void	ft_putnbr_base_cnt(long long nbr, char *base, size_t *cnt);
void	ft_putnbr_base_uint_cnt(unsigned long long nbr,
			char *base, size_t *cnt);

int		is_line_long(int *err_flag, size_t cur_cnt, size_t next_cnt);

#endif
