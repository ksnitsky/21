/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_elem.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/30 19:25:43 by tkathrin          #+#    #+#             */
/*   Updated: 2020/09/30 19:25:45 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

t_list	*ft_create_elem(void *data)
{
	t_list *temp;

	temp = (t_list*)malloc(sizeof(t_list));
	temp->next = NULL;
	temp->data = data;
	return (temp);
}

#include <stdio.h>
int		main()
{
	t_list* temp;

	temp = ft_create_elem("klad");
	
	printf(" %s", temp->data);
	printf(" %p", temp->next);
	temp->next = ft_create_elem("oqw");
	printf(" %s", (*temp).next->data);
	printf(" %p", temp->next);
}