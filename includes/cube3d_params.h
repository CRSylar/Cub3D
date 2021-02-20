/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cube3d.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 12:07:25 by cromalde          #+#    #+#             */
/*   Updated: 2021/01/26 18:30:55 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUBE3D_PARAMS_H
# define CUBE3D_PARAMS_H

# include <stdio.h>
# include <stdlib.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "struct.h"

# define X 0
# define Y 1
# define TY 2

void				freeall(t_all *all, char c);

t_param				*file_parsing(int fd, t_list **lst, t_all *all);
t_param				*map_parsing(t_list *lst, t_param *data);
char				flagparsing(char *line, t_param *data);

void				initdata(t_param *data, int fd);
int					ft_precval(char *line, t_param *data, char c);

void				checkflag(char *line, t_param *data);
void				checkcolors(char *line, int *value, t_param *data);
char				getres(char *line, t_param *data);
char				getnord(char *line, t_param *data);
char				getsud(char *line, t_param *data);
char				getwest(char *line, t_param *data);
char				getest(char *line, t_param *data);
char				getsprite(char *line, t_param *data);
char				getfloor(char *line, t_param *data);
char				getsky(char *line, t_param *data);

void				cleanxit(char *line, t_param *data, char c);
void				ft_closeall(t_list **lst, t_param *data, char **map);
void				ft_lst_dleete(t_list *lst);
void				generic_error();

void				firstnlast(t_param *data, char **map, int *y);
char				checkpossibilities(char **map, int *i, t_param *data);
char				secondcheck(char *map, int *i);
char				checkline(char **map, int *i, t_param *data);
char				charset(char str, char *set);
int					setspace(char *c);

void				save_obj(char **map, int *coord, t_param *data);
void				buildmap(t_list *lst, char **map);

#endif
