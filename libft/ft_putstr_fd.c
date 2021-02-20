/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putFD.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:09:36 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/19 14:03:34 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_putstr_fd(char *s, int len, int fd)
{
	int i;

	i = 0;
	if (!s || !len)
		return (i);
	if (len < 0)
	{
		while (s[i])
		{
			write(fd, &s[i], 1);
			i++;
		}
	}
	else
	{
		while ((len > 0) && s[i])
		{
			write(fd, &s[i], 1);
			i++;
			len--;
		}
	}
	return (i);
}
