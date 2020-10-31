
#include <stdio.h>
int	main(void)
{
	int a;
	int b;

	a = 47;
	b = 81;
	
	int *ptra;
	int *ptrb;

	ptra = &a;
	ptrb = &b;	

	printf("%d\n", *ptra);
	printf("%d\n", *ptrb);
	ft_swap(ptra, ptrb);
	printf("%d\n", *ptra);
	printf("%d\n", *ptrb);
}