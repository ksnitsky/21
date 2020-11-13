#include "ft_printf.h"

static char	*treat_base(unsigned long long ull_save, int base,
char *rtn, int count)
{
	while (ull_save != 0)
	{
		if ((ull_save % base) < 10)
			rtn[count - 1] = (ull_save % base) + 48;
		else
			rtn[count - 1] = (ull_save % base) + 55;
		ull_save /= base;
		count--;
	}
	return (rtn);
}

char		*ft_ull_base(unsigned long long ull, int base)
{
	char				*rtn;
	unsigned long long	ull_save;
	int					count;

	rtn = 0;
	count = 0;
	ull_save = ull;
	if (ull == 0)
		return (ft_strdup("0"));
	while (ull != 0)
	{
		ull /= base;
		count++;
	}
	if (!(rtn = malloc(sizeof(char) * (count + 1))))
		return (0);
	rtn[count] = '\0';
	rtn = treat_base(ull_save, base, rtn, count);
	return (rtn);
}

char		*prf_str_tolower(char *str)
{
	int i;

	i = -1;
	while (str[++i])
		str[i] = ft_tolower(str[i]);
	return (str);
}

char		*prf_uitoa(unsigned int n)
{
	char			*arr;
	int				count;
	int				sign;
	long			temp;

	temp = n;
	sign = (temp < 0 ? -1 : 1);
	count = (sign < 0 ? 2 : 1);
	while (temp /= 10)
		count++;
	if (!(arr = malloc(count * sizeof(char) + 1)))
		return (NULL);
	arr[count--] = '\0';
	n = (sign < 0 ? -n : n);
	while (count)
	{
		arr[count--] = n % 10 + 48;
		n /= 10;
	}
	arr[count] = (sign < 0 ? '-' : n + 48);
	return (arr);
}
