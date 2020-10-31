/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_iterative_power.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 14:46:01 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/22 14:46:02 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_iterative_power(int nb, int power)
{
	int i;
	int j;

	if (power == 0)
		return (1);
	else if (power < 0)
		return (0);
	i = 1;
	j = nb;
	while (i < power)
	{
		j *= nb;
		i++;
	}
	return (j);
}
