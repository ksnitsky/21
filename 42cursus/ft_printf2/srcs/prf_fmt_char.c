#include "ft_printf.h"

char	*prf_fmt_char(t_flags *flags)
{
	char	c;

	c = (char)va_arg(flags->args, int);
	flags->forced_length = 1;
	return (prf_chrtostr(c));
}
