/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_flornsky.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:34:10 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:49:17 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	setparams(t_all *all, int y, char c)
{
	int p;

	all->sfl->raydirx0 = all->img->dirx - all->img->planex * -all->rnd->camx;
	all->sfl->raydiry0 = all->img->diry - all->img->planey * -all->rnd->camx;
	all->sfl->raydirx1 = all->img->dirx + all->img->planex * -all->rnd->camx;
	all->sfl->raydiry1 = all->img->diry + all->img->planey * -all->rnd->camx;
	if (!c)
	{
		p = y - all->data->resy / 2 - all->img->pitch;
		all->sfl->camz = 0.5 * all->data->resy + all->img->posz;
	}
	else
	{
		p = all->data->resy / 2 - y + all->img->pitch;
		all->sfl->camz = 0.5 * all->data->resy - all->img->posz;
	}
	all->sfl->rowdis = all->sfl->camz / p;
	all->sfl->flstpx = all->sfl->rowdis * (all->sfl->raydirx1 -
		all->sfl->raydirx0) / all->data->resx;
	all->sfl->flstpy = all->sfl->rowdis * (all->sfl->raydiry1 -
		all->sfl->raydiry0) / all->data->resx;
	all->sfl->floorx = all->img->posx + all->sfl->rowdis * all->sfl->raydirx0;
	all->sfl->floory = all->img->posy + all->sfl->rowdis * all->sfl->raydiry0;
}

void	findcolorpixel(t_all *all, t_text *t, char c)
{
	if (c)
	{
		all->sfl->celx = ((int)all->sfl->floorx);
		all->sfl->cely = ((int)all->sfl->floory);
		all->sfl->tx = (int)(t->width * (all->sfl->floorx - all->sfl->celx)) &
		(t->width - 1);
		all->sfl->ty = (int)(t->height * (all->sfl->floory - all->sfl->cely)) &
		(t->height - 1);
		all->sfl->floorx += all->sfl->flstpx;
		all->sfl->floory += all->sfl->flstpy;
	}
	else
	{
		all->sfl->celx = ((int)all->sfl->floorx);
		all->sfl->cely = ((int)all->sfl->floory);
		all->sfl->tx = (int)(t->width * (all->sfl->floorx - all->sfl->celx)) &
		(t->width - 1);
		all->sfl->ty = (int)(t->height * (all->sfl->floory - all->sfl->cely)) &
		(t->height - 1);
		all->sfl->floorx += all->sfl->flstpx;
		all->sfl->floory += all->sfl->flstpy;
	}
}

void	putfloortxt(t_all *all, t_text *floor)
{
	int		y;
	int		x;
	int		color;

	floor = all->data->flpth;
	y = all->data->resy / 2 + all->img->pitch;
	while (y < all->data->resy)
	{
		setparams(all, y, 0);
		x = 0;
		while (x < all->data->resx)
		{
			findcolorpixel(all, floor, 0);
			color = ((unsigned int*)floor->addr)
			[floor->width * all->sfl->ty + all->sfl->tx];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	putskytxt(t_all *all, t_text *sky)
{
	int		y;
	int		x;
	int		color;

	sky = all->data->skypth;
	y = 0;
	while (y < all->data->resy / 2 + all->img->pitch)
	{
		setparams(all, y, 1);
		x = 0;
		while (x < all->data->resx)
		{
			findcolorpixel(all, sky, 1);
			color = ((unsigned int*)sky->addr)
			[sky->width * all->sfl->ty + all->sfl->tx];
			if ((color & 0x00FFFFFF) != 0)
				my_mlx_pixel_put(all->win, x, y, color);
			x++;
		}
		y++;
	}
}

void	put_floornsky(t_all *all, t_img *img, t_win *win)
{
	int x;
	int y;

	y = -1;
	if (all->data->skypth)
		putskytxt(all, 0);
	if (all->data->flpth)
		putfloortxt(all, 0);
	if (!all->data->skypth && !all->data->flpth)
	{
		while (++y < all->data->resy / 2 + img->pitch)
		{
			x = -1;
			while (++x < all->data->resx)
				my_mlx_pixel_put(win, x, y, getcolor(all->data->sky));
		}
		while (y < all->data->resy)
		{
			x = -1;
			while (++x < all->data->resx)
				my_mlx_pixel_put(win, x, y, getcolor(all->data->floor));
			y++;
		}
	}
}
