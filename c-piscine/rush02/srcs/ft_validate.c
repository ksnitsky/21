/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/03 13:42:47 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/03 13:42:47 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_rush.h"

int		ft_validate(char *str)
{
	if (*str == '\0')
		return (0);
	else if (*str == '-')
		return (0);
	else if (str[0] < '0' || str[0] > '9')
		return (0);
	else if (str[0] == '0' && ft_strlen(str) > 1)
		return (0);
	else
		return (1);
}
