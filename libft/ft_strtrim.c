/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:25:43 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:26:02 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_charset(char c, char const *set)
{
	while (*set)
	{
		if (c == *set)
			return (1);
		set++;
	}
	return (0);
}

char		*ft_strtrim(char const *s1, char const *set)
{
	char	*out;
	char	*start;
	char	*end;
	size_t	size;

	if (!s1)
		return (0);
	start = (char*)s1;
	end = start + (ft_strlen(s1));
	while (*start && ft_charset(*start, set))
		start++;
	while (start < end && ft_charset(*(end - 1), set))
		end--;
	size = end - start;
	if ((out = (char*)malloc(size + 1)) == 0)
		return (0);
	ft_strlcpy(out, start, size + 1);
	return (out);
}
