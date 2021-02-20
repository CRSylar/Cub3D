/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 10:13:12 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/17 10:13:18 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	free_obj(t_all **all, t_list *tmp)
{
	mlx_destroy_image((*all)->win->mlx,
		((t_obst*)tmp->content)->obtxt[0]->txt);
	free(((t_obst*)tmp->content)->obtxt[0]);
	free(((t_obst*)tmp->content));
	free(tmp);
}
