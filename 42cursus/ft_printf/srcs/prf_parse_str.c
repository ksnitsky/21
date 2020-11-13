#include "ft_printf.h"

int			prf_parse_char(int c, t_tab tab)
{
	int count;

	count = 0;
	if (tab.minus == 1)
		ft_putchar(c);
	count = prf_parse_width(tab.width, 1, 0);
	if (tab.minus == 0)
		count += ft_putchar(c);
	return (count);
}

static int	prf_finish_string(char *str, t_tab tab)
{
	int count;

	count = 0;
	if (tab.dot >= 0)
	{
		count += prf_parse_width(tab.dot, ft_strlen(str), 0);
		count += prf_parse_prec(str, tab.dot);
	}
	else
		count += prf_parse_prec(str, ft_strlen(str));
	return (count);
}

int			prf_parse_string(char *str, t_tab tab)
{
	int count;

	count = 0;
	if (!str)
		str = "(null)";
	if (tab.dot >= 0 && (size_t)tab.dot > ft_strlen(str))
		tab.dot = ft_strlen(str);
	if (tab.minus == 1)
		count += prf_finish_string(str, tab);
	if (tab.dot >= 0)
		count += prf_parse_width(tab.width, tab.dot, 0);
	else
		count += prf_parse_width(tab.width, ft_strlen(str), 0);
	if (tab.minus == 0)
		count += prf_finish_string(str, tab);
	return (count);
}
