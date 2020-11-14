/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_utils2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:12:55 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:12:56 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	prf_init_flags(t_flags *flags)
{
	flags->letter = '\0';
	flags->valid = 0;
	flags->minus_sign_used = 0;
	flags->side = 0;
	flags->width_char = ' ';
	flags->width_enabled = 0;
	flags->width = 0;
	flags->width_negative = 0;
	flags->precision_enabled = 0;
	flags->precision = 0;
	flags->precision_negative = 0;
	flags->hex_upper = 0;
}

char	*prf_empty_func(t_flags *flags)
{
	if (flags->precision_enabled)
		flags->precision_enabled = 0;
	if (flags->letter == '\0')
		return (ft_strnew());
	flags->forced_length = 1;
	return (prf_chrtostr(flags->letter));
}

int		prf_is_flag(char c)
{
	return ((ft_isdigit(c) || prf_strchr("-.*0", c)) ? 1 : 0);
}

int		prf_fmt_empty(int iszero, t_flags *flags)
{
	return (iszero && flags->precision_enabled && flags->precision == 0);
}
