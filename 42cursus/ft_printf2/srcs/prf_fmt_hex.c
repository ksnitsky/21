#include "ft_printf.h"

static	char	*prf_sub_fmt_hex(char *converted, t_flags *flags, int iszero)
{
	int				size;
	char			*pad;
	char			*str;

	size = 0;
	if (flags->precision_enabled && !flags->precision_negative)
		size = flags->precision - ft_strlen(converted);
	else if (!flags->side && flags->width_char == '0')
		size = flags->width - ft_strlen(converted);
	pad = prf_chrmult('0', (size < 0 ? 0 : size));
	if (!iszero)
	{
		str = ft_strjoin(flags->hex_upper ? "0X" : "0x", pad);
		free(pad);
	}
	else
		str = pad;
	return (ft_strjoin_free(str, converted, 3));
}

char			*prf_fmt_hex(t_flags *flags)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(flags->args, unsigned int);
	flags->hex_upper = flags->letter == 'X';
	if (prf_fmt_empty(nb == 0, flags))
		return (ft_strnew());
	str = ft_itoa_base(nb, (flags->hex_upper ? PRF_HEX_UP : PRF_HEX_LOW));
	str = prf_sub_fmt_hex(str, flags, nb == 0);
	str = prf_put_pads(flags, str, 0, 0);
	return (str);
}
