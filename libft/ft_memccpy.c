/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:03:50 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:05:28 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*s1;
	unsigned char	*s2;

	if (!dest && !src)
		return (0);
	i = 0;
	s1 = dest;
	s2 = (unsigned char *)src;
	while (i < n)
	{
		if (((s1[i] = s2[i])) == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (0);
}
