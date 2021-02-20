/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:23:23 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/13 18:13:03 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	int		out;

	i = 0;
	out = 0;
	while ((s2[i] || s1[i]) && (i < n))
	{
		out = (unsigned char)s1[i] - (unsigned char)s2[i];
		if (!out)
			i++;
		else
			return (out);
	}
	return (out);
}
