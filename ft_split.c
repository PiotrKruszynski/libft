/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkruszyn <pkruszyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 14:35:07 by pkruszyn          #+#    #+#             */
/*   Updated: 2026/07/10 15:22:11 by pkruszyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	count_words(const char *s, char c)
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (*s)
			count++;
		while (*s && *s != c)
			s++;
	}
	return (count);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	size_t		len;

	start = *s;
	while (**s && **s != c)
		(*s)++;
	len = (size_t)(*s - start);
	return (ft_substr(start, 0, len));
}

static void	free_split(char **res, size_t used)
{
	while (used > 0)
		free(res[--used]);
	free(res);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	char	**res;

	if (!s)
		return (NULL);
	res = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s == c)
			s++;
		if (!*s)
			break ;
		res[i] = extract_word(&s, c);
		if (!res[i])
			return (free_split(res, i), NULL);
		i++;
	}
	res[i] = NULL;
	return (res);
}
