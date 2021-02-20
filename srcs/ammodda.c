/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ammodda.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:35:47 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:37:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static	t_rend		*initshoot(t_img *img)
{
	t_rend *rend;

	rend = malloc(sizeof(t_rend));
	rend->rayx = img->dirx;
	rend->rayy = img->diry;
	rend->mapx = (int)(img->posx);
	rend->mapy = (int)(img->posy);
	rend->deltax = fabs(1 / rend->rayx);
	rend->deltay = fabs(1 / rend->rayy);
	rend->hit = 0;
	return (rend);
}

static	int			calcstepshot(t_rend *rend, t_img *img)
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
	return (0);
}

static	int			waitfshthit(t_rend *rend, t_param *data)
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
		if (data->vmap[rend->mapy][rend->mapx] == 'T')
			rend->hit = 1;
		if (charset(data->vmap[rend->mapy][rend->mapx], "123&#"))
		{
			rend->hit = -1;
			return (0);
		}
	}
	return (0);
}

int					ammodda(t_all *all)
{
	t_rend	*rend;
	t_list	*temp;

	temp = all->data->lst;
	rend = initshoot(all->img);
	rend->hit += calcstepshot(rend, all->img) + waitfshthit(rend, all->data);
	if (rend->hit == 1)
	{
		all->data->vmap[(int)(rend->mapy)]
		[(int)(rend->mapx)] = '0';
		while (temp)
		{
			if ((((t_obst*)temp->content)->obx == rend->mapy + 0.5) &&
				((t_obst*)temp->content)->oby == rend->mapx + 0.5)
			{
				free(((t_obst*)temp->content)->obtxt[0]);
				((t_obst*)temp->content)->obtxt[0] =
				((t_obst*)temp->content)->obtxt[1];
				all->enemy -= 1;
			}
			temp = temp->next;
		}
	}
	free(rend);
	return (1);
}
