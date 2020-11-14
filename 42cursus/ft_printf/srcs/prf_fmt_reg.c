#include "ft_printf.h"

char	*g_fmt_key = PRF_TYPES;
char	*(*g_fmts[9])(t_flags *) = {
	&prf_fmt_char,
	&prf_fmt_str,
	&prf_fmt_pointer,
	&prf_fmt_int,
	&prf_fmt_int,
	&prf_fmt_uint,
	&prf_fmt_hex,
	&prf_fmt_hex,
	&prf_fmt_percent
};

void	*prf_get_f_func(char key)
{
	size_t	index;

	index = 0;
	while (g_fmt_key[index])
	{
		if (g_fmt_key[index] == key)
			return (g_fmts[index]);
		index++;
	}
	return (NULL);
}
