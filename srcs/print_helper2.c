#include "ft_printf.h"

size_t	get_print_len_n(char *nbr, t_info *info)
{
	size_t	precision_len;

	precision_len = ft_strlen(nbr);
	if (info->precision >= 0 && info->precision > precision_len)
		precision_len = info->precision;
	return (precision_len);
}

size_t	get_zero_pad_len(char *nbr, t_info *info)
{
	size_t	nbr_len;
	size_t	zero_pad_len;

	zero_pad_len = 0;
	nbr_len = ft_strlen(nbr);
	if (info->precision >= 0 && info->precision > nbr_len)
		zero_pad_len = info->precision - nbr_len;
	return (zero_pad_len);
}

size_t	get_print_len_hex(unsigned int n, char *nbr, t_info *info)
{
	size_t	print_len;

	print_len = ft_strlen(nbr);
	if (info->precision >= 0 && info->precision > print_len)
		print_len = info->precision;
	if (n != 0 && info->alternate)
		print_len += 2;
	return (print_len);
}

size_t	get_print_len_di(int n, char *nbr, t_info *info)
{
	size_t	print_len;

	print_len = ft_strlen(nbr);
	if (info->precision >= 0 && info->precision > print_len)
		print_len = info->precision;
	if ((info->sign_space || info->sign) && n >= 0)
		print_len++;
	return (print_len);
}

bool	is_alter_valid(char *nbr, t_info *info)
{
	size_t	len;

	len = ft_strlen(nbr);
	if (!(len == 1 && nbr[0] == '0') && info->alternate)
		return (true);
	return (false);
}
