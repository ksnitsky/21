#include "../includes/ft_rush.h"
#include <stdio.h>

void	ft_print_one(char *inp, char *arr)
{
	int i;

	i = 0;
	while (arr[i])
	{
		if (*inp != arr[i])
			i++;
		else
		{
			while (arr[i] != '\n')
			{
				if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
				{
					write(1, &arr[i], 1);
					i++;
				}
				else
					i++;
			}
			if (arr[i] == '\n')
				break ;
		}
	}
	if (inp[0 + 1] != '\0')
		write(1, " ", 1);
}

void	ft_print_two(char *inp, char *arr)
{
	int i;
	int j;

	j = 0;
	i = 0;
	while (arr[i] != '\0')
	{
		if (inp[j] == arr[i])
		{
			if (inp[j + 1] == arr[i + 1])
			{
				while (arr[i] != '\n')
				{
					if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
					{
						write(1, &arr[i], 1);
						i++;
					}
					else
						i++;
				}
				if (arr[i] == '\n')
					break ;
			}
		}
		i++;
	}
	write(1, " ", 1);
}

void	ft_print_pwr(int n, char *arr)
{
	int i;
	int k;
	int j;
	
	j = 0;
	i = 0;
	k = 0;
	if (n % 3 == 0)
		n -= 1;
	while (arr[i] != '\0' && j == 0)
	{
		k = 0;
		while ((arr[i] >= 48 && arr[i] <= 57) && j == 0)
		{
			k++;
			i++;
		}
		if (n / 3 == k / 3)
		{
			while (arr[i] != '\n')
			{
				if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
				{
					write(1, &arr[i], 1);
					i++;
				}
				else
					i++;
				if (arr[i] == '\n')
				{
					j++;
					break ;
				}
			}
		}
	i++;
	}
	write(1, " ", 1);
}

void	ft_print_pwr_mi(char *arr)
{
	int i;
	int k;
	int j;
	
	j = 0;
	i = 0;
	k = 0;
	while (arr[i] != '\0' && j == 0)
	{
		k = 0;
		while ((arr[i] >= 48 && arr[i] <= 57) && j == 0)
		{
			k++;
			i++;
		}
		if (k == 3)
		{
			while (arr[i] != '\n')
			{
				if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
				{
					write(1, &arr[i], 1);
					i++;
				}
				else
					i++;
				if (arr[i] == '\n')
				{
					j++;
					break ;
				}
			}
		}
	i++;
	}
	write(1, " ", 1);
}

void	ft_print_pwr_th(char *arr)
{
	int i;
	int k;
	int j;
	
	j = 0;
	i = 0;
	k = 0;
	while (arr[i] != '\0' && j == 0)
	{
		k = 0;
		while ((arr[i] >= 48 && arr[i] <= 57) && j == 0)
		{
			k++;
			i++;
		}
		if (k == 4)
		{
			while (arr[i] != '\n')
			{
				if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
				{
					write(1, &arr[i], 1);
					i++;
				}
				else
					i++;
				if (arr[i] == '\n')
				{
					j++;
					break ;
				}
			}
		}
	i++;
	}
	write(1, " ", 1);
}

/*
if (n == 3)
		{
			if (arr[i] == '1' && arr[i + 1] == '0' && arr[i + 2] == '0' && arr[i + 3] != '0')
			{
				while (arr[i] != '\n')
				{
					if ((arr[i] >= 65 && arr[i] <= 90) || (arr[i] >= 97 && arr[i] <= 122))
					{
						write(1, &arr[i], 1);
						i++;
					}
					else
						i++;
				}
				if (arr[i] == '\n')
					break ;
			}
			else
			{	
				while (arr[i] != '\n')
					i++;
			}
		}(inp[j + 1] == arr[i + 1] && inp[j + 2] == arr[i + 2]) || 
		*/