/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_is_lowercase.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/19 21:20:28 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/19 22:52:44 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_str_is_lowercase(char *str)
{
	if (*str == '\0')
		return (1);
	while (*str)
	{
		if (*str < 'a' || *str > 'z')
			return (0);
		else
			str++;
	}
	return (1);
}