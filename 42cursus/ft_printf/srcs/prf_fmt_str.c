#include "ft_printf.h"

char	*prf_fmt_str(t_flags *flags)
{
	char	*str;

	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	if (flags->precision_enabled && !flags->precision_negative)
		return (ft_substr(str, 0, flags->precision));
	return (ft_strdup(str));
}
