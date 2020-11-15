/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:18:53 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:18:54 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin_free(char *s1, char *s2, int policy)
{
	char	*joined;

	joined = ft_strjoin(s1, s2);
	if (policy != 0)
	{
		if (policy == 1 || policy == 3)
			free(s1);
		if (policy == 2 || policy == 3)
			free(s2);
	}
	return (joined);
}
