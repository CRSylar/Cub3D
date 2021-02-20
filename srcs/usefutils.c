/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   usefutils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:26:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:26:20 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	removeobj(t_all **all, int y, int x)
{
	t_list *lst;
	t_list *rm;
	t_list *tmp;

	rm = 0;
	lst = (*all)->data->lst;
	while ((*all)->data->lst)
	{
		if (((t_obst*)(*all)->data->lst->content)->oby == x + 0.5 &&
			((t_obst*)(*all)->data->lst->content)->obx == y + 0.5)
		{
			tmp = (*all)->data->lst;
			if (!rm)
				(*all)->data->lst = tmp->next;
			else
				rm->next = tmp->next;
			free_obj(all, tmp);
			if (rm)
				(*all)->data->lst = lst;
			return ;
		}
		rm = (*all)->data->lst;
		(*all)->data->lst = (*all)->data->lst->next;
	}
	(*all)->data->lst = lst;
}

void	checkcub(const char *file)
{
	int i;

	i = 0;
	while (file[i])
		i++;
	if (!(ft_strncmp(&file[i - 4], ".cub", 4)))
		return ;
	printf("\tError\nInvalid map extention, need a .cub file\n");
	exit(-1);
}

void	set_screen_size(void *mlx, int *rex, int *rey)
{
	int		sizex;
	int		sizey;

	mlx_get_screen_size(mlx, &sizex, &sizey);
	if (*rex > 1280)
		*rex = 1280;
	if (*rey > 720)
		*rey = 720;
	if (*rex < 100)
		*rex = 100;
	if (*rey < 100)
		*rey = 100;
}

void	my_mlx_pixel_put(t_win *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int		exitgame(t_all *all)
{
	if (all->win->mlx)
		mlx_destroy_window(all->win->mlx, all->win->mlxwin);
	freeall(all, 0);
	system("killall afplay");
	exit(0);
	return (1);
}
