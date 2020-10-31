#include <stdio.h>

int		ft_fibonacci(int index);
int		ft_is_prime(int nb);

int		main(void)
{
	printf("%d\n", ft_fibonacci(0));
	printf("%d\n", ft_fibonacci(1));
	printf("%d\n", ft_fibonacci(2));
	printf("%d\n", ft_fibonacci(3));
	printf("%d\n", ft_fibonacci(4));
	printf("%d\n", ft_fibonacci(5));
	printf("%d\n", ft_fibonacci(6));
	printf("%d\n", ft_fibonacci(7));
	printf("%d\n", ft_fibonacci(8));
	printf("%d\n", ft_fibonacci(9));
	printf("%d\n", ft_fibonacci(10));
	printf("%d\n", ft_fibonacci(11));
	printf("%d\n", ft_fibonacci(12));

	printf("%d\n", ft_is_prime(2147483647));
	printf("%d\n", ft_is_prime(2147483646));
	printf("%d\n", ft_is_prime(2147483643));
	printf("%d\n", ft_is_prime(1013));
	printf("%d\n", ft_is_prime(169));
	printf("%d\n", ft_is_prime(173));
	printf("%d\n", ft_is_prime(2));
	printf("%d\n", ft_is_prime(3));
	printf("%d\n", ft_is_prime(4));
	printf("%d\n", ft_is_prime(6));
	printf("%d\n", ft_is_prime(13));
}