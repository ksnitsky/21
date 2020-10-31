/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strs_to_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/26 20:05:08 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/26 20:05:10 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_stock_str.h"

int					ft_strlen(char *str)
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

char				*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char				*ft_strdup(char *src)
{
	char *ptr;

	ptr = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*arr;
	int					i;

	arr = malloc(ac * sizeof(struct s_stock_str) + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i] = (struct s_stock_str) {0, 0, 0};
	return (arr);
}
