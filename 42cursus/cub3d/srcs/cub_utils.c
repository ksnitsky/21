#include "cub3d.h"

void
	cub_initstruct(t_cub *cub3d)
{
	cub3d->height = 0;
	cub3d->width = 0;
	cub3d->no = NULL;
	cub3d->so = NULL;
	cub3d->we = NULL;
	cub3d->ea = NULL;
	cub3d->s = NULL;

	cub3d->f = 0x0;
	cub3d->c = 0x0;
}

void
	panic(char *msg)
{
	write(2, "error\n", 6);
	write(2, msg, ft_strlen(msg));
	exit(1);
}

int
	cub_issomething(char c1, char c2)
{
	if (c1 == 'R')
		return (1);
	else if (c1 == 'N' && c2 == 'O')
		return (21);
	else if (c1 == 'S' && c2 == 'O')
		return (22);
	else if (c1 == 'W' && c2 == 'E')
		return (23);
	else if (c1 == 'E' && c2 == 'A')
		return (24);
	else if (c1 == 'S' && c2 == ' ')
		return (25);
	else if (c1 == 'F' && (c2 == ' ' || c2 == '\t'))
		return (31);
	else if (c1 == 'C' && (c2 == ' ' || c2 == '\t'))
		return (32);
	else if (c1 == '1')
		return (4);
	else
		return (-1);
}

char
	*cub_strjoin(char *s1, char *s2)
{
	char	*new_str;
	int		index;
	int		len;
	
	if (!s2)
		return (NULL);
	index = -1;
	if (!s1)
	{
		if (!(new_str = malloc(sizeof(char) * (ft_strlen(s2)) + 1)))
			return (NULL);
		len = 0;
	}
	else
	{
		len = ft_strlen(s1);
		if (!(new_str = malloc(sizeof(char) * (len + ft_strlen(s2)) + 1)))
			return (NULL);
		while (s1[++index])
			new_str[index] = s1[index];
	}
	while (s2[++index])
		new_str[len++] = s2[index];
	new_str[index] = '\0';
	return (new_str);
}
