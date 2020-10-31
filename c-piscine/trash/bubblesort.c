void	ft_swap(int *a, int *b)
{
	int c;

	c = *a;
	*a = *b;
	*b = c;
}

void	ft_bubble(int *arr, int n)
{
	int i;
	int j;

	i = 0;
	while (i < (n - 1))
	{
		j = 0;
		while (j < (n - i - 1))
		{
			if (arr[j] > arr[j+1])
				ft_swap(&arr[j], &arr[j+1]);
			j++;
		}
		i++;
	}
}