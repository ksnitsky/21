/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 13:42:41 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/24 13:42:42 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *ptr;

	ptr = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}
