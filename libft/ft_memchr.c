/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:06:01 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:53:03 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void	*out;
	size_t	i;

	i = 0;
	out = (void*)s;
	while (i < n)
	{
		if (*(unsigned char*)s++ == (unsigned char)c)
			return (out + i);
		i++;
	}
	out = 0;
	return (out);
}
