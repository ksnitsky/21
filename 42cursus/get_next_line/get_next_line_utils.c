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

char	*get_line(char *str)
{
	char	*line;
	int		i;

	i = 0;
	if (!str)
		return (0);
	while (str[i] && str[i] != '\n')
		i++;
	if (!(line = malloc(sizeof(char) * i + 1)))
		return (0);
	i = 0;
	while (str[i] && str[i] != '\n')
	{
		line[i] = str[i];
		i++;
	}
	line[i] = '\0';
	return (line);
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

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		len1;
	char	*str;
	int		i;

	if (!s1)
		return (str = ft_strdup(s2));
	if (!s1 && !s2)
		return (0);
	len1 = ft_strlen((char*)s1);
	if (!(str = malloc(sizeof(char) * (len1 + ft_strlen(s2) + 1))))
		return (NULL);
	i = 0;
	while (s1[i++])
		str[i] = s1[i];
	i = 0;
	while (s2[i++])
	{
		str[len1] = s2[i];
		len1++;
	}
	str[len1] = s2[i];
	free((char*)s1);
	return (str);
}



void		*ft_memmove(void *dst, const void *src, size_t len)
{
	char *d;
	char *s;

	d = (char *)dst;
	s = (char *)src;
	if (dst == src)
		return (dst);
	if (s < d)
	{
		while (len--)
			*(d + len) = *(s + len);
		return (dst);
	}
	while (len--)
		*d++ = *s++;
	return (dst);
}

char		*join_str(char const *s1, char const *s2)
{
	size_t	s1_len;
	size_t	s2_len;
	size_t	stot_len;
	char	*rtn;

	if (!s1 && !s2)
		return (0);
	s1_len = ft_strlen((char *)s1);
	s2_len = ft_strlen((char *)s2);
	stot_len = s1_len + s2_len + 1;
	rtn = malloc(sizeof(char) * stot_len);
	if (!rtn)
		return (0);
	ft_memmove(rtn, s1, s1_len);
	ft_memmove(rtn + s1_len, s2, s2_len);
	rtn[stot_len - 1] = '\0';
	free((char *)s1);
	return (rtn);
}
