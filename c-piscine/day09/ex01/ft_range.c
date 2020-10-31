/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:42:50 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/24 13:42:51 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		*ft_range(int min, int max)
{
	int *arr;
	int i;

	if (min >= max)
		return (NULL);
	i = 0;
	arr = malloc((max - min) * sizeof(int));
	while (min < max)
		arr[i++] = min++;
	return (arr);
}
