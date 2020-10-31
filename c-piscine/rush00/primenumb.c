#include <stdio.h>

int		ft_is_prime(int nb)
{
	int i;

	i = 2;
	if (nb <= 1)
		return (0);
	while (i <= (nb / 4))
    if (nb % i == 0)
      return (0);
    else
		  i++;
	return (1);
}

int		ft_find_next_prime(int nb)
{
	int i;

	i = 0;
	while (i == 0)
	{
		if (ft_is_prime(nb))
			return (nb);
		nb++;
	}
	return (0);
}

int   main()
{
  printf("%d", ft_find_next_prime(18263));
}