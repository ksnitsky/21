/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tail.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 14:26:34 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/29 14:26:36 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		ft_tail(int argc, char *argv[])
{
	int		file;
	ssize_t	ret;
	int		i;
	char	*arr;
	char	*fname;
	int		buff;

	buff = *argv[2];
	arr = malloc(buff);
	i = 0;
	while (++i <= argc)
	{
		fname = argv[i];
		file = open(fname, O_RDWR);
		if (errno)
			ft_puterr(strerror(errno), basename(*argv), &argv[i][0]);
		while ((ret = read(file, &arr, BUFF_SIZE)) > 0)
			write(1, &arr, ret);
		close(file);
	}
	return (0);
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
