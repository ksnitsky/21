#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t count;

	count = 0;
	if (!s)
		return (0);
	while (s[count] != '\0')
		count++;
	return (count);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!(str = (char *)malloc(sizeof(*s) * (len + 1))) || !s)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		if (j < len && i >= start)
		{
			str[j] = s[i];
			j++;
		}
		i++;
	}
	str[j] = '\0';
	return (str);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	int		len1;
	int		i;

	if (s1 && s2)
	{
		len1 = ft_strlen(s1);
		if (!(str = (char*)malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1))))
			return (NULL);
		i = -1;
		while (s1[++i])
			str[i] = s1[i];
		i = -1;
		while (s2[++i])
		{
			str[len1] = s2[i];
			len1++;
		}
		str[len1] = s2[i];
		return (str);
	}
	return (NULL);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;

	if (dest == NULL && src == NULL)
		return (dest);
	s = src;
	d = dest;
	while (n--)
		*d++ = *s++;
	return (dest);
}

char	*ft_strdup(const char *s1)
{
	size_t	len;
	void	*s2;

	len = ft_strlen(s1) + 1;
	if (!(s2 = malloc(len)))
		return (NULL);
	return ((char*)ft_memcpy(s2, s1, len));
}

void	ft_strdel(char **as)
{
	if (as)
	{
		free(*as);
		*as = NULL;
	}
	return ;
}
