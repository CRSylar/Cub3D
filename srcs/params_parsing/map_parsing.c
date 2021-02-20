/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/11 17:22:16 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

void		firstnlast(t_param *data, char **map, int *y)
{
	int tx;
	int ty;

	tx = 0;
	ty = 0;
	if (!map[0])
		ft_closeall(0, data, 0);
	while (charset(map[0][*y], " 1"))
		(*y)++;
	if (map[0][*y] != '\0' && printf("\tError\n\tCarattere invalido R1"))
		ft_closeall(0, data, map);
	while (map[++tx])
	{
		while (charset(map[tx][ty], " 1"))
			ty++;
		if (!ty && (charset(map[tx][ty - 1], "1") && (map[tx][ty]))
			&& printf("\tError\n\tMappa invalida%d", tx))
			ft_closeall(0, data, map);
		ty = 0;
	}
	while (charset(map[tx - 1][ty], " 1") && setspace(&(map[tx - 1][ty])))
		ty++;
	if (map[tx - 1][ty] != '\0' &&
		printf("\tError\n\tCarattere invalido R.%d", tx))
		ft_closeall(0, data, map);
}

char		checkpossibilities(char **map, int *i, t_param *data)
{
	if (charset(map[0][i[TY]], "023#&T"))
	{
		if ((map[0][i[TY] - 1] == 32 || (*(map - 1))[i[TY]] == 32))
			return (0);
		save_obj(map, i, data);
	}
	else if (charset(map[0][i[TY]], "NSWE"))
	{
		if (map[0][i[TY] - 1] == 32 || (*(map - 1))[i[TY]] == 32)
			return (0);
		if (!data->spawn && (data->spawn = map[0][i[TY]]))
		{
			data->spy = i[TY]++;
			data->spx = i[X];
		}
		else
			return (0);
	}
	else if ((map[0][i[TY]] == 32) &&
		(!charset(map[0][i[TY] - 1], " 1") ||
			!charset((*(map - 1))[i[TY]], " 1")))
		return (0);
	else if (!charset(map[0][i[TY]++], " 1"))
		return (0);
	return (1);
}

char		checkline(char **map, int *i, t_param *data)
{
	while (map[0][i[TY]] && i[TY] < i[Y])
	{
		if (!checkpossibilities(map, i, data))
		{
			printf("\tError\n\tCarattere invalido[%c] R%d[%s]",
				map[0][--i[TY]], i[X], map[0]);
			return (0);
		}
	}
	if (--i[TY] < i[Y] && !secondcheck(*(map - 1), i))
		return (0);
	while (map[0][i[TY]])
	{
		if (!charset(map[0][i[TY]], " 1"))
			return (0);
		i[TY]++;
	}
	i[Y] = i[TY];
	return (1);
}

t_param		*map_parsing(t_list *lst, t_param *data)
{
	char	**map;
	int		i[3];

	i[X] = 1;
	i[Y] = 0;
	i[TY] = 0;
	if (!(map = (char**)malloc(sizeof(char**) * (ft_lstsize(lst) + 1))))
		ft_closeall(&lst, data, map);
	buildmap(lst, map);
	ft_lst_dleete(lst);
	firstnlast(data, map, &i[Y]);
	while (map[i[X]])
	{
		i[TY] = 0;
		while (charset(map[i[X]][i[TY]], " 1"))
			i[TY]++;
		if (!i[TY] || !checkline(&map[i[X]], i, data))
			ft_closeall(0, data, map);
		i[X]++;
	}
	if (data->spx == -1 || data->spy == -1)
		ft_closeall(0, data, map);
	data->vmap = map;
	return (data);
}
