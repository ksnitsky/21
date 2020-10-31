/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_list_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 20:36:30 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/01 20:36:31 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_list.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list *curr;
	t_list *next;

	curr = begin_list;
	while (curr != NULL)
	{
		next = curr->next;
		free_fct(curr->data);
		free(curr->next);
		curr = next;
	}
	begin_list = NULL;
}
