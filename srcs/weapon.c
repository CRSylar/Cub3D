/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   weapon.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/06 15:40:21 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:49:46 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void			initgun(t_all *all)
{
	all->gun->status = WPNSTOP;
	all->gun->tex[0] = get_text(ft_strdup("textures/SPR_PISTOLATK1.xpm"),
		all->win);
	all->gun->tex[WPNSTOP] = get_text(ft_strdup("textures/SPR_PISTOLATK1.xpm"),
		all->win);
	all->gun->tex[WPNSHOT] = get_text(ft_strdup("textures/SPR_PISTOLATK2.xpm"),
		all->win);
	all->gun->tex[WPNSHOT1] = get_text(ft_strdup("textures/SPR_PISTOLATK3.xpm"),
		all->win);
	all->gun->gunx = (all->data->resx / 2) - (all->data->resx / 6);
	all->gun->guny = (all->data->resy / 2) + (all->data->resy / 6);
}

void			shoot(t_all *all)
{
	if (all->ammo)
	{
		if (!all->gun->friction && ammodda(all))
			system("afplay ./sound/shot.wav &");
		all->gun->friction += WPNFRIC;
		if (all->gun->friction < WPNLIM)
			all->gun->status = WPNSHOT;
		else if (all->gun->friction < WPNLIM1)
			all->gun->status = WPNSHOT1;
		else if (all->gun->check)
		{
			all->keyb ^= SHT;
			all->gun->status = WPNSTOP;
			all->gun->friction = 0;
			all->gun->check = 0;
			all->ammo -= 1;
		}
		else
		{
			all->gun->status = WPNSTOP;
			all->ammo -= 1;
		}
	}
	else
		all->keyb ^= SHT;
}

static	void	cast_y_gun(t_all *all, t_text *tex, int txx, int stripe)
{
	int		y;
	int		d;
	int		texy;
	int		color;
	int		i;

	y = all->gun->guny;
	i = 0;
	d = tex->height - ((all->data->resy / 3) / tex->height) * 5;
	while (y < all->data->resy)
	{
		d = y * 256 - all->data->resy * 128 + (all->data->resy / 3) * 128;
		texy = (i / ((double)(all->data->resy / 3) / (double)tex->height));
		i++;
		texy = (texy > d) ? d : texy;
		color = ((unsigned int*)tex->addr)[tex->width * texy + txx];
		if (color != 0x980088)
			my_mlx_pixel_put(all->win, stripe, y, color);
		y++;
	}
}

void			putgun(t_all *all)
{
	int		stripe;
	int		dendx;
	int		txx;
	int		i;
	t_text	*tex;

	tex = all->gun->tex[(int)all->gun->status];
	stripe = all->gun->gunx;
	dendx = all->data->resx / 3 + stripe;
	i = 0;
	while (stripe < dendx)
	{
		txx = (i / (((double)(all->data->resx / 3) / (double)tex->width)));
		i++;
		cast_y_gun(all, tex, txx, stripe);
		stripe++;
	}
}
