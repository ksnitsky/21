#include <unistd.h>

void	first_word(char *str)
{
	while (*str)
	{
		while (*str != ' ' && *str != '\t')
		{
			write(1, str++, 1);
			if (*str == ' ' || *str == '\0' || *str == '\t')
				return ;
		}
		str++;
	}

}

int		main(int argc, char **argv)
{
	if (argc == 1 || argc > 2)
		write(1, "\n", 1);
	else
	{
		first_word(argv[1]);
		write(1, "\n", 1);
	}
	return (0);
}
