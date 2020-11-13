/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_free.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ecaceres <ecaceres@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/04 16:25:03 by ecaceres          #+#    #+#             */
/*   Updated: 2019/12/04 16:25:03 by ecaceres         ###   ########.fr       */
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
