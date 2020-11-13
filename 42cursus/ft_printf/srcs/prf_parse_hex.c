#include "ft_printf.h"

static int		prf_parse_hex_minus(char *hex, t_tab tab)
{
	int count;

	count = 0;
	if (tab.dot >= 0)
		count += prf_parse_width(tab.dot - 1, ft_strlen(hex) - 1, 1);
	count += prf_parse_prec(hex, ft_strlen(hex));
	return (count);
}

static int		prf_finish_hex(char *hex, t_tab tab)
{
	int count;

	count = 0;
	if (tab.minus == 1)
		count += prf_parse_hex_minus(hex, tab);
	if (tab.dot >= 0 && (size_t)tab.dot < ft_strlen(hex))
		tab.dot = ft_strlen(hex);
	if (tab.dot >= 0)
	{
		tab.width -= tab.dot;
		count += prf_parse_width(tab.width, 0, 0);
	}
	else
		count += prf_parse_width(tab.width,
		ft_strlen(hex), tab.zero);
	if (tab.minus == 0)
		count += prf_parse_hex_minus(hex, tab);
	return (count);
}

int				prf_parse_hex(unsigned int ui, int lower, t_tab tab)
{
	char	*hex;
	int		count;

	count = 0;
	ui = (unsigned int)(4294967295 + 1 + ui);
	if (tab.dot == 0 && ui == 0)
	{
		count += prf_parse_width(tab.width, 0, 0);
		return (count);
	}
	hex = ft_ull_base((unsigned long long)ui, 16);
	if (lower == 1)
		hex = prf_str_tolower(hex);
	count += prf_finish_hex(hex, tab);
	free(hex);
	return (count);
}
