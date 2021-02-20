/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/30 09:24:37 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/30 09:24:41 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

char	charset(char str, char *set)
{
	if (!str)
		return (0);
	while (*set)
	{
		if (str == *set++)
			return (1);
	}
	return (0);
}

void	ft_closeall(t_list **lst, t_param *data, char **map)
{
	int i;

	i = 0;
	if (!map)
		printf("\tError\nIn Malloc reading the Map");
	else
		while (map[i])
			free(map[i++]);
	free(map);
	ft_lstclear(lst, &free);
	cleanxit(0, data, 1);
}

void	ft_lst_dleete(t_list *lst)
{
	t_list *tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp);
	}
}

void	buildmap(t_list *lst, char **map)
{
	int		i;
	t_list	*tmp;

	i = 0;
	tmp = lst;
	while (tmp)
	{
		if (((char*)tmp->content)[0])
			map[i++] = tmp->content;
		tmp = tmp->next;
	}
	map[i] = 0;
}
