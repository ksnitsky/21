#include <stdio.h>

# include <unistd.h>
# include <fcntl.h>
# include <errno.h>
# include <string.h>
# include <libgen.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}


int		main(int argc, char *argv[])
{
	int i;
	int ret;
	char arr[28672];
	int j;
	char *str;

	j = 0;
	i = open(argv[1], O_RDWR);
	while ((ret = read(i, &arr, 28672)) > 0)
	{
		write(1, &arr, ret);
	}
	//printf("%d", j);
	return (0);
}