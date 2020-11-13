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

size_t	ft_itoa_base_nsize(long number, size_t radix)
{
	size_t	size;

	size = (number < 0 ? 1 : 0);
	while (1)
	{
		number /= radix;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa_base(long n, char *base)
{
	long long	number;
	size_t		radix;
	char		*array;
	size_t		size;

	number = n;
	radix = ft_strlen(base);
	size = ft_itoa_base_nsize(n, radix);
	if (!(array = malloc((size + 1) * sizeof(char))))
		return (NULL);
	if (number < 0)
	{
		array[0] = '-';
		number *= -1;
	}
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = base[(number % radix)];
		number /= radix;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}

size_t	ft_itoa_u_base_nsize(unsigned long number, size_t radix)
{
	size_t	size;

	size = 0;
	while (1)
	{
		number /= radix;
		size++;
		if (number == 0)
			break ;
	}
	return (size);
}

char	*ft_itoa_u_base(unsigned long n, char *base)
{
	long long	number;
	size_t		radix;
	char		*array;
	size_t		size;

	number = n;
	radix = ft_strlen(base);
	size = ft_itoa_u_base_nsize(n, radix);
	if (!(array = malloc((size + 1) * sizeof(char))))
		return (NULL);
	array[size] = '\0';
	while (1)
	{
		array[size - 1] = base[(number % radix)];
		number /= radix;
		size--;
		if (number == 0)
			break ;
	}
	return (array);
}
