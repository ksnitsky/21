/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkathrin <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/31 11:04:34 by tkathrin          #+#    #+#             */
/*   Updated: 2020/10/31 11:04:35 by tkathrin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(const char *s, char c)
{
	int		i;
	int		words;

	words = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] != c && (s[i + 1] == c || s[i + 1] == '\0'))
			words++;
		i++;
	}
	return (words);
}

static int	word_len(const char *s, char c)
{
	int		i;
	int		len;

	i = 0;
	len = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static void	*ft_free(char **leaked, int pos)
{
	int i;

	i = 0;
	while (i < pos)
	{
		free(leaked[i]);
		i++;
	}
	free(leaked);
	return (NULL);
}

static char	**do_split(const char *s, char c, int words, char **to_split)
{
	int		i;
	int		j;
	int		len;

	i = 0;
	while (i < words)
	{
		while (*s == c)
			s++;
		len = word_len(s, c);
		if (!(to_split[i] = (char *)malloc(sizeof(char) * (len + 1))))
			return (ft_free(to_split, i));
		j = 0;
		while (j < len)
			to_split[i][j++] = *s++;
		to_split[i][j] = '\0';
		i++;
	}
	to_split[i] = NULL;
	return (to_split);
}

char		**ft_split(char const *s, char c)
{
	char	**newstr;
	int		words;

	if (!s)
		return (NULL);
	words = count_words(s, c);
	if (!(newstr = (char **)malloc(sizeof(char *) * (words + 1))))
		return (NULL);
	return (newstr = do_split(s, c, words, newstr));
}
