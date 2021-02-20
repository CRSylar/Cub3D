/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:19:13 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:19:50 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*out;
	size_t	i;
	size_t	len;

	i = 0;
	len = ft_strlen(s);
	if ((out = (char*)ft_calloc(len + 1, sizeof(char))) == 0)
		return (0);
	while (i < len)
	{
		out[i] = s[i];
		i++;
	}
	out[i] = '\0';
	return (out);
}
