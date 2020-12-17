#include <limits.h>
#include <stdio.h>

int
	ft_printf(const char *format, ...);

int
	main(void)
{
	int i = 0;
	printf("%%15.10xx, %%15.10dd, %%15.10xx, %%15.10ss\n");
	i = ft_printf("%15.10xx, %15.10dd, %15.10xx, %15.10ss", UINT_MAX, INT_MIN, UINT_MAX, "POOOPQW");
	printf("\n%d \n", i);
	i = printf("%15.10xx, %15.10dd, %15.10xx, %15.10ss", UINT_MAX, INT_MIN, UINT_MAX, "POOOPQW");
	printf("\n%d \n", i);
}
