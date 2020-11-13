#include "ft_printf.h"

void	prf_parse(t_flags *flags)
{
	unsigned char	current;

	flags->index = 0;
	flags->done = 0;
	flags->forced_length = -1;
	while ((current = flags->format[flags->index]) && !flags->done)
	{
		flags->index++;
		if (current != '%')
			prf_putchar(flags, (char)current);
		else
			prf_parse_format(flags);
	}
}
