/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:02:27 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:31:10 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	wise_rotation(t_all *all, double c)
{
	double olddirx;
	double oldplanex;

	if (all->mom < 0.06)
		all->mom += all->mom;
	all->mom = 0;
	olddirx = all->img->dirx;
	all->img->dirx = all->img->dirx * cos(-(ROT * c) - all->mom) -
		all->img->diry * sin(-(ROT * c) - all->mom);
	all->img->diry = olddirx * sin(-(ROT * c) - all->mom) + all->img->diry *
		cos(-(ROT * c) - all->mom);
	oldplanex = all->img->planex;
	all->img->planex = all->img->planex * cos(-(ROT * c) - all->mom) -
		all->img->planey * sin(-(ROT * c) - all->mom);
	all->img->planey = oldplanex * sin(-(ROT * c) - all->mom) +
		all->img->planey * cos(-(ROT * c) - all->mom);
}

void	counter_rotation(t_all *all, double c)
{
	double olddirx;
	double oldplanex;

	if (all->mom < 0.06)
		all->mom += all->mom;
	all->mom = 0;
	olddirx = all->img->dirx;
	all->img->dirx = all->img->dirx * cos((ROT * c) + all->mom) -
	all->img->diry * sin((ROT * c) + all->mom);
	all->img->diry = olddirx * sin((ROT * c) + all->mom) + all->img->diry *
		cos((ROT * c) + all->mom);
	oldplanex = all->img->planex;
	all->img->planex = all->img->planex * cos((ROT * c) + all->mom) -
		all->img->planey * sin((ROT * c) + all->mom);
	all->img->planey = oldplanex * sin((ROT * c) + all->mom) +
		all->img->planey * cos((ROT * c) + all->mom);
}
