#include "header.h"

// set flag information to struct pointer according to the character
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

/* set the minimun field width to struct pointer according to
  character or variable */
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

/* set the precision to struct pointer according to
  character or variable */
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

// parse the format string from next to '%' to conversion specifier
void	parse_flag(const char **fmt, t_finfo **finfo, va_list *ap, int ret)
{
	*finfo = new_flag(ret);
	if (finfo == NULL)
	{
		*finfo = NULL;
		return ;
	}
	(*fmt)++;
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
