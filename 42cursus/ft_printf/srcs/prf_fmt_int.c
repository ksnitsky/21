/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fmt_int.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:11:02 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:11:03 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_fmt_int(t_flags *flags)
{
	int		nb;
	char	*str;

	nb = va_arg(flags->args, int);
	if (prf_fmt_empty(nb == 0, flags))
		return (ft_strnew());
	str = ft_itoa_base(ft_abs(nb), PRF_DEC);
	str = prf_put_pads(flags, str, nb < 0, 0);
	return (str);
}
