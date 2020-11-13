#include "ft_printf.h"

t_tab		prf_flag_minus(t_tab tab)
{
	tab.minus = 1;
	tab.zero = 0;
	return (tab);
}

t_tab		prf_flag_digit(char c, t_tab tab)
{
	
	if (tab.star == 1)
		tab.width = 0;
	tab.width = (tab.width * 10) + (c - '0');
	return (tab);
}

t_tab		prf_flag_width(va_list args, t_tab tab)
{
	tab.star = 1;
	tab.width = va_arg(args, int);
	if (tab.width < 0)
	{
		tab.minus = 1;
		tab.width *= -1;
	}
	return (tab);
}

int			prf_flag_dot(const char *format, int i,
			t_tab *tab, va_list args)
{
	if (format[++i] == '*')
	{
		tab->dot = va_arg(args, int);
		i++;
	}
	else
	{
		tab->dot = 0;
		while (ft_isdigit(format[i]))
			tab->dot = (tab->dot * 10) + (format[i++] - '0');
	}
	return (i);
}
