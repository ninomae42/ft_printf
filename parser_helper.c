#include "ft_printf.h"

t_info	*info_new(int cnt)
{
	t_info	*new;

	new = (t_info *)calloc(1, sizeof(t_info));
	if (new == NULL)
		return (NULL);
	new->alternate = false;
	new->sign = false;
	new->sign_space = false;
	new->zero_padding = false;
	new->left_align = false;
	new->min_width = DEFAULT;
	new->precision = DEFAULT;
	new->conv_specifier = '\0';
	new->cnt = cnt;
	return (new);
}

void	print_flag_info(t_info *info)
{
	printf("alternate: %d\n", info->alternate);
	printf("sign: %d\n", info->sign);
	printf("sign_space: %d\n", info->sign_space);
	printf("zero_padding: %d\n", info->zero_padding);
	printf("left_align: %d\n", info->left_align);
	printf("min_width: %d\n", info->min_width);
	printf("precision: %d\n", info->precision);
	printf("conv_specifier: %c\n", info->conv_specifier);
	printf("cnt: %d\n", info->cnt);
}

bool	is_flag(const char flag)
{
	if (strchr("-0# +", flag) != NULL)
		return (true);
	return (false);
}

bool	is_conv_specifier(const char c)
{
	if (strchr("cspdiuxX%", c) != NULL)
		return (true);
	return (false);
}
