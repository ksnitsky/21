#include "ft_printf.h"

static int	prf_finish_uint(char *unsi_int, t_tab tab)
{
	int count;

	count = 0;
	if (tab.minus == 1)
		{
		if (tab.dot >= 0)
			count += prf_parse_width(tab.dot - 1, ft_strlen(unsi_int) - 1, 1);
		count += prf_parse_prec(unsi_int, ft_strlen(unsi_int));
		}
	if (tab.dot >= 0 && (size_t)tab.dot < ft_strlen(unsi_int))
		tab.dot = ft_strlen(unsi_int);
	if (tab.dot >= 0)
	{
		tab.width -= tab.dot;
		count += prf_parse_width(tab.width, 0, 0);
	}
	else
		count += prf_parse_width(tab.width,
		ft_strlen(unsi_int), tab.zero);
	if (tab.minus == 0)
	{
		if (tab.dot >= 0)
			count += prf_parse_width(tab.dot - 1, ft_strlen(unsi_int) - 1, 1);
		count += prf_parse_prec(unsi_int, ft_strlen(unsi_int));
	}
	return (count);
}

int			prf_parse_uint(unsigned int unsi, t_tab tab)
{
	char	*unsi_int;
	int		count;

	count = 0;
	if (tab.dot == 0 && unsi == 0)
	{
		count += prf_parse_width(tab.width, 0, 0);
		return (count);
	}
	unsi_int = prf_uitoa(unsi);
	count += prf_finish_uint(unsi_int, tab);
	free(unsi_int);
	return (count);
}