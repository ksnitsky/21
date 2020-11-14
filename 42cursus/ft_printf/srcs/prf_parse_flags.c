/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prf_parse_flags.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.ft>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/14 17:12:25 by tkathrin          #+#    #+#             */
/*   Updated: 2020/11/14 17:12:26 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	prf_parse_value(t_flags *flags, char *str)
{
	int		value;

	if (str[*(flags->index)] == '*')
	{
		value = va_arg(flags->args, int);
		*(flags->index) += 1;
	}
	else
	{
		value = ft_atoi(str + *(flags->index));
		*(flags->index) += ft_itoa_base_nsize(value, 10) - 1;
	}
	return (value);
}

static void	prf_parse_width(t_flags *flags, char *str)
{
	int		value;

	flags->width_enabled = 1;
	value = prf_parse_value(flags, str);
	if (value < 0)
	{
		flags->side = 1;
		value *= -1;
		flags->width_negative = 1;
		flags->width_char = ' ';
	}
	flags->width = value;
}

static void	prf_parse_precision(t_flags *flags, char *str)
{
	int		value;
	size_t	zero_skip;

	*(flags->index) += 1;
	zero_skip = 0;
	while ((str[*(flags->index) + zero_skip]) == '0')
		zero_skip++;
	flags->precision_enabled = 1;
	value = prf_parse_value(flags, str);
	if (value < 0)
	{
		value *= -1;
		flags->precision_negative = 1;
	}
	flags->precision = value;
	*(flags->index) += zero_skip;
	if (value == 0)
		flags->index -= 1;
}

static void	prf_parse_minus(t_flags *flags, char *str)
{
	char	current;

	current = str[*(flags->index)];
	if (current == '-')
	{
		flags->minus_sign_used = 1;
		flags->width_char = ' ';
		flags->side = 1;
	}
	else if (current == '0')
	{
		if (!flags->minus_sign_used)
			flags->width_char = '0';
	}
	else
	{
		if ((current = str[*(flags->index)]) != '.')
			prf_parse_width(flags, str);
		if ((current = str[*(flags->index)]) == '.')
			prf_parse_precision(flags, str);
	}
}

void		prf_parse_flags(t_flags *flags, size_t start, size_t end)
{
	size_t	length;
	char	*str;
	size_t	index;
	size_t	*old_index;

	length = end - start;
	if (!(str = malloc((length + 1) * sizeof(char))))
		return ;
	ft_memcpy(str, flags->format + start, length);
	str[length] = '\0';
	index = 0;
	old_index = flags->index;
	flags->index = &index;
	while (index < length)
	{
		prf_parse_minus(flags, str);
		index++;
	}
	flags->index = old_index;
	free(str);
	prf_validate_flags(flags);
}
