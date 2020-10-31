/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_display_file.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/28 12:49:40 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/28 12:49:42 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

int		main(int argc, char **argv)
{
	int		file;
	ssize_t	ret;
	char	arr[BUFF_SIZE];

	file = open(argv[1], O_RDONLY);
	if (argc == 1)
		ft_putstr(NO_FILE_MSG, 2);
	else if (argc > 2)
		ft_putstr(T_MANY_MSG, 2);
	else if (file == -1)
		ft_putstr(R_ERR_MSG, 2);
	else
	{
		while ((ret = read(file, arr, BUFF_SIZE)) > 0)
			write(1, arr, ret);
		write(1, "\n", 1);
	}
	close(file);
	return (0);
}
