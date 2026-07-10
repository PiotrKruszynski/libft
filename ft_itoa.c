/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pkruszyn <pkruszyn@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/07/08 12:10:42 by pkruszyn          #+#    #+#             */
/*   Updated: 2026/07/09 15:58:10 by pkruszyn         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(long n)
{
	int	count;

	count = 1;
	if (n < 0)
		n = -n;
	while (n >= 10)
	{
		n = n / 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	long	nb;
	int		len;
	int		negative;
	char	*res;

	negative = (n < 0);
	nb = n;
	if (negative)
		nb = -nb;
	len = count_digits(nb);
	if (negative)
		len = len + 1;
	res = malloc(sizeof(char) * (len + 1));
	if (!res)
		return (NULL);
	res[len] = '\0';
	while (len > negative)
	{
		res[--len] = (nb % 10) + '0';
		nb = nb / 10;
	}
	if (negative)
		res[0] = '-';
	return (res);
}
