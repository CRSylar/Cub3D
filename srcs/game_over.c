/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_over.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 16:34:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:35:35 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static	int		kcheck(t_all *all)
{
	mlx_hook(all->win->mlxwin, 2, 1L << 0, &keypressed, all);
	if (all->keyn & ESC)
		exitgame(all);
	return (1);
}

int				theend(t_all *all, char c)
{
	if (c == '-')
	{
		system("killall afplay");
		system("afplay ./sound/death.wav &");
		all->win->img = mlx_xpm_file_to_image(all->win->mlx,
				"textures/game-over.xpm", &(all->win->line_length),
				&(all->win->bits_per_pixel));
	}
	else if (c == '+')
	{
		system("killall afplay");
		system("afplay ./sound/Victory_Fanfare.mp3 &");
		all->win->img = mlx_xpm_file_to_image(all->win->mlx,
				"textures/End-game.xpm", &(all->win->line_length),
				&(all->win->bits_per_pixel));
	}
	mlx_put_image_to_window(all->win->mlx, all->win->mlxwin, all->win->img,
		0, 0);
	mlx_loop_hook(all->win->mlx, &kcheck, all);
	mlx_loop(all->win->mlx);
	return (1);
}
