#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_rush(int x, int y)
{
	int i;
	int j;

	j = 0;
	while (j < y)
	{
		i = 0;
		while (i < x)
		{
			if ((i == 0 || i == x - 1) && (j == 0 || j == y - 1))
				ft_putchar('o');
			else if ((j > 0 && j < y) && (i > 0 && i < x - 1))
				ft_putchar(' ');
			else if ((i > 0 && i < x - 1) && (j == 0 || j < y))
				ft_putchar('-');
			else
				ft_putchar('|');
			if (i == x - 1)
			{
				ft_putchar('\n');
				j++;
			}
			i++;
		}
	}
}

int		main(void)
{
	ft_rush(20, 20);
}
