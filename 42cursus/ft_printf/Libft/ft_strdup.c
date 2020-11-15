/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:04:48 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/01 13:23:42 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*s2;

	len = ft_strlen(s1) + 1;
	if (!(s2 = malloc(len)))
		return (NULL);
	return ((char*)ft_memcpy(s2, s1, len));
}
