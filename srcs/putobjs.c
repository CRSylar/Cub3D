/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   putobjs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:35:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:35:30 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	calcspr(t_list *it, t_spr *spt, t_img *img, t_param *data)
{
	spt->spritex = ((t_obst*)it->content)->oby - img->posx;
	spt->spritey = ((t_obst*)it->content)->obx - img->posy;
	spt->invdet = 1.0 / (img->planex * img->diry - img->dirx * img->planey);
	spt->trasfx = -spt->invdet * (img->diry * spt->spritex -
		img->dirx * spt->spritey);
	spt->trasfy = spt->invdet * (-img->planey * spt->spritex + img->planex *
		spt->spritey);
	spt->screenx = (int)((data->resx / 2) * (1 + spt->trasfx / spt->trasfy));
	spt->vmscreen = (int)(0.0 / spt->trasfy) + img->pitch + img->posz /
	spt->trasfy;
	spt->spriteh = abs((int)(data->resy / spt->trasfy)) / 1;
	if ((spt->dstarty = (-spt->spriteh / 2) + (data->resy / 2) +
		spt->vmscreen) < 0)
		spt->dstarty = 0;
	if ((spt->dendy = (spt->spriteh / 2) + (data->resy / 2) + spt->vmscreen)
		>= data->resy)
		spt->dendy = data->resy - 1;
	spt->spritew = abs((int)(data->resy / spt->trasfy)) / 1;
	if ((spt->dstartx = -spt->spritew / 2 + spt->screenx) < 0)
		spt->dstartx = 0;
	if ((spt->dendx = spt->spritew / 2 + spt->screenx) >= data->resx)
		spt->dendx = data->resx - 1;
	spt->stripe = spt->dstartx - 1;
}

void	putspt(t_all *all, t_text *text, double *zbuffer, t_list *it)
{
	int		y;
	size_t	color;

	while (++all->spt->stripe < all->spt->dendx)
	{
		all->rnd->texx = (int)(256 * (all->spt->stripe - (-all->spt->spritew /
			2 + all->spt->screenx)) * text->width / all->spt->spritew) / 256;
		if ((all->spt->trasfy > 0) && (all->spt->stripe > 0) &&
			(all->spt->stripe < all->data->resx) && (all->spt->trasfy <=
				zbuffer[all->spt->stripe]))
		{
			y = all->spt->dstarty - 1;
			while (++y < all->spt->dendy)
			{
				all->spt->d = (y - all->spt->vmscreen) * 256 -
				(all->data->resy * 128) + (all->spt->spriteh * 128);
				all->rnd->texy = ((all->spt->d * text->height) /
					all->spt->spriteh) / 256;
				color = addshade(all, &text, 'o', it);
				if ((color & 0x00FFFFFF) != 0)
					my_mlx_pixel_put(all->win, all->spt->stripe, y, color);
			}
		}
	}
}
