/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fmt_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:10:52 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:10:53 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_fmt_char(t_flags *flags)
{
	char	c;

	c = (char)va_arg(flags->args, int);
	flags->forced_length = 1;
	return (prf_chrtostr(c));
}
