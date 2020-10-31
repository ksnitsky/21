/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_map.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/29 20:02:32 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/29 20:02:33 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_map(int *tab, int length, int (*f)(int))
{
	int i;
	int *arr;

	if ((arr = malloc(length * sizeof(int))) == NULL)
		return (NULL);
	i = 0;
	while (i <= length)
	{
		arr[i] = f(tab[i]);
		i++;
	}
	return (arr);
}
