/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:03:47 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 11:03:48 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char *cs;

	cs = (unsigned char*)s;
	while (n--)
	{
		if (*cs == (unsigned char)c)
			return (cs);
		cs++;
	}
	return (NULL);
}
