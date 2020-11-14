/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_utils3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:13:00 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:13:01 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char		*prf_chrmult(char c, size_t times)
{
	char	*str;

	if (!(str = malloc((times + 1) * sizeof(char))))
		return (NULL);
	ft_memset(str, c, times);
	str[times] = '\0';
	return (str);
}

char		*prf_strjoin_sided(char const *s1, char const *s2, int side)
{
	if (side)
		return (ft_strjoin(s2, s1));
	return (ft_strjoin(s1, s2));
}

char		*prf_memjoin(void *s1, size_t l1, void *s2, size_t l2)
{
	char	*str;

	if (!s1 || !s2 || !(str = malloc(l1 + l2)))
		return (NULL);
	ft_memcpy(str, s1, l1);
	ft_memcpy(str + l1, s2, l2);
	return (str);
}

static int	prf_is_width_or_prec_enabled(t_flags *flags, int offset)
{
	if (flags->width_enabled && flags->precision_enabled)
	{
		if (flags->width_negative && !flags->precision_negative)
			return (flags->precision);
		else if (!flags->width_negative && flags->precision_negative)
			return (flags->width_char == '0' ? flags->width - offset : 0);
		else if (flags->width_negative && flags->precision_negative)
			return (0);
		else
		{
			if (flags->width_char == '0' && flags->precision == 0)
				return (flags->precision > flags->width ?
					ft_zero_if_neg(flags->width - offset) : flags->precision);
			else
				return (flags->precision);
		}
	}
	else if (flags->width_enabled && !flags->precision_enabled)
		return (!flags->width_negative &&
				flags->width_char == '0' ? flags->width - offset : 0);
	else if (!flags->width_enabled && flags->precision_enabled)
		return (!flags->precision_negative ? flags->precision : 0);
	return (0);
}

char		*prf_put_pads(t_flags *flags, char *abs_itoa,
								int negative, int offset)
{
	int		required;
	char	*zeros;
	char	*str;
	size_t	length;

	length = ft_strlen(abs_itoa);
	required = prf_is_width_or_prec_enabled(flags, negative + offset);
	required -= length;
	required = ft_zero_if_neg(required);
	if (negative)
		required++;
	if (!(zeros = prf_chrmult('0', required)))
		return (abs_itoa);
	str = ft_strjoin_free(zeros, abs_itoa, 3);
	if (negative)
		str[0] = '-';
	return (str);
}
