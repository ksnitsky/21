#include "libft.h"
#include <stdio.h>

static size_t	
	gnl_strlen(const char *s)
{
	size_t count;

	if (!s)
		return (0);
	count = 0;
	while (s[count] != '\0')
		count++;
	return (count);
}

static void	*gnl_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest == NULL && src == NULL)
		return (dest);
	s = src;
	d = dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

static char	
	*gnl_strdup(const char *s1)
{
	size_t	len;
	void	*s2;

	len = gnl_strlen(s1) + 1;
	if (!(s2 = malloc(len)))
		return (NULL);
	return ((char*)gnl_memcpy(s2, s1, len));
}

static char	
	*gnl_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		i;

	if (!s1)
		return (str = gnl_strdup(s2));
	if (s1 && s2)
	{
		len1 = gnl_strlen(s1);
		if (!(str = (char*)malloc(sizeof(char) * (len1 + gnl_strlen(s2) + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = s2[i];
		free((char *)s1);
		return (str);
	}
	return (NULL);
}

static int
	has_return(char *str)
{
	int		i;

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

static char
	*go_next(char *file)
{
	char		*nextl;
	int			i;
	int			j;

	if (!file)
		return (0);
	i = 0;
	j = 0;
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

static char
	*get_line(char *str)
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

int
	get_next_line(int fd, char **line)
{
	static char	*file;
	char		*temp;
	int			ret;

	if (fd < 0 || BUFFER_SIZE <= 0 || !line)
		return (-1);
	ret = 1;
	if (!(temp = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (-1);
	while (!has_return(file) && ret != 0)
	{
		if ((ret = read(fd, temp, BUFFER_SIZE)) < 0)
		{
			free(temp);
			return (-1);
		}
		temp[ret] = '\0';
		file = gnl_strjoin(file, temp);
	}
	free(temp);
	*line = get_line(file);
	file = go_next(file);
	if (ret == 0)
		return (0);
	return (1);
}
