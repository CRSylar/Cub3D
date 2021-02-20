/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:11:42 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 15:07:48 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_wcount(char const *s, char c)
{
	int i;
	int count;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

char		**ft_split(char const *s, char c)
{
	size_t	i;
	char	**out;
	char	*start;

	out = 0;
	i = 0;
	if ((!s) ||
		(out = (char**)malloc((ft_wcount(s, c) + 1) * sizeof(char*))) == 0)
		return (0);
	while (*s)
	{
		if (*s != c)
		{
			start = (char*)s;
			while (*s && *s != c)
				s++;
			if ((out[i] = (char*)malloc((s - start) + 1)) == 0)
				return (0);
			ft_strlcpy(out[i++], start, (s - start) + 1);
		}
		else
			s++;
	}
	out[i] = 0;
	return (out);
}
