/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:24:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:24:26 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	k;

	i = 0;
	k = 0;
	if (!(*little))
		return ((char*)big);
	while (big[i])
	{
		while ((big[i + k] == little[k]) && (i + k) < len)
		{
			if (little[k + 1] == '\0')
				return ((char*)big + i);
			k++;
		}
		k = 0;
		i++;
	}
	return (0);
}
