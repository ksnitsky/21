#include <stdlib.h>
#include <stdio.h>

char	*ft_itoa(int n)
{
	static int	count;
	static char	*str = NULL;

	if (n > 9)
		ft_itoa(n / 10);
	if (count == 0)
		str = malloc(10);
	str[count++] = (n % 10 + 48);
	return (str);
}

int main()
{
    printf("%s", ft_itoa(438123721));
}