/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_zero_if_neg.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:19:56 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:21:37 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

long long int	ft_zero_if_neg(long long int number)
{
	return ((number < 0) ? 0 : number);
}

long long int	ft_abs(long long int number)
{
	return ((number < 0) ? -number : number);
}
