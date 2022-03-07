#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <ctype.h>
# include <limits.h>
# include <stdarg.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# define ERROR -1
# define DEFAULT -1

typedef struct s_info {
	bool	alternate;
	bool	sign;
	bool	sign_space;
	bool	zero_padding;
	bool	left_align;
	int		min_width;
	int		precision;
	char	conv_specifier;
	int		cnt;
}	t_info;

/* parser.c */
t_info	*parse_flag(const char **fmt, va_list *ap, int cnt);
void	set_flag(const char flag, t_info *info);
void	set_min_width(const char **fmt, t_info *info, va_list *ap);
void	set_precision(const char **fmt, t_info *info, va_list *ap);

/* parser_helper.c */
t_info	*info_new(int cnt);
void	print_flag_info(t_info *info);
bool	is_flag(const char flag);
bool	is_conv_specifier(const char c);

#endif
