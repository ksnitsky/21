#include "ft_printf.h"

int			ft_printf(const char *format, ...)
{
	t_flags flags;

	flags.format = format;
	flags.count = 0;
	va_start(flags.args, format);
	prf_parse(&flags);
	va_end(flags.args);
	return (flags.count);
}
