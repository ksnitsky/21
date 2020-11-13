#include "ft_printf.h"

void	prf_putchar(t_flags *flags, char c)
{
	write(1, &c, 1);
	flags->count += 1;
}

void	prf_putstr(char *str, t_flags *flags, int length)
{
	int	index;

	if (!str || length == 0)
		return ;
	if (length == -1)
		while (*str)
			prf_putchar(flags, *str++);
	else
	{
		index = 0;
		while (index < length)
			prf_putchar(flags, str[index++]);
	}
}

int		prf_strchr(const char *str, char c)
{
	while (*str)
	{
		if (*str == c)
			return (1);
		str++;
	}
	return (0);
}

char	*prf_chrtostr(char c)
{
	char	*str;

	if (!(str = malloc(2 * sizeof(char))))
		return (NULL);
	str[0] = c;
	str[1] = '\0';
	return (str);
}

void	prf_validate_flags(t_flags *flags)
{
	if (flags->valid)
		return ;
	flags->valid = (flags->width_enabled || flags->precision_enabled
					|| flags->hex_upper);
	flags->valid = flags->valid && flags->letter != '\0';
	flags->done = flags->letter == '\0';
}
