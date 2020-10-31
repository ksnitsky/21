/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <tkathrin@student.21-schoo>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/17 14:27:57 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/17 19:59:11 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int		ft_revnum(int j)
{
	int i;

	if (j < 0)
	{
		ft_putchar('-');
		j = -j;
	}
	i = 0;
	while (j != 0)
	{
		i = i * 10;
		i = i + j % 10;
		j = j / 10;
	}
	return (i);
}

void	ft_putnbr(int nb)
{
	int j;

	j = reverse(nb);
	if (j < 10)
	{
		ft_putchar(j + 48);
		exit(j);
	}
	else
	{
		while (j > 99)
		{
			ft_putchar((j % 10) + 48);
			j /= 10;
		}
		ft_putchar((j % 10) + 48);
		ft_putchar((j / 10) + 48);
	}
}
