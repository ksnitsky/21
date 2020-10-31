/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/29 23:54:00 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/30 11:36:25 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*s;
	unsigned char	*d;
	size_t			i;

	i = 0;
	d = (unsigned char *)dest;
	s = (unsigned char *)src;
	while (i < n && s[i] != (unsigned char)c)
	{
		d[i] = s[i];
		i++;
	}
	if (i == n)
		return (NULL);
	else
	{
		d[i] = s[i];
		i++;
		return (&d[i]);
	}
}
