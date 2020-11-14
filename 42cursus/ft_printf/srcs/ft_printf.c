/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:10:46 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:10:47 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_flags flags;

	flags.format = format;
	flags.count = 0;
	va_start(flags.args, format);
	prf_parse(&flags);
	va_end(flags.args);
	return (flags.count);
}
