#include "libft.h"

char	*ft_strnew(void)
{
	char	*str;

	if (!(str = malloc(sizeof(char))))
		return (NULL);
	str[0] = '\0';
	return (str);
}
