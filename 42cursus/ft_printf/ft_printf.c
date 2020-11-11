/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:06 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/11 09:49:43 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

/*	External functions:
*			malloc, free, write, va_start,
*			va_arg, va_copy, va_end
*/

int ft_printf(const char *format, ...)
{
	va_list		poop;
	long long	b;

	va_start(poop, format);

	b = va_arg(poop, int);
	
	printf("%05d", b);

	va_end(poop);
	
	return (0);
}


int	main()
{
	ft_printf("One", 123, "Three", "Four");
}