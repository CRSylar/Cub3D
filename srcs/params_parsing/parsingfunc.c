/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsingfunc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:58 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/cube3d_params.h"

static void	ft_iferror(char res, t_list **lst)
{
	if (res == -1 && *lst && printf("GetNextLine\n"))
	{
		ft_lstclear(lst, &free);
		generic_error();
	}
}

char		flagparsing(char *line, t_param *data)
{
	if (!ft_strncmp("R ", line, 2))
		return (getres(line, data));
	else if (!ft_strncmp("NO ", line, 3))
		return (getnord(line, data));
	else if (!ft_strncmp("SO ", line, 3))
		return (getsud(line, data));
	else if (!ft_strncmp("WE ", line, 3))
		return (getwest(line, data));
	else if (!ft_strncmp("EA ", line, 3))
		return (getest(line, data));
	else if (!ft_strncmp("S ", line, 2))
		return (getsprite(line, data));
	else if ((!ft_strncmp("F ", line, 2) && ft_precval(line, data, 'f')))
		return (getfloor(line, data));
	else if ((!ft_strncmp("C ", line, 2) && ft_precval(line, data, 'c')))
		return (getsky(line, data));
	else if (!*line)
	{
		free(line);
		return (1);
	}
	free(line);
	return (0);
}

t_param		*file_parsing(int fd, t_list **lst, t_all *all)
{
	char		*tmp;
	char		res;
	t_param		*data;

	if (!(data = (t_param*)malloc(sizeof(t_param))))
		freeall(all, 1);
	initdata(data, fd);
	while ((res = get_next_line(fd, &tmp) > 0))
	{
		if (flagparsing(ft_strtrim(tmp, " \t\v\n\b\f\r"), data) > 0)
		{
			free(tmp);
			continue ;
		}
		checkflag(tmp, data);
		ft_lstadd_back(lst, ft_lstnew(tmp));
		while ((res = get_next_line(fd, &tmp) > 0))
			ft_lstadd_back(lst, ft_lstnew(tmp));
		ft_lstadd_back(lst, ft_lstnew(tmp));
		break ;
	}
	ft_iferror(res, lst);
	close(fd);
	return (map_parsing(*lst, data));
}

void		freeall(t_all *all, char c)
{
	int i;

	i = 0;
	if (c)
		free(all->win);
	free(all->img);
	free(all->rnd);
	free(all->spt);
	free(all->gun);
	free(all->sfl);
	while (i < 2)
		free(all->hud[i++]);
	if (!(all->win->mlx))
		free(all->win->mlx);
	if (c)
		generic_error();
}

void		generic_error(void)
{
	printf("\tError\n\tMalloc failed somewhere\n\tsorry");
	exit(-1);
}
