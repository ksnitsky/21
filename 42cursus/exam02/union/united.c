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
	print_union(char *pee, char *poo)
{
	while (*pee)
	{
		if (*pee != '*')
			write(1, pee, 1);
		pee++;
	}
	while (*poo)
	{
		if (*poo != '*')
			write(1, poo, 1);
		poo++;
	}
}

void
	ft_union(char *one, char *two)
{
	int		i;
	int		j;

	no_doubles(one);
	no_doubles(two);
	i = 0;
	while (one[i])
	{
		j = 0;
		while (two[j])
		{
			if (one[i] == two[j])
				two[j] = '*';
			j++;
		}
		i++;
	}
	print_union(one, two);
}

int
	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
