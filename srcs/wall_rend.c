/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wall_rend.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:30:29 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:30:31 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int		addshade(t_all *all, t_text **text, char c, t_list *it)
{
	int		color;
	int		shade;
	double	divide;
	t_text	*t;

	if (it && ((t_obst*)it->content)->obtxt[0])
		t = ((t_obst*)it->content)->obtxt[0];
	divide = all->rnd->waldist / 1.5;
	color = ((unsigned int*)(*text)->addr)[(*text)->height * all->rnd->texy +
		all->rnd->texx];
	if (c == 'o')
	{
		divide = (sqrt(((t_obst*)it->content)->dist));
		color = ((unsigned int *)t->addr)[t->height * all->rnd->texy +
			all->rnd->texx];
	}
	if (divide < 1)
		divide = 1;
	shade = (((int)(((0xFF0000 & color) >> 16) / divide) << 16)
		+ ((int)(((0x00FF00 & color) >> 8) / divide) << 8)
		+ ((int)((0x0000FF & color) / divide)));
	return (shade);
}

void	putwall(t_all *all, t_text **text, double *zbuffer)
{
	int		x;
	int		y;
	size_t	color;

	x = -1;
	while (++x < (all->data->resx))
	{
		initrend(x, all->rnd, all->data, all->img);
		calcstep(all->rnd, all->img);
		waitforhit(all->rnd, all->data);
		getdirection(all->rnd, all->img);
		all->rnd->wallx -= floor((all->rnd->wallx));
		wallprepare(all->rnd, all->data, all->img, text);
		y = all->rnd->dstart;
		while (y < all->rnd->dend)
		{
			all->rnd->texy = (int)all->rnd->texpos & ((*text)->width - 1);
			all->rnd->texpos += all->rnd->step;
			color = addshade(all, text, 0, 0);
			my_mlx_pixel_put(all->win, x, y, color);
			y++;
		}
		zbuffer[x] = all->rnd->waldist;
	}
}
