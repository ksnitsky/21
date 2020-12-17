#include <unistd.h>

void
	no_doubles(char *str)
{
	int	i;
	int	j;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				str[j] = '*';
			j++;
		}
		i++;
	}
}

void
	print_union(char *fir, char *sec)
{
	while (*fir)
	{
		if (*fir != '*')
			write(1, fir, 1);
		fir++;
	}
	while (*sec)
	{
		if (*sec != '*')
			write(1, sec, 1);
		sec++;
	}
}

void
	ft_union(char *fir, char *sec)
{
	int	i;
	int	j;

	no_doubles(fir);
	no_doubles(sec);
	i = 0;
	while (fir[i] != '\0')
	{
		j = 0;
		while (sec[j] != '\0')
		{
			if (fir[i] == sec[j])
				sec[j] = '*';
			j++;
		}
		i++;
	}
	print_union(fir, sec);
}

int
	main(int argc, char **argv)
{
	if (argc == 3)
		ft_union(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
