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
	int			file;
	ssize_t		ret;
	int			i;
	char		arr[BUFF_SIZE];
	const char	pname;

	pname = argv[0][2];
	i = 1;
	if (argc == 1)
		write(2, "File name missing\n", 18);
	while (i < argc)
	{
		file = open(argv[i], O_RDONLY);
		if (errno)
		{
			ft_puterr(strerror(errno), pname, &argv[i][0]);
			errno = 0;
		}
		else
		{
			while ((ret = read(file, arr, BUFF_SIZE)) > 0)
				write(1, arr, ret);
		}
		close(file);
		i++;
	}
	return (0);
}
