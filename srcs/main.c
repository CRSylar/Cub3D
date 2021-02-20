/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 16:47:11 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

static	int		countit(t_all *all)
{
	t_list	*tmp;
	int		i;

	tmp = all->data->lst;
	i = 0;
	while (tmp)
	{
		if (((t_obst*)tmp->content)->count)
			i++;
		tmp = tmp->next;
	}
	return (i);
}

static	void	startptr(t_all *all)
{
	int i;

	i = 0;
	ft_bzero(all, sizeof(t_all));
	all->win = (t_win*)malloc(sizeof(t_win));
	all->img = (t_img*)malloc(sizeof(t_img));
	all->rnd = (t_rend*)malloc(sizeof(t_rend));
	all->spt = (t_spr*)malloc(sizeof(t_spr));
	all->sfl = (t_sfl*)malloc(sizeof(t_sfl));
	all->gun = (t_gun*)malloc(sizeof(t_gun));
	all->it = (t_list*)malloc(sizeof(t_list));
	all->win->mlx = mlx_init();
	if ((!all->img) || (!all->rnd) || (!all->spt) || !(all->win->mlx)
		|| !all->sfl || !all->gun || (!all->it))
		freeall(all, 1);
}

void			allinit(t_all *all, int fd, t_list *lst)
{
	startptr(all);
	all->data = file_parsing(fd, &lst, all);
	set_screen_size(all->win->mlx, &(all->data->resx), &(all->data->resy));
	all->win->mlxwin = mlx_new_window(all->win->mlx, all->data->resx,
		all->data->resy, "Cube3d");
	imginit(all->img, all->data);
	all->keyn = 0;
	all->keyb = 0;
	all->c = 0;
	all->crc = 150;
	all->rnd->waldist = 0.01;
	all->mom = pow(10, -25);
	all->life = 100;
	all->ammo = 5;
	all->enemy = countit(all);
	initgun(all);
	prepare_sprite(all, 0);
	prepare_hud(all);
}

void			my_mlx_loop(t_all *all)
{
	mlx_hook(all->win->mlxwin, 2, 1L << 0, &keypressed, all);
	mlx_hook(all->win->mlxwin, 3, 1L << 1, &keyreleased, all);
	mlx_hook(all->win->mlxwin, 17, 1L << 2, &exitgame, all);
	mlx_hook(all->win->mlxwin, 6, 0, &mouse, all);
	mlx_loop_hook(all->win->mlx, krend, all);
	mlx_loop(all->win->mlx);
}

int				main(int argc, const char **argv)
{
	int			fd;
	t_all		all;

	all.save = 0;
	if (argc < 2 || argc > 3)
	{
		printf("\tError \n\tPlease insert a valid amount of Args\n");
		return (-1);
	}
	checkcub(argv[1]);
	if ((argc == 3) && (!(ft_strncmp(argv[2], "--save", 7))))
		all.save = 'y';
	else if ((argc == 3) && (printf("Error\n --save or NULL\nas 2nd argv")))
		return (-1);
	if ((fd = open(argv[1], O_RDONLY)) == -1)
	{
		printf("\tError \n\tOpening the map file \n%s\n", argv[1]);
		return (-1);
	}
	allinit(&all, fd, 0);
	storetext(&all);
	system("afplay ./sound/music.mp3 &");
	my_mlx_loop(&all);
	return (0);
}
