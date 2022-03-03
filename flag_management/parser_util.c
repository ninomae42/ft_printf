#include "header.h"

// create new struct pointer to handle flag information.
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

// print current flag information for convenience
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

// checks whether the character is conviersion specifier or not
bool	is_conv_specifier(const char c)
{
	if (strchr("cspdiuxX%", c) != NULL)
		return (true);
	return (false);
}

// checks whether the character is flag or not
bool	is_flag(const char c)
{
	if (strchr("-0# +", c) != NULL)
		return (true);
	return (false);
}
