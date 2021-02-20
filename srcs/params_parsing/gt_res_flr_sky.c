/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gt_res_flr_sku.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

char	getres(char *line, t_param *data)
{
	char	*tmp;

	if (data->resx || data->resy)
	{
		printf("\tError\n\tDuplicate value for Resolution param\n");
		cleanxit(line, data, 1);
	}
	if (!(tmp = ft_strtrim(line + 1, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	data->resx = ft_atoi(tmp);
	data->resy = ft_atoi(tmp + ft_intlen(data->resx));
	tmp += ft_intlen(data->resx);
	free(tmp - ft_intlen(data->resx));
	tmp = ft_strtrim(tmp + 1, "\t\n\v\f\r ") + ft_intlen(data->resy);
	if (data->resx < 0 || data->resy < 0 || *tmp != '\0')
	{
		printf("\tError\n\tWrong Resolution size\n");
		cleanxit(line, data, 1);
	}
	free(tmp - ft_intlen(data->resy));
	free(line);
	return (1);
}

char	getfloor(char *line, t_param *data)
{
	char	*tmp;
	char	*needle;

	if (!(tmp = ft_strtrim(line + 1, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	if (!(needle = ft_strchr(tmp, ',')))
		data->flpth = tmp;
	else
	{
		data->floor[0] = ft_atoi(tmp);
		data->floor[1] = ft_atoi(needle + 1);
		if (!(needle = ft_strchr(needle + 1, ',')))
		{
			printf("\tError\n\tColor non completed need [R,G,B] format\n");
			cleanxit(line, data, 1);
		}
		data->floor[2] = ft_atoi(needle + 1);
		checkcolors(line, data->floor, data);
		free(tmp);
	}
	free(line);
	return (1);
}

char	getsky(char *line, t_param *data)
{
	char	*tmp;
	char	*needle;

	if (!(tmp = ft_strtrim(line + 1, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	if (!(needle = ft_strchr(tmp, ',')))
		data->skypth = tmp;
	else
	{
		data->sky[0] = ft_atoi(tmp);
		data->sky[1] = ft_atoi(needle + 1);
		if (!(needle = ft_strchr(needle + 1, ',')))
		{
			printf("\tError\n\tColor non completed need [R,G,B] format\n");
			cleanxit(line, data, 1);
		}
		data->sky[2] = ft_atoi(needle + 1);
		checkcolors(line, data->sky, data);
		free(tmp);
	}
	free(line);
	return (1);
}
