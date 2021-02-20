/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:30:28 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:30:34 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	move_forward(t_all *all)
{
	if (!charset(all->data->vmap[(int)(all->img->posy)][(int)(all->img->posx +
		all->img->dirx * (MIN(MOV, all->crc)))], "123"))
		all->img->posx += all->img->dirx * (MIN(MOV, all->crc));
	if (!charset(all->data->vmap[(int)(all->img->posy + all->img->diry *
		(MIN(MOV, all->crc)))][(int)(all->img->posx)], "123"))
		all->img->posy += all->img->diry * (MIN(MOV, all->crc));
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "#"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->ammo += 5;
	}
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "&"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->life += 25;
		(all->life > 100) ? all->life = 100 : 0;
	}
}

void	move_back(t_all *all)
{
	if (!charset(all->data->vmap[(int)(all->img->posy)][(int)(all->img->posx -
		all->img->dirx * (MIN(MOV, all->crc)))], "123"))
		all->img->posx -= all->img->dirx * (MIN(MOV, all->crc));
	if (!charset(all->data->vmap[(int)(all->img->posy - all->img->diry *
		(MIN(MOV, all->crc)))][(int)(all->img->posx)], "123"))
		all->img->posy -= all->img->diry * (MIN(MOV, all->crc));
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "#"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->ammo += 5;
	}
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "&"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->life += 25;
		(all->life > 100) ? all->life = 100 : 0;
	}
}

void	move_right(t_all *all)
{
	if (!charset(all->data->vmap[(int)(all->img->posy + all->img->dirx *
		(MIN(MOV, all->crc)))][(int)(all->img->posx)], "123"))
		all->img->posy += all->img->dirx * (MIN(MOV, all->crc));
	if (!charset(all->data->vmap[(int)(all->img->posy)][(int)(all->img->posx -
		all->img->diry * (MIN(MOV, all->crc)))], "123"))
		all->img->posx -= all->img->diry * (MIN(MOV, all->crc));
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "#"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->ammo += 5;
	}
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "&"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->life += 25;
		(all->life > 100) ? all->life = 100 : 0;
	}
}

void	move_left(t_all *all)
{
	if (!charset(all->data->vmap[(int)(all->img->posy - all->img->dirx *
		(MIN(MOV, all->crc)))][(int)(all->img->posx)], "123"))
		all->img->posy -= all->img->dirx * (MIN(MOV, all->crc));
	if (!charset(all->data->vmap[(int)(all->img->posy)][(int)(all->img->posx +
		all->img->diry * (MIN(MOV, all->crc)))], "123"))
		all->img->posx += all->img->diry * (MIN(MOV, all->crc));
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "#"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->ammo += 5;
	}
	if (charset(all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)], "&"))
	{
		system("afplay ./sound/wolf/Pickup.wav &");
		all->data->vmap[(int)(all->img->posy)]
		[(int)(all->img->posx)] = '0';
		removeobj(&all, (int)(all->img->posy), (int)(all->img->posx));
		all->life += 25;
		(all->life > 100) ? all->life = 100 : 0;
	}
}
