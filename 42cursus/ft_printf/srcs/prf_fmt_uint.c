/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_fmt_uint.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:12:21 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:12:22 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*prf_fmt_uint(t_flags *flags)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(flags->args, unsigned int);
	if (prf_fmt_empty(nb == 0, flags))
		return (ft_strnew());
	str = ft_itoa_u_base(nb, PRF_DEC);
	if (str && flags->precision_enabled)
		return (prf_put_pads(flags, str, 0, 0));
	return (str);
}
