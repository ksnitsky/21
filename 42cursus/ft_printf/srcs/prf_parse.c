/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parse.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:12:42 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:12:43 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prf_parse(t_flags *flags)
{
	unsigned char	current;
	size_t			index;

	index = 0;
	flags->done = 0;
	while ((current = flags->format[index]) && !flags->done)
	{
		index++;
		if (current != '%')
			prf_putchar(flags, (char)current);
		else
			prf_parse_format(flags, &index);
	}
}
