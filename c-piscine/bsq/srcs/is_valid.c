/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxhoan <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/06 16:21:43 by dxhoan            #+#    #+#             */
/*   Updated: 2020/10/07 16:21:50 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

int		g_cols;
int		g_rows;
char	g_signs[3];
char	**g_matrix;
int		**g_trans;
int		g_x;
int		g_y;
int		g_max;

int		is_valid(int fd, int line_count, char *empt, char *obst)
{
	char	temp;
	int		long_count;
	int		count;

	count = 0;
	long_count = 0;
	while (read(fd, &temp, 1))
	{
		if (temp != *empt && temp != *obst && temp != '\n')
			return (-4);
		if (temp != '\n')
			count++;
		else
		{
			line_count--;
			if (long_count == 0)
				long_count = count;
			else if (long_count != count)
				return (-3);
			count = 0;
		}
	}
	return (line_count == 0 ? long_count : -2);
}

int		take_first(int fd, char *empt, char *obst, char *full)
{
	char	temp;
	int		count;
	int		result;

	result = 0;
	count = 0;
	while ((read(fd, &temp, 1)) && temp != '\n')
	{
		if (count++ > 2)
		{
			if (*empt >= '0' && *empt <= '9')
				result = (result * 10) + *empt - '0';
			else
				return (-20);
		}
		*empt = *obst;
		*obst = *full;
		*full = temp;
	}
	if (count < 3 || diff_printable_signs(empt, obst, full) != 1)
		return (-10);
	else
		return (result);
}

int		diff_printable_signs(char *empt, char *obst, char *full)
{
	if (*empt == *obst)
		return (-1);
	if (*empt == *full)
		return (-1);
	if (*obst == *full)
		return (-1);
	if (*empt < ' ' || *empt > '~')
		return (-1);
	if (*obst < ' ' || *obst > '~')
		return (-1);
	if (*full < ' ' || *full > '~')
		return (-1);
	return (1);
}

int		validator(char *mapname)
{
	int		fd;

	if ((fd = open(mapname, O_RDONLY)) == -1)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	g_rows = take_first(fd, g_signs, g_signs + 1, g_signs + 2);
	g_cols = is_valid(fd, g_rows, g_signs, g_signs + 1);
	close(fd);
	if (g_cols < 1 || g_rows < 1)
	{
		write(2, "map error\n", 10);
		return (-1);
	}
	else
		return (0);
}
