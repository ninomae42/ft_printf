#include <assert.h>
#include <stdio.h>
#include "ft_printf.h"

void	case1(void);
void	case2(void);
void	case3(void);
void	case4(void);
void	case5(void);
void	case6(void);

int	main(void)
{
	case1();
	case2();
	case3();
	case4();
	case5();
	case6();
	return (0);
}

void	case1(void)
{
	int	ret_honke;
	int	ret_jisaku;

	puts("Case 1 -- no specifier");
	ret_honke = printf("hello, world!\n");
	fflush(stdout);
	ret_jisaku = ft_printf("hello, world!\n");
	printf("ret_honke:\t%d\n", ret_honke);
	printf("ret_jisaku:\t%d\n", ret_jisaku);
	assert(ret_honke == ret_jisaku);
	puts("case1 - OK\n");
}

void	case2(void)
{
	int		ret_honke;
	int		ret_jisaku;
	char	str[] = "hello, world!\n";

	puts("Case 2 -- %c and %s and %%");
	ret_honke = printf("%c%c%% %s\n", '4', '2', str);
	fflush(stdout);
	ret_jisaku = ft_printf("%c%c%% %s\n", '4', '2', str);
	printf("ret_honke:\t%d\n", ret_honke);
	printf("ret_jisaku:\t%d\n", ret_jisaku);
	assert(ret_honke == ret_jisaku);
	puts("case2 - OK\n");
}

void	case3(void) {
	int		ret_honke;
	int		ret_jisaku;

	puts("Case 3 -- %d and %i");
	ret_honke = printf("%d %d %d %d : %i %i %i \n",
		-2147483648, 0, 2147483647, 4294967295, -2147483648, 0, 2147483647, 4294967295);
	fflush(stdout);
	ret_jisaku = ft_printf("%d %d %d %d : %i %i %i \n",
		-2147483648, 0, 2147483647, 4294967295, -2147483648, 0, 2147483647, 4294967295);
	printf("ret_honke:\t%d\n", ret_honke);
	printf("ret_jisaku:\t%d\n", ret_jisaku);
	assert(ret_honke == ret_jisaku);
	puts("case3 - OK\n");
}


void	case4(void)
{
	int		ret_honke;
	int		ret_jisaku;

	puts("Case 5 -- %x and %X");
	ret_honke = printf("%x %x %x %x : %X %X %X %X\n",
		0, 4294967295, -1, 100, 0, 4294967295, -1, 100);
	fflush(stdout);
	ret_jisaku = ft_printf("%x %x %x %x : %X %X %X %X\n",
		0, 4294967295, -1, 100, 0, 4294967295, -1, 100);
	printf("ret_honke:\t%d\n", ret_honke);
	printf("ret_jisaku:\t%d\n", ret_jisaku);
	assert(ret_honke == ret_jisaku);
	puts("case5 - OK\n");
}

void	case5(void)
{
	int		ret_honke;
	int		ret_jisaku;
	char	*addr;

	puts("Case 5 -- %p");
	ret_honke = 0;
	ret_jisaku = 0;
	addr = ft_strdup("");
	ret_honke = printf("%p, %p\n", addr, NULL);
	fflush(stdout);
	ret_jisaku = ft_printf("%p, %p\n", addr, NULL);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);
	free(addr);
	assert(ret_honke == ret_jisaku);
	puts("case5 - OK\n");
}

void	case6(void)
{
	int		ret_honke;
	int		ret_jisaku;
	char	*addr;

	puts("Case 6 -- %s (NULL pointer)");
	ret_honke = 0;
	ret_jisaku = 0;
	addr = ft_strdup("text");
	ret_honke = printf("%s, %s\n", addr, NULL);
	fflush(stdout);
	ret_jisaku = ft_printf("%s, %s\n", addr, NULL);
	printf("honke: %d\n", ret_honke);
	printf("jisaku: %d\n\n", ret_jisaku);
	free(addr);
	assert(ret_honke == ret_jisaku);
	puts("case6 - OK\n");
}
