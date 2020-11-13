#include "ft_printf.h"

static int	prf_finish_pointer(char *pointer, t_tab tab)
{
	int char_count;

	char_count = 0;
	char_count += prf_parse_prec("0x", 2);
	if (tab.dot >= 0)
	{
		char_count += prf_parse_width(tab.dot, ft_strlen(pointer), 1);
		char_count += prf_parse_prec(pointer, tab.dot);
	}
	else
		char_count += prf_parse_prec(pointer, ft_strlen(pointer));
	return (char_count);
}

int			prf_parse_pointer(unsigned long long ull, t_tab tab)
{
	char	*pointer;
	int		char_count;

	char_count = 0;
	if (ull == 0 && tab.dot == 0)
	{
		char_count += prf_parse_prec("0x", 2);
		return (char_count += prf_parse_width(tab.width, 0, 1));
	}
	pointer = ft_ull_base(ull, 16);
	pointer = prf_str_tolower(pointer);
	if ((size_t)tab.dot < ft_strlen(pointer))
		tab.dot = ft_strlen(pointer);
	if (tab.minus == 1)
		char_count += prf_finish_pointer(pointer, tab);
	char_count += prf_parse_width(tab.width, ft_strlen(pointer) + 2, 0);
	if (tab.minus == 0)
		char_count += prf_finish_pointer(pointer, tab);
	free(pointer);
	return (char_count);
}
