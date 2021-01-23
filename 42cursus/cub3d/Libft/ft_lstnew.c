/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 14:25:51 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 14:27:03 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list *temp;

	if (!(temp = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	temp->next = NULL;
	temp->content = content;
	return (temp);
}
