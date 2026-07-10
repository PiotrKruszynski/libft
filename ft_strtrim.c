/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkruszyn <pkruszyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/03 09:57:44 by pkruszyn          #+#    #+#             */
/*   Updated: 2026/07/09 17:46:51 by pkruszyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	const char	*start;
	const char	*end;
	char		*res;

	if (!s1)
		return (NULL);
	if (!set || !*s1 || !*set)
		return (ft_strdup(s1));
	start = s1;
	while (*start && ft_strchr(set, *start))
		start++;
	if (*start == '\0')
		return (ft_strdup("\0"));
	end = s1 - 1 + ft_strlen(s1);
	while (end > start && ft_strchr(set, *end))
		end--;
	res = ft_substr(start, 0, end - start + 1);
	return (res);
}
