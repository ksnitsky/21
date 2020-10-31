
#include <stdio.h>

int     main()
{
	printf("%s", ft_strdup("132"));
}

#include <stdio.h>

int     main()
{
	int *intarr;
	int min = 8;
	int max = 1;

	intarr = ft_range(min, max);
	printf("%p\n", intarr);
	while (min < max)
	{
		printf("%d\n", *intarr);
		if (*intarr == max - 1)
			break ;
		else
			intarr++;
	}
}