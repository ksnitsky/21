#include <unistd.h>

void	intdup(char *str)
{
	int j;
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[j] == str[i])
			{
				str[j] = '*';
				j++;
			}
			else
				j++;
		}
		i++;
	}
}

void	inter(char *str, char *find)
{
	int	i;
	int j;

	i = 0;
	j = 0;
	intdup(str);
	while (str[i] != '\0')
	{
		j = 0;
		while (find[j] != '\0')
		{
			if (str[i] == find[j])
			{
				write(1, &str[i], 1);
				break ;
			}
			else
				j++;
		}
		i++;
	}
}

int		main(int argc, char **argv)
{
	if (argc == 3)
		inter(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}
