/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:06 by lflint            #+#    #+#             */
/*   Updated: 2020/11/12 23:41:49 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

/*	External functions:
*			malloc, free, write, va_start,
*			va_arg, va_copy, va_end
*/

int		ft_printf(const char *format, ...)
{
	const char	*format_copy;
	va_list		args;
	int			count;

	format_copy = ft_strdup(format);
	count = 0;
	va_start(args, format);
	count += prf_parser(format_copy, args);
	va_end(args);
	free((char *)format_copy);
	return (count);
}
