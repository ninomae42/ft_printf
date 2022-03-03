#include <ctype.h>
#include <limits.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#define ERROR -1

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

t_finfo	*new_flag(void)
{
	t_finfo	*new;

	new = (t_finfo *)calloc(1, sizeof(t_finfo));
	if (new == NULL)
		return (NULL);
	new->alter_flag = false;
	new->space_flag = false;
	new->plus_flag = false;
	new->zero_flag = false;
	new->minus_flag = false;
	new->min_field_width = -1;
	new->precision = -1;
	new->conv_specifier = '\0';
	new->is_error = false;
	return (new);
}

void	print_flag_info(t_finfo *info)
{
	printf("alter_flag: %d\n", info->alter_flag);
	printf("space_flag: %d\n", info->space_flag);
	printf("plus_flag: %d\n", info->plus_flag);
	printf("zero_flag: %d\n", info->zero_flag);
	printf("minus_flag: %d\n", info->minus_flag);
	printf("min_field_width: %d\n", info->min_field_width);
	printf("precision: %d\n", info->precision);
	printf("conv_specifier: %c\n", info->conv_specifier);
	printf("is_error: %d\n", info->is_error);
}

bool	is_conv_specifier(const char c)
{
	if (strchr("cspdiuxX%", c) != NULL)
		return (true);
	return (false);
}

bool	is_flag(const char c)
{
	if (strchr("-0# +", c) != NULL)
		return (true);
	return (false);
}

void	set_flag(const char flag, t_finfo **info)
{
	if (flag == '-')
	{
		(*info)->minus_flag = true;
		(*info)->zero_flag = false;
	}
	else if (flag == '0' && (*info)->minus_flag == false)
		(*info)->zero_flag = true;
	else if (flag == '+')
	{
		(*info)->plus_flag = true;
		(*info)->space_flag = false;
	}
	else if (flag == ' ' && (*info)->plus_flag == false)
		(*info)->space_flag = true;
	else if (flag == '#')
		(*info)->alter_flag = true;
}

void	set_min_field_width(const char **fmt, t_finfo **info, va_list *ap)
{
	int	min_field_width_ap;

	if (**fmt == '*')
	{
		min_field_width_ap = va_arg(*ap, int);
		if (min_field_width_ap < 0)
		{
			if (min_field_width_ap == INT_MIN)
				(*info)->is_error = true;
			else
			{
				set_flag('-', info);
				(*info)->min_field_width = -min_field_width_ap;
			}
		}
		else
			(*info)->min_field_width = min_field_width_ap;
		(*fmt)++;
	}
	else
	{
		(*info)->min_field_width = atoi(*fmt);
		while (isdigit(**fmt))
			(*fmt)++;
	}
}

void	set_precision(const char **fmt, t_finfo **info, va_list *ap)
{
	int	precision_ap;

	if (ap != NULL)
	{
		precision_ap = va_arg(*ap, int);
		if (precision_ap >= 0)
		{
			(*info)->precision = 0;
			(*info)->precision = precision_ap;
		}
		(*fmt) += 2;
	}
	else
	{
		(*fmt)++;
		(*info)->precision = 0;
		(*info)->precision = atoi(*fmt);
		while (isdigit(**fmt))
			(*fmt)++;
	}
}

void	parse_flag(const char **fmt, t_finfo **finfo, va_list *ap)
{
	while (!is_conv_specifier(**fmt) && !((*finfo)->is_error))
	{
		while (is_flag(**fmt))
			set_flag(*((*fmt)++), finfo);
		if (isdigit(**fmt) || **fmt == '*')
			set_min_field_width(fmt, finfo, ap);
		if (**fmt == '.' && *((*fmt) + 1) == '*')
			set_precision(fmt, finfo, ap);
		else if (**fmt == '.')
			set_precision(fmt, finfo, NULL);
		if (!is_flag(**fmt) && **fmt != '.' && !isdigit(**fmt)
			&& !is_conv_specifier(**fmt))
			break ;
	}
	if (is_conv_specifier(**fmt))
		(*finfo)->conv_specifier = *((*fmt)++);
}

int	ft_printf(const char *fmt, ...)
{
	size_t	ret;
	va_list	ap;
	t_finfo	*finfo;

	ret = 0;
	if (fmt == NULL)
		return (ERROR);
	va_start(ap, fmt);
	while (*fmt != '\0')
	{
		if (*fmt == '%')
		{
			fmt++;
			finfo = new_flag();
			if (finfo == NULL)
			{
				ret = ERROR;
				break ;
			}
			parse_flag(&fmt, &finfo, &ap);
			print_flag_info(finfo);
			if (finfo->is_error)
			{
				ret = ERROR;
				free(finfo);
				break ;
			}
			free(finfo);
		}
		else
			putchar(*fmt++);
	}
	va_end(ap);
	return (ret);
}

int	main(void)
{
	int	ret;

	//ret = printf("%*.*d\n", INT_MIN, 1, 10);
	ret = ft_printf("%*.*d\n", INT_MIN, 1, 10);
	printf("ret: %d\n", ret);
	//ft_printf("%+-4.2 0.8 #1 *.* dhogehoge\n", 42, 42);
	//ft_printf("%04.12d%%hoge\n");
}
