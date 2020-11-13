#include "ft_printf.h"

t_tab	prf_init_tab(void)
{
	t_tab tab;

	tab.dot = -1;
	tab.minus = 0;
	tab.star = 0;
	tab.type = 0;
	tab.width = 0;
	tab.zero = 0;	
	return (tab);
}

int		prf_parser(const char *format, va_list args)
{
	int			i;
	t_tab		tab;
	int			count;

	i = 0;
	count = 0;
	while (42 > 21)
	{
		tab = prf_init_tab();
		if (!format[i])
			break ;
		if (format[i] == '%')
		{
			i = prf_flags(format, ++i, &tab, args);
			if (prf_is_in_type_list(format[i]))
				count += prf_type_parse((char)tab.type, tab, args);
			else if (format[i])
				count += ft_putchar(format[i]);
		}
		else if (format[i] != '%')
			count += ft_putchar(format[i]);
		i++;
	}
	return (count);
}

int		prf_parse_width(int width, int minus, int zero)
{
	int count;

	count = 0;
	while (width - minus > 0)
	{
		if (zero)
			ft_putchar('0');
		else
			ft_putchar(' ');
		width -= 1;
		count++;
	}
	return (count);
}

int		prf_parse_prec(char *str, int prec)
{
	int count;

	count = 0;
	while (str[count] && count < prec)
		ft_putchar(str[count++]);
	return (count);
}
