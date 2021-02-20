/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Hud.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:37:24 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:42:32 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	putsighty(t_all *all)
{
	int		stripe;
	int		dendx;
	int		color;
	int		y;

	y = (all->data->resy / 2) - 6;
	while (y < (all->data->resy / 2) + 8)
	{
		stripe = (all->data->resx / 2) - 1;
		dendx = (all->data->resx / 2) + 1;
		while (stripe < dendx)
		{
			color = 0x00FF00;
			my_mlx_pixel_put(all->win, stripe, y, color);
			stripe++;
		}
		y++;
	}
}

void	putsightx(t_all *all)
{
	int		stripe;
	int		dendx;
	int		color;
	int		y;

	stripe = (all->data->resx / 2) - 7;
	dendx = (all->data->resx / 2) + 7;
	while (stripe < dendx)
	{
		y = (all->data->resy / 2);
		while (y < (all->data->resy / 2) + 2)
		{
			color = 0x00FF00;
			my_mlx_pixel_put(all->win, stripe, y, color);
			y++;
		}
		stripe++;
	}
	putsighty(all);
}

void	lifebar(t_all *all, int i, int j)
{
	unsigned int	color;

	while (j < 36)
	{
		i = 0;
		while (i < 200)
		{
			color = ((unsigned int*)all->hud[1]->addr)
			[((64 * (j / 2)) + (i / 4)) * 2];
			if ((color != 0xFF000000) && i < 131)
				my_mlx_pixel_put(all->win, i + 20, j + 20, color);
			color = ((unsigned int*)all->hud[1]->addr)
			[((64 * (j / 2 + 18)) + (i / 4)) * 2];
			if (color != 0xFF000000 && i < 131 &&
					((double)(i - 56) < all->life))
				my_mlx_pixel_put(all->win, i + 20, j + 20, color);
			i++;
		}
		j++;
	}
}

void	putbullet(t_all *all, int i, int j, int q)
{
	unsigned int	color;
	int				ammo;

	ammo = 1;
	while (ammo <= q)
	{
		j = 0;
		while (j < 45)
		{
			i = 0;
			while (i < 15)
			{
				color = ((unsigned int*)all->hud[0]->addr)
				[(((128) * (j / 2)) + (i))];
				if (color != 0xFF000000)
					my_mlx_pixel_put(all->win,
							all->data->resx - (50 + (20 * ammo)) - i,
							all->data->resy - 50 + j, color);
				i++;
			}
			j++;
		}
		ammo++;
	}
}

void	puthud(t_all *all)
{
	(all->life > -28) ? all->life -= 0.05 : 0;
	(all->life < -28) ? all->life = -100 : 0;
	putsightx(all);
	lifebar(all, 0, 0);
	putbullet(all, 0, 0, all->ammo);
}
