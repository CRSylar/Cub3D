/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initrend.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:27:07 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:27:10 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	initrend(int x, t_rend *rend, t_param *data, t_img *img)
{
	rend->camx = (2 * x / (double)data->resx) - 1;
	rend->rayx = img->dirx + (img->planex * -rend->camx);
	rend->rayy = img->diry + (img->planey * -rend->camx);
	rend->mapx = (int)(img->posx);
	rend->mapy = (int)(img->posy);
	rend->deltax = fabs(1 / rend->rayx);
	rend->deltay = fabs(1 / rend->rayy);
	rend->hit = 0;
}

void	calcstep(t_rend *rend, t_img *img)
{
	if (rend->rayx < 0)
	{
		rend->stepx = -1;
		rend->sdx = (img->posx - rend->mapx) * rend->deltax;
	}
	else
	{
		rend->stepx = 1;
		rend->sdx = (rend->mapx + 1.0 - img->posx) * rend->deltax;
	}
	if (rend->rayy < 0)
	{
		rend->stepy = -1;
		rend->sdy = (img->posy - rend->mapy) * rend->deltay;
	}
	else
	{
		rend->stepy = 1;
		rend->sdy = (rend->mapy + 1.0 - img->posy) * rend->deltay;
	}
}

void	waitforhit(t_rend *rend, t_param *data)
{
	while (rend->hit == 0)
	{
		if (rend->sdx < rend->sdy)
		{
			rend->sdx += rend->deltax;
			rend->mapx += rend->stepx;
			rend->side = 0;
		}
		else
		{
			rend->sdy += rend->deltay;
			rend->mapy += rend->stepy;
			rend->side = 1;
		}
		if (data->vmap[rend->mapy][rend->mapx] == '1')
			rend->hit = 1;
	}
}

void	getdirection(t_rend *rend, t_img *img)
{
	if (!rend->side)
	{
		rend->waldist = (rend->mapx - img->posx + (1 - rend->stepx) / 2) /
		rend->rayx;
		rend->wallx = img->posy + rend->waldist * rend->rayy;
		if (img->posx > rend->mapx)
			rend->side = 2;
	}
	else
	{
		rend->waldist = (rend->mapy - img->posy + (1 - rend->stepy) / 2) /
		rend->rayy;
		rend->wallx = img->posx + rend->waldist * rend->rayx;
		if (img->posy > rend->mapy)
			rend->side = 3;
	}
}

void	wallprepare(t_rend *rend, t_param *data, t_img *img, t_text **text)
{
	int y;

	if (!rend->side)
		*text = data->ea;
	if (rend->side == 2)
		*text = data->we;
	if (rend->side == 1)
		*text = data->so;
	if (rend->side == 3)
		*text = data->no;
	rend->texx = (int)(rend->wallx * (double)((*text)->width));
	rend->hline = (int)(data->resy / rend->waldist);
	rend->step = 1.0 * (*text)->height / rend->hline;
	if ((rend->dstart = (-rend->hline / 2) + (data->resy / 2) +
		img->pitch + (img->posz / rend->waldist)) < 0)
		rend->dstart = 0;
	if ((rend->dend = rend->hline / 2 + data->resy / 2 + img->pitch +
		(img->posz / rend->waldist)) >= data->resy)
		rend->dend = data->resy - 1;
	rend->texpos = (rend->dstart - img->pitch - (img->posz / rend->waldist)
		- (data->resy / 2) + rend->hline / 2) * rend->step;
	y = rend->dstart;
}
