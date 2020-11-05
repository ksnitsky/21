#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

int			main(int argc, char **argv)
{
	int		i;
	int		fd;
	char	*line;

	if (argc == 2)
	{
		i = 0;
		fd = open(argv[1], O_RDONLY);
		while ((get_next_line(fd, &line)) == 1)
		{
			write(1, line, ft_strlen(line));
			write(1, "\n", 1);
			free(line);
		}
		close(fd);
	}
	return (0);
}
