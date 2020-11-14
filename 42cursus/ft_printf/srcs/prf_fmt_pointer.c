#include "ft_printf.h"

char				*prf_fmt_pointer(t_flags *flags)
{
	unsigned long	ptr;
	char			*temp;
	char			*str;

	ptr = (unsigned long)va_arg(flags->args, void *);
	temp = ft_itoa_u_base(ptr, PRF_HEX_LOW);
	str = prf_put_pads(flags, temp, 0, 2);
	if (ptr == 0 && flags->precision_enabled && flags->precision == 0)
	{
		free(str);
		str = ft_strnew();
	}
	str = ft_strjoin_free("0x", str, 2);
	return (str);
}
