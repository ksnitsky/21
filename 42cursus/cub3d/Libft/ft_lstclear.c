/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:26:12 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 14:26:43 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list *temp;
	t_list *ent;

	ent = *lst;
	while (ent)
	{
		temp = ent->next;
		if (del)
			del(ent->content);
		free(ent);
		ent = temp;
	}
	*lst = NULL;
}
