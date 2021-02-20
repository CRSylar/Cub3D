/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stoa_b.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/19 14:03:46 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 14:03:59 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(size_t n, int base)
{
	return ((n == 0) ? 0 : 1 + nlen(n / base, base));
}

static char	*ft_givebase(char flag)
{
	if (flag == 'd')
		return (BASE_10);
	if (flag == 'h')
		return (BASE_16);
	if (flag == 'H')
		return (BASE_16B);
	if (flag == 'o')
		return (BASE_8);
	else
		return (0);
}

char		*ft_stoa_b(size_t n, char flag)
{
	char			*base;
	char			*out;
	size_t			ncpy;
	int				lenbase;
	int				len;

	if (!(base = ft_givebase(flag)))
		return (0);
	lenbase = ft_strlen(base);
	len = 1 + nlen(n / lenbase, lenbase);
	out = 0;
	ncpy = n;
	if (!(out = (char*)ft_calloc(len + 1, sizeof(char))))
		return (0);
	out[len] = 0;
	while (ncpy)
	{
		out[--len] = base[ncpy % lenbase];
		ncpy /= lenbase;
	}
	if (!out[0])
		out[0] = '0';
	return (out);
}
