/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

void	cleanxit(char *line, t_param *data, char c)
{
	free(line);
	(data->no) ? free(data->no) : 0;
	(data->so) ? free(data->so) : 0;
	(data->we) ? free(data->we) : 0;
	(data->ea) ? free(data->ea) : 0;
	(data->spr) ? free(data->spr) : 0;
	ft_lstclear(&(data->lst), &free);
	close(data->fd);
	if (c)
	{
		printf("\tError\nin some Map Params\n\tBye-Bye\n\n");
		exit(0);
	}
}

void	initdata(t_param *data, int fd)
{
	int i;

	i = 0;
	data->fd = fd;
	data->resx = 0;
	data->resy = 0;
	data->no = 0;
	data->so = 0;
	data->we = 0;
	data->ea = 0;
	data->spr = 0;
	data->flpth = 0;
	data->skypth = 0;
	data->spawn = 0;
	data->lst = 0;
	data->spx = -1;
	data->spy = -1;
	while (i < 3)
	{
		data->floor[i] = -1;
		data->sky[i] = -1;
		i++;
	}
}

int		ft_precval(char *line, t_param *data, char c)
{
	if (c == 'f')
	{
		if (data->floor[0] != -1 || data->flpth)
			cleanxit(line, data, printf("\tError\nDouble entry for Floor"));
	}
	else
	{
		if (data->sky[0] != -1 || data->skypth)
			cleanxit(line, data, printf("\tError\nDouble entry for Ceiling"));
	}
	return (1);
}

void	checkcolors(char *line, int *value, t_param *data)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = line + 1;
	while (i < 3)
	{
		while (charset(*tmp, ", \t\v\n\b\r"))
			tmp++;
		tmp += ft_intlen(value[i]);
		if (value[i] < 0 || value[i] > 255)
		{
			printf("\tError\n[R,G,B] Params must fit in 0-255 range\n");
			cleanxit(line, data, 1);
		}
		i++;
	}
	if (*tmp)
	{
		printf("\tError\n[R,G,B] Params must end after B param\n");
		cleanxit(line, data, 1);
	}
}

void	checkflag(char *line, t_param *data)
{
	if (!((data->resx) && (data->resy) &&
			((char*)data->no) && ((char*)data->so) &&
			((char*)data->we) && ((char*)data->ea) &&
			((char*)data->spr) &&
			(((char*)data->flpth) || (data->floor[1] >= 0)) &&
			(((char*)data->skypth) || (data->sky[1] >= 0))))
		cleanxit(line, data, printf("\tError\n\n some Params is missing\n"));
}
