/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dxhoan <dxhoan@student.21-school.>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/05 15:30:53 by dxhoan            #+#    #+#             */
/*   Updated: 2020/10/06 23:51:03 by dxhoan           ###   ########.fr       */
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

int		main(int argc, char **argv)
{
	char	*mapname;
	int		i;

	i = 1;
	if (argc == 1)
	{
		anti25lines();
		mapname = STDIN_MAP;
		if (validator(mapname) == 0)
			get_matrix(mapname);
	}
	while (i < argc)
	{
		mapname = argv[i];
		if (validator(mapname) == 0)
			get_matrix(mapname);
		i++;
	}
	return (0);
}
