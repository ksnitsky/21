/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:26:34 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/29 14:26:36 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_cat(int argc, char *argv[])
{
	int		file;
	ssize_t	ret;
	int		i;
	char	arr[BUFF_SIZE];

	i = 0;
	while (++i <= argc)
	{
		if ((file = open(argv[i], O_RDWR)) < 0 && errno)
			ft_puterr(strerror(errno), basename(*argv), &argv[i][0]);
		while ((ret = read(file, &arr, BUFF_SIZE)) > 0)
			write(1, &arr, ret);
		close(file);
	}
}

void	ft_dog(void)
{
	ssize_t	ret;
	char	arr;

	while (1)
	{
		ret = read(2, &arr, 1);
		write(1, &arr, ret);
	}
}
