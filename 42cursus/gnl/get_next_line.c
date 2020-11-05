#include "get_next_line.h"

static	int	has_return(char *str)
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

static	int	get_line(char **file, char **line)
{
	char	*temp;
	int		i;

	i = 0;
	while ((*file)[i] && (*file)[i] != '\n')
		i++;
	if ((*file)[i] == '\n')
	{
		*line = ft_substr(*file, 0, i);
		temp = ft_strdup(&(*file)[i + 1]);
		free(*file);
		*file = temp;
		if ((*file)[0] == '\0')
			ft_strdel(file);
	}
	else
	{
		*line = ft_strdup(*file);
		ft_strdel(file);
	}
	return (1);
}

int					get_next_line(int fd, char **line)
{
	static char	*file[4096];
	char		buf[BUFFER_SIZE + 1];
	char		*temp;
	int			ret;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	while((ret = read(fd, buf, BUFFER_SIZE)) > 0)
	{
		buf[ret] = '\0';
		if (!file[fd])
			file[fd] = ft_strdup(buf);
		else
		{
			temp = ft_strjoin(file[fd], buf);
			free(file[fd]);
			file[fd] = temp;
		}
		if (has_return(&buf[fd]))
			break ;
	}
	if (ret < 0)
		return (-1);
	else if (ret == 0 && (!file[fd] || file[fd][0] == '\0'))
		return (0);
	return (get_line(&file[fd], line));
}
