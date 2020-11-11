/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lflint <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/09 19:06:06 by lflint            #+#    #+#             */
/*   Updated: 2020/11/11 19:41:11 by lflint           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>
#include <stdlib.h>

/*	External functions:
*			malloc, free, write, va_start,
*			va_arg, va_copy, va_end
*/

int	ft_printf(const char *format, ...)
{
	t_tab		*tab;

	if (!(tab = malloc(sizeof(t_tab))))
		return (-1);
	tab->format = format;
	
	if (!(prf_parser(tab)))
		prf_print(tab->format);

	va_start(tab->args, format);
	
	printf("%s\n", tab->format);

	va_end(tab->args);
	
	return (0);
}


int	main()
{
	ft_printf("One", 123, "Three", "Four");
}
