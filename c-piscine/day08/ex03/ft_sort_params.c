/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:36:00 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/23 16:36:01 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_sort_params(int *arr)
{
	while
	z = tab[a];
		tab[a] = tab[b];
		tab[b] = z;
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	j = 1;

	while (j < argc)
	{
		i = 0;
		while (argv[j][i])
		{
			ft_sort_params(argv[j][i]);
			++i;
		}
		ft_putchar('\n');
		++j;
	}
	return (0);
}
