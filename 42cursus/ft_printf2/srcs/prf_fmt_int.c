#include "ft_printf.h"

char	*prf_fmt_int(t_flags *flags)
{
	int		nb;
	char	*str;

	nb = va_arg(flags->args, int);
	if (prf_fmt_empty(nb == 0, flags))
		return (ft_strnew());
	str = ft_itoa_base(nb, PRF_DEC);
	str = prf_put_pads(flags, str, nb < 0, 0);
	return (str);
}
