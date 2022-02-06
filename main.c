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

	ret_honke = 0;
	ret_jisaku = 0;
	ret_honke = printf("%d, %i\n", 2147483647, -2147483648);
	fflush(stdout);
	ret_jisaku = ft_printf("%d, %i\n", 2147483647, -2147483648);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n", ret_jisaku);
	return (0);
}
