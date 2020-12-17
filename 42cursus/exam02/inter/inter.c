#include <unistd.h>
#include <stdio.h>

void
	no_doubles(char *poop)
{
	int		i;
	int		j;

	i = 0;
	while (poop[i])
	{
		j = i + 1;
		while (poop[j])
		{
			if (poop[i] == poop[j])
				poop[j] = '*';
			j++;
		}
		i++;
	}
}

void
	inter(char *one, char *two)
{
	int		i;
	int		j;

	i = 0;
	no_doubles(one);
	while (one[i])
	{
		j = 0;
		while (two[j])
		{
			if (one[i] == two[j])
			{
				write(1, &one[i], 1);
				break ;
			}
			j++;
		}
		i++;
	}
}

int
	main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
