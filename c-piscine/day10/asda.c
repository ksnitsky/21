#ifndef FT_STOCK_STR_H
# define FT_STOCK_STR_H

typedef struct s_stock_str 
{
	int 	size;
	char 	*str;
	char 	*copy;
}			t_stock_str;

#endif

#include <stdlib.h>
#include <unistd.h>

int		ft_strlen(char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		i++;
		str++;
	}
	return (i);
}


char	*ft_strcpy(char *dest, char *src)
{
	while (*src)
		*dest++ = *src++;
	*dest = '\0';
	return (dest);
}

char	*ft_strdup(char *src)
{
	char *ptr;

	ptr = malloc(ft_strlen(src) * sizeof(char) + 1);
	if (ptr == NULL)
		return (NULL);
	ft_strcpy(ptr, src);
	return (ptr);
}

struct	s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	int i;
	struct s_stock_str *arr;

	arr = malloc(ac * sizeof(struct s_stock_str) + 1);
	if (arr == NULL)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		arr[i].size = ft_strlen(av[i]);
		arr[i].str = av[i];
		arr[i].copy = ft_strdup(av[i]);
		i++;
	}
	arr[i] = (struct s_stock_str) {0, 0, 0};
	return (arr);
}

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	if (nb > 9)
	{
		ft_putnbr(nb / 10);
		ft_putnbr(nb % 10);
	}
	else
		ft_putchar(nb + 48);
}

void	ft_putstr(char *str)
{
	while (*str)
		write(1, str++, 1);
}

void	ft_show_tab(struct s_stock_str *par)
{
	int i;

	i = 0;
	while (par[i].str != '\0')
	{
		ft_putstr(par[i].str);
		ft_putchar('\n');
		ft_putnbr(par[i].size);
		ft_putchar('\n');
		ft_putstr(par[i].copy);
		ft_putchar('\n');
		i++;
	}
}

int     main(int argc, char **argv)
{
    argc = 1;
    ft_show_tab(ft_strs_to_tab(argc, argv));
}