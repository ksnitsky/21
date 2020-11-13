#include "ft_printf.h"

int		prf_is_in_type_list(int c)
{
	return ((c == 'c') || (c == 's') || (c == 'p') || (c == 'd') || (c == 'i')
			|| (c == 'u') || (c == 'x') || (c == 'X') || (c == '%'));
}

int		prf_is_in_flags_list(int c)
{
	return ((c == '-') || (c == ' ') || (c == '0') || (c == '.') || (c == '*'));
}

int		prf_flags(const char *format, int i, t_tab *tab, va_list args)
{
	while (format[i])
	{
		if (!ft_isdigit(format[i]) && !prf_is_in_type_list(format[i])
		&& !prf_is_in_flags_list(format[i]))
			break ;
		if (format[i] == '0' && tab->width == 0 && tab->minus == 0)
		{
			printf("prf_zero\n");
			tab->zero = 1;
		}
		if (format[i] == '.')
		{
			printf("prf_flag_dot\n");
			i = prf_flag_dot(format, i, tab, args);
		}
		else if (ft_isdigit(format[i]))
		{
			printf("prf_flag_digit\n");
			*tab = prf_flag_digit(format[i], *tab);
		}
		if (format[i] == '-')
		{
			printf("prf_flag_minus\n");
			*tab = prf_flag_minus(*tab);
		}
		if (format[i] == '*')
		{
			printf("prf_flag_width\n");
			*tab = prf_flag_width(args, *tab);
		}
		if (prf_is_in_type_list(format[i]))
		{
			printf("prf_is_in_type_list\n");
			tab->type = format[i];
			break ;
		}
		i++;
	}
	return (i);
}

int		prf_type_parse(int c, t_tab tab, va_list args)
{
	int count;

	count = 0;
	if (c == 'c')
		count += prf_parse_char(va_arg(args, int), tab);
	else if (c == 's')
		count += prf_parse_string(va_arg(args, char *), tab);
	else if (c == 'p')
		count += prf_parse_pointer(va_arg(args, unsigned long long), tab);
	else if (c == 'd' || c == 'i')
		count += prf_parse_int(va_arg(args, int), tab);
	else if (c == 'u')
		count += prf_parse_uint((unsigned int)va_arg(args, unsigned int), tab);
	else if (c == 'x')
		count += prf_parse_hex(va_arg(args, unsigned int), 1, tab);
	else if (c == 'X')
		count += prf_parse_hex(va_arg(args, unsigned int), 0, tab);
	else if (c == '%')
		count += prf_parse_perc(tab);
	return (count);
}
