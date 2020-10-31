/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:03:23 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 11:03:24 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *s;

	if ((s = malloc(count * size)) == NULL)
		return (NULL);
	if (s)
		ft_bzero(s, count * size);
	return (s);
}
