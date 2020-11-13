#include "ft_printf.h"

int		main()
{
	int i = 0;
	int j = 0;
	i = ft_printf("oure :%0d\n", -2147483648);
	j = printf("orig :%0d\n", -2147483648);
	printf("\nOur: %d, Orig: %d\n", i, j);
	return (0);
}


/*
#include "ft_printf.h"

static int	prf_finish_int_minus(char *str_i, int i, t_tab tab)
{
	int count;

	count = 0;
	if (i < 0 && tab.dot >= 0)
		ft_putchar('-');
	if (tab.dot >= 0)
		count += prf_parse_width(tab.dot - 1, ft_strlen(str_i) - 1, 1);
	count += prf_parse_prec(str_i, ft_strlen(str_i));
	return (count);
}

static int	prf_finish_int(char *str_i, int i, t_tab tab)
{
	int count;
	
	count = 0;
	if (tab.minus == 1)
		count += prf_finish_int_minus(str_i, i, tab);
	if (tab.dot >= 0 && (size_t)tab.dot < ft_strlen(str_i))
		tab.dot = ft_strlen(str_i);
	if (tab.dot >= 0)
	{
		tab.width -= tab.dot;
		count += prf_parse_width(tab.width, 0, 0);
	}
	else
		count += prf_parse_width(tab.width, ft_strlen(str_i), tab.zero);
	if (tab.minus == 0)
		count += prf_finish_int_minus(str_i, i, tab);
	return (count);
}

int			prf_parse_int(int i, t_tab tab)
{
	char	*str_i;
	int		temp;
	int		count;
	
	if (tab.dot == 0 && i == 0)
		return (prf_parse_width(tab.width, 0, 0));
	count = 0;
	temp = i;
	if (i < 0 && (tab.dot >= 0 || tab.zero == 1))
	{
		if (tab.zero == 1 && tab.dot == -1)
			prf_parse_prec("-", 1);
		i *= -1;
		tab.zero = 1;
		tab.width--;
		count++;
	}
	str_i = ft_itoa(i);
	count += prf_finish_int(str_i, temp, tab);
	free(str_i);
	return (count);
}

int		prf_parse_perc(t_tab tab)
{	
	int count;

	count = 0;
	if (tab.minus == 1)
		count += prf_parse_prec("%", 1);
	count += prf_parse_width(tab.width, 1, tab.zero);
	if (tab.minus == 0)
		count += prf_parse_prec("%", 1);
	return (count);
}
*/