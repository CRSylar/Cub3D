/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   save_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:10:22 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:10:24 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

int			setspace(char *c)
{
	if (*c == ' ')
		*c = '1';
	return (1);
}

char		secondcheck(char *map, int *i)
{
	int len;

	len = i[TY];
	while (map[len])
	{
		if (!charset(map[len], " 1"))
			return (0);
		len++;
	}
	return (1);
}

void		save_obj(char **map, int *coord, t_param *data)
{
	t_obst	*tmp;
	t_list	*t2;

	if (map[0][coord[TY]++] == '0')
		return ;
	if (!(t2 = (t_list*)ft_calloc(1, sizeof(t_list))))
		ft_closeall(0, data, map - coord[X]);
	ft_lstadd_front(&(data->lst), t2);
	if (!(tmp = (t_obst*)ft_calloc(1, sizeof(t_obst))))
		ft_closeall(0, data, map - coord[X]);
	tmp->obx = 0.5 + coord[X];
	tmp->oby = 0.5 + coord[TY] - 1;
	tmp->type = map[0][coord[TY] - 1];
	if (tmp->type == 'T')
		tmp->count = 1;
	else
		tmp->count = 0;
	data->lst->content = tmp;
}
