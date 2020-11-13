#include "ft_printf.h"

char	*prf_fmt_percent(t_flags *flags)
{
	(void)flags;
	return (prf_chrtostr('%'));
}
