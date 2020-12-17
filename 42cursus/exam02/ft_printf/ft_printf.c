#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

#define DEC_BASE "0123456789"
#define HEX_BASE "0123456789abcdef"

typedef struct		s_flags
{
	const char		*format;
	va_list			args;
	int				width;
	int				prec;
	int				count;
	int				dot;
	int				done;
}					t_flags;

void
	prf_initstruct(t_flags *flags)
{
	flags->width = 0;
	flags->prec = 0;
	flags->dot = 0;
	flags->done = 0;
}

void
	prf_putchar(t_flags *flags, char c)
{
	write(1, &c, 1);
	flags->count += 1;
}

int
	prf_isdigit(char c)
{
	return (c >= 48 && c <= 57);
}

int
	prf_istype(char c)
{
	return (c == 's' || c == 'd' || c == 'x');
}

long long
	prf_abs(long long nb)
{
	return (nb < 0 ? -nb : nb);
}

int
	prf_strlen(char *str)
{
	int				len;

	if (!str)
		return (0);
	len = 0;
	while (str[len])
		len++;
	return (len);
}

int
	prf_intlen(unsigned int nb, int base)
{
	int				len;

	if (nb == 0)
		return (1);
	len = 0;
	while (nb)
	{
		nb /= base;
		len++;
	}
	return (len);
}

char
	*prf_itoa_base(unsigned int nb, char *base)
{
	unsigned int	nubmer;
	char			*itoed;
	int				radix;
	int				size;

	nubmer = nb;
	radix = prf_strlen(base);
	size = prf_intlen(nubmer, radix);
	if (!(itoed = malloc(sizeof(char) * (size + 1))))
		return (NULL);
	itoed[size] = '\0';
	while (1)
	{
		itoed[size - 1] = base[(nubmer % radix)];
		nubmer /= radix;
		size--;
		if (nubmer == 0)
			break ;
	}
	return (itoed);
}

void
	prf_putpoops(t_flags *flags, char *str, int minus)
{
	int				len;
	int				poops;
	int				zeroes;

	len = minus + prf_strlen(str);
	zeroes = flags->prec > len ? flags->prec - len : 0;
	poops = flags->width > (len + zeroes) ? flags->width - (len + zeroes) : 0;
	while (*str)
	{
		while (poops-- > 0)
			prf_putchar(flags, ' ');
		if (minus)
		{
			prf_putchar(flags, '-');
			minus = 0;
		}
		while (zeroes-- > 0)
			prf_putchar(flags, '0');
		prf_putchar(flags, *(str++));
	}
	flags->done = 1;
}

void
	prf_fmt_str(t_flags *flags)
{
	char			*str;
	int				len;
	int				poops;

	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	if(!flags->prec)
		len = prf_strlen(str);
	else
		len = flags->prec > prf_strlen(str) ? prf_strlen(str) : flags->prec;
	poops = flags->width > len ? flags->width - len : 0;
	while (len--)
	{
		while (poops-- > 0)
			prf_putchar(flags, ' ');
		prf_putchar(flags, *(str++));
	}
	flags->done = 1;
}

void
	prf_fmt_dec(t_flags *flags)
{
	int				nb;
	char			*str;

	nb = va_arg(flags->args, int);
	str = prf_itoa_base(prf_abs(nb), DEC_BASE);
	prf_putpoops(flags, str, nb < 0);
	free(str);
}

void
	prf_fmt_hex(t_flags *flags)
{
	unsigned int	nb;
	char			*str;

	nb = va_arg(flags->args, unsigned int);
	str = prf_itoa_base(prf_abs(nb), HEX_BASE);
	prf_putpoops(flags, str, 0);
	free(str);
}

void
	prf_parse(t_flags *flags, size_t *index)
{
	unsigned char	poop;

	prf_initstruct(flags);
	while ((poop = flags->format[*index]) && !flags->done)
	{
		if (prf_isdigit(poop))
			flags->dot == 0 ? (flags->width = (flags->width * 10) + (poop - 48)) \
							: (flags->prec = (flags->prec * 10) + (poop - 48));
		else if (poop == '.')
			flags->dot = 1;
		else if (prf_istype(poop))
		{
			if (poop == 's')
				prf_fmt_str(flags);
			else if (poop == 'd')
				prf_fmt_dec(flags);
			else
				prf_fmt_hex(flags);
		}
		else
			break ;
		*index += 1;
	}
}

int
	ft_printf(const char *format, ...)
{
	unsigned char	current;
	t_flags			flags;
	size_t			index;

	flags.format = format;
	flags.count = 0;
	index = 0;
	va_start(flags.args, format);
	while ((current = flags.format[index]))
	{
		index++;
		if (current != '%')
			prf_putchar(&flags, current);
		else
			prf_parse(&flags, &index);
	}
	va_end(flags.args);
	return (flags.count);
}
