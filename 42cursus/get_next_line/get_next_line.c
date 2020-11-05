#include "get_next_line.h"
#include <stdio.h>

static	char	*get_save(char *save)
{
	char	*rtn;
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (!save)
		return (0);
	while (save[i] && save[i] != '\n')
		i++;
	if (!save[i])
	{
		free(save);
		return (0);
	}
	if (!(rtn = malloc(sizeof(char) * ((ft_strlen(save) - i) + 1))))
		return (0);
	i++;
	while (save[i])
		rtn[j++] = save[i++];
	rtn[j] = '\0';
	free(save);
	return (rtn);
}

static	int		has_return(char *str)
{
	int i;

	i = 0;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int				get_next_line(int fd, char **line)
{
	static	char	*file;
	char			*temp;
	int				reader;

	reader = 1;
	if (!line || BUFFER_SIZE <= 0 || fd < 0)
		return (-1);
	if (!(temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (!has_return(file) && reader != 0)
	{
		if ((reader = read(fd, temp, BUFFER_SIZE)) < 0)
		{
			free(temp);
			return (-1);
		}
		temp[reader] = '\0';
		file = join_str(file, temp);
	}
	free(temp);
	*line = get_line(file);
	file = get_save(file);
	if (reader == 0)
		return (0);
	return (1);
}
