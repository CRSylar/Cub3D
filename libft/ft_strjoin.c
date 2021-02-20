/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:20:05 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 14:20:12 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*out;

	if (!s1)
		return (0);
	if (!s2)
		return (0);
	i = (ft_strlen(s1) + ft_strlen(s2) + 1);
	if ((out = (char*)malloc(i * sizeof(char))) == 0)
		return (0);
	ft_strlcpy(out, s1, i);
	ft_strlcat(out, s2, i);
	return (out);
}
