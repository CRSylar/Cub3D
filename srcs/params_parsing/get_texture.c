/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_texture.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

char	getnord(char *line, t_param *data)
{
	if (ft_strlen(line) < 4)
		cleanxit(line, data, printf("%s\n", "NO param empty"));
	if (data->no)
	{
		printf("\tError\n\tDuplicate entry for NO param");
		cleanxit(line, data, 1);
	}
	if (!(data->no = ft_strtrim(line, "NO\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	free(line);
	return (1);
}

char	getsud(char *line, t_param *data)
{
	if (ft_strlen(line) < 4)
		cleanxit(line, data, printf("%s\n", "SO param empty"));
	if (data->so)
	{
		printf("\tError\n\tDuplicate entry for SO param");
		cleanxit(line, data, 1);
	}
	if (!(data->so = ft_strtrim(line, "SO\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	free(line);
	return (1);
}

char	getwest(char *line, t_param *data)
{
	if (ft_strlen(line) < 4)
		cleanxit(line, data, printf("%s\n", "WE param empty"));
	if (data->we)
	{
		printf("\tError\n\tDuplicate entry for WE param");
		cleanxit(line, data, 1);
	}
	if (!(data->we = ft_strtrim(line + 2, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	free(line);
	return (1);
}

char	getest(char *line, t_param *data)
{
	if (ft_strlen(line) < 4)
		cleanxit(line, data, printf("%s\n", "EA param empty"));
	if (data->ea)
	{
		printf("\tError\n\tDuplicate entry for EA param");
		cleanxit(line, data, 1);
	}
	if (!(data->ea = ft_strtrim(line + 2, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	free(line);
	return (1);
}

char	getsprite(char *line, t_param *data)
{
	if (ft_strlen(line) < 4)
		cleanxit(line, data, printf("%s\n", "SPR param empty"));
	if (data->spr)
	{
		printf("\tError\n\tDuplicate entry for S param");
		cleanxit(line, data, 1);
	}
	if (!(data->spr = ft_strtrim(line + 1, "\t\n\v\f\r ")))
	{
		printf("\tError\n\tMem allocation\n");
		cleanxit(line, data, 1);
	}
	free(line);
	return (1);
}
