/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 16:26:30 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/23 16:26:31 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		main(int argc, char **argv)
{
	int i;
	int j;

	j = argc - 1;
	while (j >= 1)
	{
		i = 0;
		while (argv[j][i])
		{
			ft_putchar(argv[j][i]);
			++i;
		}
		ft_putchar('\n');
		j--;
	}
	return (0);
}
