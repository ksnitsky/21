/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:03:37 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 11:03:38 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_isnegative(int *n, int *m)
{
	if (*n < 0)
	{
		*n *= -1;
		*m = 1;
	}
}

char			*ft_itoa(int n)
{
	int		temp;
	int		z;
	int		m;
	char	*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	temp = n;
	z = 2;
	m = 0;
	ft_isnegative(&n, &m);
	while (temp /= 10)
		z++;
	z = (m == 1 ? z + 1 : z);
	if (!(str = (char*)malloc(sizeof(char) * z)))
		return (NULL);
	str[--z] = '\0';
	while (z--)
	{
		str[z] = n % 10 + '0';
		n /= 10;
	}
	if (m == 1)
		str[0] = '-';
	return (str);
}
