/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:09:02 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:09:08 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, unsigned int n)
{
	unsigned int	i;
	unsigned char	*ptr;

	ptr = str;
	i = 0;
	while (i < n)
	{
		*ptr++ = (unsigned char)c;
		i++;
	}
	return (str);
}
