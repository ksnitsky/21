/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 17:59:13 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/22 17:59:16 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_sqrt(int nb)
{
	int i;

	i = 1;
	if (nb <= 0)
		return (0);
	while (i <= (nb / 2))
	{
		if (i * i == nb)
			return (i);
		i++;
	}
	return (0);
}
#include <stdio.h>
int		main(void)
{
	printf("%d", ft_sqrt(1610168185));
}