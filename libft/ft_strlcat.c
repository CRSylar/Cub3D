/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:20:33 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 17:56:44 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t			ft_strlcat(char *dest, const char *src, size_t size)
{
	char				*dst;
	const char			*fnt;
	size_t				n;
	size_t				dlen;

	fnt = src;
	dst = dest;
	n = size;
	while (n-- != 0 && *dst != '\0')
		dst++;
	dlen = dst - dest;
	n = size - dlen;
	if (n == 0)
		return (dlen + ft_strlen(fnt));
	while (*fnt)
	{
		if (n != 1)
		{
			*dst++ = *fnt;
			n--;
		}
		fnt++;
	}
	*dst = '\0';
	return (dlen + (fnt - src));
}
