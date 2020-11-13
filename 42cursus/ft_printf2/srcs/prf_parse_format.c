#include "ft_printf.h"

void		prf_parse_format(t_flags *flags)
{
	size_t	start;
	void	*f_func;

	prf_init_flags(flags);
	start = flags->index;
	while ((flags->letter = flags->format[flags->index]))
	{
		f_func = prf_get_f_func(flags->letter);
		if (f_func != NULL || !prf_is_flag(flags->letter))
			break ;
		flags->index += 1;
	}
	if (start != flags->index)
		prf_parse_flags(flags, start, flags->index);
	prf_process_format(flags, f_func);
}

void		prf_process_format(t_flags *flags, char *(*f_func)(t_flags *))
{
	char	*str;

	if (f_func == NULL)
		f_func = &prf_empty_func;
	flags->index += 1;
	str = (*(f_func))(flags);
	str = prf_flag_handle(flags, str);
	prf_putstr(str, flags, flags->forced_length);
	free(str);
}

char		*prf_handle_width(t_flags *flags, char *formatted)
{
	size_t	length;
	int		required;
	char	*padding;
	char	*str;
	char	letter;

	letter = ft_tolower(flags->letter);
	if ((flags->precision_enabled || flags->precision_negative)
			&& !prf_strchr("s%", letter) && ((letter != 'x' && letter != 'o')
			|| flags->precision < flags->width))
	{
		flags->width_char = ' ';
	}
	length = ft_strlen(formatted);
	required = flags->width - length;
	if (required < 0)
		return (formatted);
	padding = prf_chrmult(flags->width_char, required);
	if (!padding)
		return (formatted);
	str = prf_strjoin_sided(padding, formatted, flags->side);
	flags->forced_length = required + length;
	free(padding);
	return (str);
}

char		*prf_handle_width_m(t_flags *flags, char *formatted)
{
	size_t	length;
	int		required;
	char	*padding;
	char	*str;

	if (flags->precision_enabled
			&& flags->precision != 0 && flags->letter != 'c')
		flags->width_char = ' ';
	length = flags->forced_length;
	required = flags->width - length;
	if (required < 0)
		return (formatted);
	padding = prf_chrmult(flags->width_char, required);
	if (!padding)
		return (formatted);
	if (flags->side)
		str = prf_memjoin(formatted, length, padding, required);
	else
		str = prf_memjoin(padding, required, formatted, length);
	flags->forced_length = required + length;
	free(padding);
	return (str);
}

char		*prf_flag_handle(t_flags *flags, char *formatted)
{
	char	*str;

	if (!flags->valid)
		return (formatted);
	str = formatted;
	if (flags->width_enabled)
	{
		if (flags->forced_length == -1)
			str = prf_handle_width(flags, str);
		else
			str = prf_handle_width_m(flags, str);
	}
	if (str != formatted)
		free(formatted);
	return (str);
}
