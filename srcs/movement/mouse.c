/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:22:00 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:22:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int		mouse(int x, int y, t_all *all)
{
	static int xc;

	mlx_mouse_hide();
	mlx_mouse_get_pos(all->win->mlxwin, &xc, &y);
	if (xc > (all->data->resx / 2) + 8)
		wise_rotation(all, (xc - 10008) / 3000);
	else if (x < (all->data->resx / 2) - 8)
		counter_rotation(all, (xc - 10008) / 3000);
	mlx_mouse_move(all->win->mlxwin, all->data->resx / 2, all->data->resy / 2);
	return (0);
}
