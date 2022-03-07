#ifndef HEADER_H
# define HEADER_H
# include <ctype.h>
# include <limits.h>
# include <stdio.h>
# include <stdarg.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <unistd.h>
# define ERROR -1
# define NULL_STR "(null)"
# define BASE_10 "0123456789"
# define BASE_16L "0123456789abcdef"
# define BASE_16U "0123456789ABCDEF"

typedef struct s_finfo {
	bool	alter_flag;
	bool	space_flag;
	bool	plus_flag;
	bool	zero_flag;
	bool	minus_flag;
	int		min_field_width;
	int		precision;
	char	conv_specifier;
	bool	is_error;
}	t_finfo;

/* parser.c / functions for flag parse and set its value */
void	set_flag(const char flag, t_finfo **info);
void	set_min_field_width(const char **fmt, t_finfo **info, va_list *ap);
void	set_precision(const char **fmt, t_finfo **info, va_list *ap);
void	parse_flag(const char **fmt, t_finfo **finfo, va_list *ap);

/* parser_util.c / funcitons for flag parse utilities */
t_finfo	*new_flag(void);
void	print_flag_info(t_finfo *info);
bool	is_conv_specifier(const char c);
bool	is_flag(const char c);

/* itoa.c */
char	*ft_itoa(int n);
size_t	count_digit(int n);

/* ulonglong_toa.c */
size_t	count_digit_ulonglong_base(unsigned long long int n, char *base);
char	*ulonglong_toa_base(unsigned long long int nbr, char *base);

/* strutils.c */
void	ft_putchar(const char c);
void	ft_putstr(const char *s);
size_t	ft_strlen(const char *s);
void	ft_putstr_len(const char *s, size_t max_len);

/* put_utils1.c */
size_t	get_padding_len(size_t len, t_finfo *info);
char	get_padding_char(t_finfo *info);
void	put_padding(size_t padding_len, t_finfo *info);
size_t	get_print_len(char *s, t_finfo *info);

/* put_utils2.c */
size_t	get_print_len_num(char *s, t_finfo *info);
size_t	get_padding_len_num(size_t len, t_finfo *info);

#endif
