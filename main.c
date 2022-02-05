#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret_honke;
	int		ret_jisaku;

	ret_honke = printf("hello%c%s%%\n", '/', "42Tokyo");
	fflush(stdout);
	ret_jisaku = ft_printf("hello%c%s%%\n", '/', "42Tokyo");
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n", ret_jisaku);
	return (0);
}
