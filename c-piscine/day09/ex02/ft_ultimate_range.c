/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ultimate_range.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:43:00 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/24 13:43:01 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_ultimate_range(int **range, int min, int max)
{
	int *arr;
	int i;
	int n;

	if (min >= max)
	{
		*range = NULL;
		return (0);
	}
	n = (max - min) - 1;
	if ((arr = malloc(n * sizeof(int))) == NULL)
	{
		*range = NULL;
		return (-1);
	}
	i = 0;
	*range = arr;
	while (i <= n)
	{
		arr[i] = min + i;
		i++;
	}
	return (n + 1);
}
