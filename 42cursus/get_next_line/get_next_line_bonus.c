/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/07 12:50:32 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/07 16:59:55 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int		has_return(char *str)
{
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

static char		*go_next(char *file)
{
	char		*nextl;
	int			i;
	int			j;

	i = 0;
	j = 0;
	if (!file)
		return (0);
	while (file[i] && file[i] != '\n')
		i++;
	if (!file[i])
	{
		free(file);
		return (0);
	}
	if (!(nextl = malloc(sizeof(char) * (ft_strlen(file) - i) + 1)))
		return (0);
	i++;
	while (file[i])
		nextl[j++] = file[i++];
	nextl[j] = '\0';
	free(file);
	return (nextl);
}

static char		*get_line(char *str)
{
	char		*line;
	int			i;

	if (!str)
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

int				get_next_line(int fd, char **line)
{
	static char	*file[OPEN_MAX];
	char		*temp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	ret = 1;
	if (!(temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (!has_return(file[fd]) && ret != 0)
	{
		if ((ret = read(fd, temp, BUFFER_SIZE)) < 0)
		{
			free(temp);
			return (-1);
		}
		temp[ret] = '\0';
		file[fd] = ft_strjoin(file[fd], temp);
	}
	free(temp);
	*line = get_line(file[fd]);
	file[fd] = go_next(file[fd]);
	if (ret == 0)
		return (0);
	return (1);
}
