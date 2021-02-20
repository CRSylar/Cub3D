/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/20 11:51:49 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/20 18:44:50 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	double	gestsign(double num, char *ret)
{
	if (num < 0)
	{
		ret[0] = '-';
		return (-num);
	}
	return (num);
}

int				ft_dtoa(double num, char **intpart, char **decpart)
{
	char	ret[2];
	int		i;
	double	f;
	int		x;

	if (!num)
	{
		*intpart = 0;
		*decpart = 0;
		return (0);
	}
	f = gestsign(num, ret);
	*intpart = ft_stoa_b(f, 'd');
	i = ft_strlen(*intpart);
	f *= 10000000000000000;
	*decpart = ft_stoa_b(f, 'd');
	*decpart = ft_strjoin(".", *decpart + i);
	x = ft_strlen(*decpart);
	while (*((*decpart) + x - 1) == '0')
		*(*decpart + x--) = 0;
	*intpart = ft_strjoin(ret, *intpart);
	return (i);
}
