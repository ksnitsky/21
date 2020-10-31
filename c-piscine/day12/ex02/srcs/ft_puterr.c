/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puterr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 15:55:07 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/21 15:55:10 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft.h"

void	ft_puterr(char *str, char *pname, char *fname)
{
	write(2, pname, ft_strlen(pname));
	write(2, ": ", 2);
	write(2, fname, ft_strlen(fname));
	write(2, ": ", 2);
	write(2, str, ft_strlen(str));
	write(2, "\n", 1);
}

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
