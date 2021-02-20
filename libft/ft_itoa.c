/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:55:08 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 13:57:02 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	nlen(int n)
{
	return ((n == 0) ? 0 : 1 + nlen(n / 10));
}

char		*ft_itoa(int n)
{
	unsigned int	ncpy;
	int				len;
	char			*out;

	len = 1 + nlen(n / 10);
	out = 0;
	if (n < 0)
	{
		ncpy = -n;
		len++;
	}
	else
		ncpy = n;
	if ((out = (char*)ft_calloc(len + 1, sizeof(char))) == 0)
		return (0);
	out[len] = 0;
	if (n < 0)
		out[0] = '-';
	while (ncpy)
	{
		out[--len] = (ncpy % 10) + '0';
		ncpy /= 10;
	}
	(out[0]) ? len++ : (out[0] = '0');
	return (out);
}
