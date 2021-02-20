/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   spriter.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:10:58 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:01 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/main.h"

void	calcdistance(t_all *all)
{
	t_list	*tmp;
	t_img	*img;
	t_obst	*obst;

	img = all->img;
	tmp = all->data->lst;
	obst = all->data->lst->content;
	while (tmp)
	{
		obst = tmp->content;
		obst->dist = ((img->posx - obst->oby) * (img->posx - obst->oby) +
						(img->posy - obst->obx) * (img->posy - obst->obx));
		tmp = tmp->next;
	}
}

t_list	*findmin(t_all *all, t_list *prec)
{
	double	n;
	t_list	*tmp;

	if (!all->data->lst)
		return (0);
	tmp = all->data->lst;
	n = ((t_obst*)tmp->content)->dist;
	while (tmp->next)
	{
		if (((t_obst*)tmp->next->content)->dist <= n)
		{
			n = ((t_obst*)tmp->next->content)->dist;
			prec = tmp;
		}
		tmp = tmp->next;
	}
	if (prec)
	{
		tmp = prec->next;
		prec->next = tmp->next;
		return (tmp);
	}
	tmp = all->data->lst;
	all->data->lst = tmp->next;
	return (tmp);
}

t_list	*sortsprite(t_all *all)
{
	t_list	*out;
	t_list	*min;

	out = 0;
	if (!all->data->lst)
		return (0);
	calcdistance(all);
	while ((min = findmin(all, 0)))
	{
		min->next = 0;
		ft_lstadd_front(&out, min);
	}
	return (out);
}
