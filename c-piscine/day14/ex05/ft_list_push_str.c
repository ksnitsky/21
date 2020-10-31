/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_push_str.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:35:51 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/01 20:35:54 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list *temp;
	t_list *tmp1;

	if (size == 0 || strs == NULL)
		return (0);
	tmp1 = ft_create_elem(strs[--size]);
	temp = NULL;
	temp = tmp1;
	while (size > 0)
	{
		tmp1->next = ft_create_elem(strs[--size]);
		tmp1 = tmp1->next;
	}
	return (temp);
}
