/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:48:33 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

int			getcolor(int *color)
{
	return (color[0] << 16 | color[1] << 8 | color[2]);
}

void		prepare_hud(t_all *all)
{
	all->hud[0] = get_text(ft_strdup("textures/bullet.xpm"), all->win);
	all->hud[1] = get_text(ft_strdup("textures/lifebar.xpm"), all->win);
}

void		prepare_sprite(t_all *all, t_list *temp)
{
	temp = all->data->lst;
	while (temp)
	{
		if (((t_obst*)temp->content)->type == '2')
			((t_obst*)temp->content)->obtxt[0] =
		get_text(ft_strdup("textures/barrel.xpm"), all->win);
		else if (((t_obst*)temp->content)->type == '3')
			((t_obst*)temp->content)->obtxt[0] =
		get_text(ft_strdup("textures/Pillar.xpm"), all->win);
		else if (((t_obst*)temp->content)->type == '#')
			((t_obst*)temp->content)->obtxt[0] =
			get_text(ft_strdup("textures/chestfull.xpm"), all->win);
		else if (((t_obst*)temp->content)->type == '&')
			((t_obst*)temp->content)->obtxt[0] =
			get_text(ft_strdup("textures/item.xpm"), all->win);
		else if (((t_obst*)temp->content)->type == 'T')
		{
			((t_obst*)temp->content)->obtxt[0] =
			get_text(ft_strdup("textures/SPR_GRD_SHOOT2.x-bmp.xpm"), all->win);
			((t_obst*)temp->content)->obtxt[1] =
			get_text(ft_strdup("textures/SPR_GRD_DEAD.x-bmp.xpm"), all->win);
		}
		temp = temp->next;
	}
}

void		fullprint(t_all *all)
{
	if (all->save)
	{
		save_image_to_bmp_file(all, all->data->resx, all->data->resy);
		exitgame(all);
	}
	mlx_put_image_to_window(all->win->mlx, all->win->mlxwin, all->win->img,
		0, 0);
	mlx_destroy_image(all->win->mlx, all->win->img);
}

void		startrend(t_all *all)
{
	t_list	*it;
	t_text	*text;
	double	zbuffer[all->data->resx];

	all->win->img = mlx_new_image(all->win->mlx,
		all->data->resx, all->data->resy);
	all->win->addr = mlx_get_data_addr(all->win->img,
		&all->win->bits_per_pixel, &all->win->line_length,
		&all->win->endian);
	put_floornsky(all, all->img, all->win);
	all->data->lst = sortsprite(all);
	it = all->data->lst;
	putwall(all, &text, zbuffer);
	while (it)
	{
		text = all->data->spr;
		calcspr(it, all->spt, all->img, all->data);
		putspt(all, text, zbuffer, it);
		it = it->next;
	}
	putgun(all);
	puthud(all);
	fullprint(all);
	(all->life == -100) ? theend(all, '-') : 0;
	(all->enemy == 0) ? theend(all, '+') : 0;
}
