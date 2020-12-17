#include "get_next_line.h"

static int
	gnl_strlen(char *str)
{
	int		len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

static char
	*gnl_charjoin(char *str, char c)
{
	char	*new_str;
	int		index;
	int		len;
	
	if (!str)
	{
		if (!(new_str = malloc(sizeof(char) * BUFFER_SIZE + 1)))
			return (NULL);
		index = 0;
		if (c != '\n')
			new_str[index++] = c;
		new_str[index] = '\0';
		return (new_str);
	}
	if (c == '\n')
		return (str);
	len = gnl_strlen(str);
	if (!(new_str = malloc(sizeof(char) * len + 2)))
		return (NULL);
	index = -1;
	while (str[++index])
		new_str[index] = str[index];
	free(str);
	new_str[len++] = c;
	new_str[len] = '\0';
	return (new_str);
}

int
	get_next_line(char **line)
{
	char	*buff;
	char	*temp;
	int		ret;

	if (!line)
		return (-1);
	if (!(temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	ret = 1;
	buff = NULL;
	while ((ret = read(0, temp, BUFFER_SIZE)))
	{
		if (ret < 0)
		{
			free(temp);
			return (-1);
		}
		temp[ret] = '\0';
		buff = gnl_charjoin(buff, temp[0]);
		if (temp[0] == '\n')
			break ;
	}
	*line = buff;
	free(temp);
	return (ret == 0 ? 0 : 1);
}
