/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:16:51 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:18:22 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static	void	west(t_img *img)
{
	img->dirx = -1;
	img->diry = 0;
	img->planex = 0;
	img->planey = 0.75;
}

static	void	east(t_img *img)
{
	img->dirx = 1;
	img->diry = 0;
	img->planex = 0;
	img->planey = -0.75;
}

static void		south(t_img *img)
{
	img->dirx = 0;
	img->diry = 1;
	img->planex = 0.75;
	img->planey = 0;
}

static void		nord(t_img *img)
{
	img->dirx = 0;
	img->diry = -1;
	img->planex = -0.75;
	img->planey = 0;
}

void			imginit(t_img *img, t_param *data)
{
	img->posx = data->spy + 0.5;
	img->posy = data->spx + 0.5;
	img->pitch = 0;
	img->posz = 0.5;
	if (data->spawn == 'W')
		west(img);
	else if (data->spawn == 'E')
		east(img);
	else if (data->spawn == 'S')
		south(img);
	else if (data->spawn == 'N')
		nord(img);
}
