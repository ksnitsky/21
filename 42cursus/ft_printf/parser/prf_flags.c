#include "ft_printf.h"

int		prf_flags(t_tab *tab)
{
	while (tab->format[tab->index])
	{
		if (!(is_flag_valid(&tab->format[tab->index], tab))
			return (-1);
		//else if (tab->format[tab->index] == '%')
			
	}

	return (0);
}

int		is_flag_valid(char *str, t_tab *tab)
{
	int i;
	
	i = 0;
	while (str[i])
	{
		if (str[i] == '-')
			tab->minus = 1;
		else if (str[i] == '')

	}
}



//%*.*d 1, 2, 3 = valid
//%5.*d 1, 2, 3 = invalid