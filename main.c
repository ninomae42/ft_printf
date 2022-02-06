#include <stdio.h>
#include "ft_printf.h"

int	main(void)
{
	int		ret_honke;
	int		ret_jisaku;
	char	*addr;

	puts("no specifier and %s and %c and %%");
	ret_honke = printf("hello%c%s%%\n", '/', "42Tokyo");
	fflush(stdout);
	ret_jisaku = ft_printf("hello%c%s%%\n", '/', "42Tokyo");
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);

	puts("%d and %i");
	ret_honke = 0;
	ret_jisaku = 0;
	ret_honke = printf("%d, %i\n", 2147483647, -2147483648);
	fflush(stdout);
	ret_jisaku = ft_printf("%d, %i\n", 2147483647, -2147483648);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);

	puts("%u");
	ret_honke = 0;
	ret_jisaku = 0;
	ret_honke = printf("%u\n", 4294967295);
	fflush(stdout);
	ret_jisaku = ft_printf("%u\n", 4294967295);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);

	puts("%x and %X");
	ret_honke = 0;
	ret_jisaku = 0;
	ret_honke = printf("%x : %X\n", 100, 100);
	fflush(stdout);
	ret_jisaku = ft_printf("%x : %X\n", 100, 100);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);

	puts("%p");
	ret_honke = 0;
	ret_jisaku = 0;
	addr = ft_strdup("");
	ret_honke = printf("%p\n", addr);
	fflush(stdout);
	ret_jisaku = ft_printf("%p\n", addr);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);
	free(addr);
	return (0);
}
