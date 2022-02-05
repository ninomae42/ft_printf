#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret_honke;
	int		ret_jisaku;

	ret_honke = printf("hello%c\n", 'O');
	fflush(stdout);
	ret_jisaku = ft_printf("hello%c\n", 'O');
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n", ret_jisaku);
	return (0);
}
