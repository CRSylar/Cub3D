/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:25:16 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:25:18 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

char	findtype(char *path)
{
	int i;

	i = 0;
	while (path[i])
		i++;
	if (!ft_strncmp(path + i - 3, "xpm", 4))
		return ('x');
	if (!ft_strncmp(path + i - 3, "png", 4))
		return ('p');
	else
		return (0);
}

t_text	*get_text_xpm(char *path, t_win *img)
{
	t_text	*out;

	if (!(out = (t_text*)malloc(sizeof(t_text))))
		return (0);
	if (!(out->txt = mlx_xpm_file_to_image(img->mlx, path,
	&(out->width), &(out->height))))
	{
		free(out);
		write(1, "\tError\n\tFile not Found at  ", 29);
		printf(" %s\n", path);
		return (0);
	}
	free(path);
	return (out);
}

t_text	*get_text_png(char *path, t_win *img)
{
	t_text	*out;

	if (!(out = (t_text*)malloc(sizeof(t_text))))
		return (0);
	if (!(out->txt = mlx_png_file_to_image(img->mlx, path,
	&(out->width), &(out->height))))
	{
		free(out);
		write(1, "\tError\n\tFile not Found at  ", 29);
		printf(" %s\n", path);
		return (0);
	}
	free(path);
	return (out);
}

t_text	*get_text(char *path, t_win *img)
{
	t_text	*out;
	char	type;

	type = findtype(path);
	if ((type == 'x') && (!(out = get_text_xpm(path, img))))
	{
		free(out);
		return (0);
	}
	else if ((type == 'p') && (!(out = get_text_png(path, img))))
	{
		free(out);
		return (0);
	}
	else if ((type != 'p') && (type != 'x'))
	{
		printf("\tError\n\twrong extension File %s", path);
		free(out);
		return (0);
	}
	out->addr = mlx_get_data_addr(out->txt,
		&(out->bpp), &(out->hline), &out->endian);
	return (out);
}

void	storetext(t_all *all)
{
	if (!(all->data->no = get_text(all->data->no, all->win)))
		exitgame(all);
	if (!(all->data->so = get_text(all->data->so, all->win)))
		exitgame(all);
	if (!(all->data->we = get_text(all->data->we, all->win)))
		exitgame(all);
	if (!(all->data->ea = get_text(all->data->ea, all->win)))
		exitgame(all);
	if (!(all->data->spr = get_text(all->data->spr, all->win)))
		exitgame(all);
	if (all->data->skypth)
		if (!(all->data->skypth = get_text(all->data->skypth, all->win)))
			exitgame(all);
	if (all->data->flpth)
		if (!(all->data->flpth = get_text(all->data->flpth, all->win)))
			exitgame(all);
}
