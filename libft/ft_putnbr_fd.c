/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putFD.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/11 14:09:36 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/11 15:49:43 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void			ft_putnbr_fd(int nb, int fd)
{
	int t;
	int sz;

	if (nb < 0)
	{
		ft_putchar_fd('-', fd);
		nb = -nb;
	}
	if (nb == -2147483648)
	{
		ft_putchar_fd('2', fd);
		nb = 147483648;
	}
	t = nb;
	sz = 1;
	while ((t = t / 10) > 0)
		sz = sz * 10;
	t = nb;
	while (sz)
	{
		ft_putchar_fd((t / sz) + '0', fd);
		t = t % sz;
		sz = sz / 10;
	}
}
