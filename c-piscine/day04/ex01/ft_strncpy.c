/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 18:49:42 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/19 22:51:33 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_strlen(char *str)
{
	int j;

	j = 0;
	while (*str)
	{
		str++;
		j++;
	}
	return (j);
}

char	*ft_strncpy(char *dest, char *src, unsigned int n)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = ft_strlen(src);
	while (i < n)
	{
		if (i >= j && j < n)
		{
			*dest++ = '\0';
		}
		else
		{
			*dest++ = *src++;
		}
		i++;
	}
	return (dest);
}
