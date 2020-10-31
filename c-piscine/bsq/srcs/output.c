/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   output.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/07 16:21:15 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/07 16:21:21 by tkathrin         ###   ########.fr       */
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

void	insert_square(void)
{
	int		i;
	int		j;

	j = g_y;
	while (j < (g_y + g_max))
	{
		i = g_x;
		while (i < (g_x + g_max))
		{
			g_matrix[j][i] = g_signs[2];
			i++;
		}
		j++;
	}
	print_square();
}

void	print_square(void)
{
	int		i;
	int		j;

	j = 0;
	while (j < g_rows)
	{
		i = 0;
		while (i < g_cols)
			write(1, &g_matrix[j][i++], 1);
		j++;
		write(1, "\n", 1);
	}
	free_mem();
}

void	free_mem(void)
{
	int		j;

	j = 0;
	while (j < g_rows)
	{
		free(*(g_matrix + j));
		free(*(g_trans + j));
		j++;
	}
	free(g_matrix);
	free(g_trans);
}

void	anti25lines(void)
{
	int		counter;
	char	*buffer;
	int		fd;

	buffer = NULL;
	fd = open(STDIN_MAP, O_RDWR | O_TRUNC | O_CREAT, 0777);
	if (fd == -1)
		fd = open(STDIN_MAP, O_RDWR);
	while ((counter = read(0, &buffer, 1)))
		write(fd, &buffer, 1);
	close(fd);
	write(1, "\n", 1);
}
