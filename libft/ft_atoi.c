/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 13:48:05 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/13 18:11:53 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *nptr)
{
	unsigned int		out;
	int					neg;

	out = 0;
	neg = 1;
	while ((*nptr >= 9 && *nptr <= 13) || *nptr == 32)
		nptr++;
	if ((*nptr == '-') || (*nptr == '+'))
	{
		if (*nptr == '-')
			neg = -1;
		nptr++;
	}
	if (*nptr < '0' || *nptr > '9')
		return (-1);
	while (*nptr >= '0' && *nptr <= '9' && out < 2147483647)
		out = (out * 10) + (*nptr++ - '0');
	if ((out == 2147483648 && neg == -1) || (out < 2147483648))
		return (out * neg);
	if (neg == 1 && out != 0)
		return (-1);
	return (0);
}
