/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solution.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:21:28 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/07 16:21:57 by tkathrin         ###   ########.fr       */
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

void	get_matrix(char *file_name)
{
	char	*string;
	int		count;
	int		fd;
	char	temp;

	fd = open(file_name, O_RDONLY);
	while ((read(fd, &temp, 1)) && temp != '\n')
		count = 0;
	g_matrix = malloc(g_rows * sizeof(char*));
	while (count < g_rows)
	{
		string = malloc(g_cols * sizeof(char));
		read(fd, string, g_cols);
		*(g_matrix + count) = string;
		read(fd, &temp, 1);
		count++;
	}
	close(fd);
	brain_f();
}

void	brain_f(void)
{
	int j;
	int i;

	j = 0;
	g_trans = malloc(g_rows * sizeof(int*));
	while (j < g_rows)
	{
		i = g_cols - 1;
		*(g_trans + j) = malloc(g_cols * sizeof(int));
		while (i >= 0)
		{
			if (g_matrix[j][i] == g_signs[1])
				g_trans[j][i] = 0;
			else
			{
				if (i == g_cols - 1)
					g_trans[j][i] = 1;
				else
					g_trans[j][i] = g_trans[j][i + 1] + 1;
			}
			i--;
		}
		j++;
	}
	find_max();
}

int		max_size(int j, int i, int max)
{
	int min;
	int count;

	if (g_trans[j][i] > max)
	{
		count = 1;
		min = g_trans[j][i];
		j++;
		while (j < g_rows && g_trans[j][i] > count && count < min)
		{
			count++;
			min = (g_trans[j][i] < min ? g_trans[j][i] : min);
			j++;
		}
		return (count);
	}
	else
		return (0);
}

void	find_max(void)
{
	int j;
	int i;
	int current;

	j = 0;
	g_max = 0;
	while (j < g_rows)
	{
		i = 0;
		while (i < g_cols)
		{
			current = max_size(j, i, g_max);
			if (current > g_max)
			{
				g_max = current;
				g_x = i;
				g_y = j;
			}
			i++;
		}
		j++;
	}
	insert_square();
}
