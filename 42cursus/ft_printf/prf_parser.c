#include "ft_printf.h"

int		prf_parser(char *str)
{
	t_flags	flags;
	int		i;

	if ((i = prf_percent(str)) == -1)
		return (0);
	while (str[i] != '\0')
	{
		

		i++;
	}
	return (1);
}
