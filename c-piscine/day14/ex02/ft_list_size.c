/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_size.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:26:45 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/30 19:26:46 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

int		ft_list_size(t_list *begin_list)
{
	int i;

	i = 0;
	while (begin_list != NULL)
	{
		begin_list = begin_list->next;
		i++;
	}
	return (i);
}
