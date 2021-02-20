/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:08:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:08:47 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char	*ptdest;
	unsigned char	*ptsrc;

	if (!dest && !src)
		return (0);
	ptdest = (unsigned char *)dest;
	ptsrc = (unsigned char*)src;
	if ((ptsrc < ptdest) && (ptdest < (ptsrc + n)))
	{
		ptdest += n;
		ptsrc += n;
		while (n--)
			*--ptdest = *--ptsrc;
	}
	else
	{
		while (n--)
			*ptdest++ = *ptsrc++;
	}
	return (dest);
}
