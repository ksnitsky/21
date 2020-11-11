#include "ft_printf.h"

int		prf_parser(t_tab *tab)
{
	if ((tab->index = prf_percent(tab->format, tab->index)) == -1)
		return (0);
	if (!(prf_flags(tab->format[tab->index])))
		return (tab->index);
	 
}
