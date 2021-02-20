/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:07:51 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:07:59 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;
	char	*s2;

	if (!dest && !src)
		return (0);
	i = 0;
	s2 = dest;
	while (n--)
	{
		s2[i] = *(char*)src++;
		i++;
	}
	return (dest);
}
