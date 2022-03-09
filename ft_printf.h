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
# define NULL_STR "(null)"
# define BASE_10 "0123456789"
# define BASE_16_L "0123456789abcdef"
# define BASE_16_U "0123456789ABCDEF"

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

/* ft_putsome.c */
size_t	ft_putchar_cnt(const char c);
size_t	ft_strlen(const char *s);
size_t	ft_putstr_cnt(const char *s);
size_t	ft_putstr_len_cnt(const char *s, size_t max_len);

/* print_helper.c */
bool	is_fmt_long(size_t current_len, t_info *info);
size_t	get_padding_len(size_t print_len, t_info *info);
size_t	get_print_len(char *s, t_info *info);
char	get_pad_char(t_info *info);

/* print_helper2.c */
size_t	get_print_len_n(char *nbr, t_info *info);
size_t	get_zero_pad_len(char *nbr, t_info *info);

/* put_c.c */
ssize_t	put_pad_c(unsigned char c, size_t padding_len, t_info *info);
ssize_t	put_c(unsigned char c, t_info *info);
ssize_t	put_percent(unsigned char c, t_info *info);
ssize_t	put_pad_percent(unsigned char c, size_t padding_len, t_info *info);

/* put_s.c */
ssize_t	put_pad_s(char *s, t_info *info, size_t padding_len, size_t print_len);
ssize_t	put_s(char *s, t_info *info);

/* put_p.c */
ssize_t	put_pad_p(char *p, t_info *info, size_t padding_len);
ssize_t	put_p(unsigned long long int addr, t_info *info);

/* put_u.c */
ssize_t	put_zero_pad_u(char *nbr, t_info *info, size_t padding_len_num);
ssize_t	put_pad_u(char *nbr,
			t_info *info, size_t padding_len, size_t padding_len_num);
ssize_t	put_u(unsigned int n, t_info *info);

/* itoa_base_8byte_u.c */
char	*itoa_base_8byte_u(unsigned long long int n, char *base);

#endif
