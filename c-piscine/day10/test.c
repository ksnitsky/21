#include "ft.h"
#include <stdio.h>

int     main(void)
{
	ft_putchar('a');
}


#include "ft_boolean.h"

void	ft_putstr(char *str) 
{
	while (*str)
		write(1, str++, 1);
}

t_bool	ft_is_even(int nbr)
{
	return ((EVEN(nbr)) ? TRUE : FALSE);
}

int		main(int argc, char **argv)
{
	(void)argv;
	if (ft_is_even(argc - 1) == TRUE)
		ft_putstr(EVEN_MSG);
	else
		ft_putstr(ODD_MSG);
	return (SUCCESS);
}

#include "ft_abs.h"
#include <stdio.h>
int     main()
{
    long int a;
    a = ABS(-2147483648);
    printf("%ld", a);
}

#include "ft_point.h"
#include <stdio.h>
void	set_point(t_point *point)
{
	point->x = 42;
	point->y = 21;
}

int		main(void)
{
	t_point		point;

	set_point(&point);
	printf("%d %d\n", point.x, point.y);
	return (0);
}