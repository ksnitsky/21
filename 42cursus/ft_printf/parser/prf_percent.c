#include "ft_printf.h"
/* looks for '%' in string of chars */
int		prf_percent(char *str, int n)
{
	while (str[n] != '\0')
	{
		if (str[n] == '%')
			return (n + 1);
		n++;
	}
	return (-1);
}
