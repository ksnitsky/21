/* ex01 */
#include <stdio.h>
int		ft_plus(int i)
{
	return (i + 2);
}

int		main()
{
	int arr[10] = {3, 8, 1, 6, 2, 3, 8, 1, 6, 2};
	int i = 0;
	int *karr = ft_map(arr, 10, &ft_plus);
	while (i < 10)
	{
		printf("%d, ", karr[i]);
		i++;
	}
	return (0);
}

/* ex02 */
#include <stdio.h>
int		ft_finda(char *arr)
{
	while (*arr)
	{
		if (*arr == 'b')
			return (1);
		else
			arr++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	int a;

	a = ft_any(argv, &ft_finda);
	printf("%d", a);
	return (0);
}

/* ex03 */
#include <stdio.h>
int		ft_finda(char *arr)
{
	while (*arr)
	{
		if (*arr == 'b')
			return (1);
		else
			arr++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	(void)argc;
	int a;

	a = ft_count_if(argv, argc, &ft_finda);
	printf("%d", a);
	return (0);
}

/* ex04 */
#include <stdio.h>
int		ft_compare(int a, int b)
{
	if (a < b)
		return (-1);
	else if (a == b)
		return (0);
	else
		return (1);
}

int		main()
{
	int i;
	int A[] = {1, 2, 3, 4, 5, 6};
	i = ft_is_sort(A, 6, &ft_compare);
	printf("%d", i);
	return (0);
}