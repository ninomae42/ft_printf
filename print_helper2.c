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
