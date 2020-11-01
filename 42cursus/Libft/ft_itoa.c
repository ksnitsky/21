/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/01 11:33:53 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/01 12:38:43 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	char	*arr;
	int		count;
	int		sign;
	int		temp;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	sign = (n < 0 ? -1 : 1);
	temp = (sign < 0 ? -n : n);
	count = (sign < 0 ? 2 : 1);
	while (temp /= 10)
		count++;
	if (!(arr = malloc(count * sizeof(char) + 1)))
		return (NULL);
	arr[count--] = '\0';
	n = (sign < 0 ? -n : n);
	while (count)
	{
		arr[count--] = n % 10 + 48;
		n /= 10;
	}
	arr[count] = (sign < 0 ? '-' : n + 48);
	return (arr);
}
