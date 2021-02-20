/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/26 11:45:18 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/10 17:10:12 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAIN_H
# define MAIN_H

# include "cube3d_params.h"
# include "../minilibx1/mlx.h"
# include "struct.h"
# include <math.h>
# include <unistd.h>
# include <stdlib.h>

# define ROT		0.04
# define MOV		0.08
# define KRR		0b10000000
# define KLR		0b01000000
# define KA			0b00100000
# define KW			0b00010000
# define KD			0b00001000
# define KS			0b00000100
# define ESC		0b00000010
# define PUP		0b00000001
# define PDW		0b00000010
# define CRC		0b00000100
# define JMP		0b00001000
# define SHT		0b00010000

# define WPNFRIC	0.5
# define WPNLIM		5
# define WPNLIM1	10
# define WPEND		15
# define WPNSTOP	1
# define WPNSHOT	2
# define WPNSHOT1	3

# define MIN(x,y) ((x < y) ? x : y)

int		save_image_to_bmp_file(t_all *all, int width, int height);

void	checkcub(const char *file);
void	set_screen_size(void *mlx, int *rex, int *rey);
void	storetext(t_all *all);

void	initgun(t_all *all);
void	imginit(t_img *img, t_param *data);
void	initrend(int x, t_rend *rend, t_param *data, t_img *img);
void	prepare_hud(t_all *all);
void	prepare_sprite(t_all *all, t_list *temp);

void	startrend(t_all *all);
void	calcstep(t_rend *rend, t_img *img);
void	waitforhit(t_rend *rend, t_param *data);
void	getdirection(t_rend *rend, t_img *img);
void	wallprepare(t_rend *rend, t_param *data, t_img *img, t_text **text);
void	putwall(t_all *all, t_text **text, double *zbuffer);
void	puthud(t_all *all);
void	putgun(t_all *all);
void	put_floornsky(t_all *all, t_img *img, t_win *win);
void	putspt(t_all *all, t_text *text, double *zbuffer, t_list *it);

int		keypressed(int key, t_all *all);
int		keyreleased(int key, t_all *all);
int		krend(t_all *all);

void	move_right(t_all *all);
void	move_left(t_all *all);
void	move_back(t_all *all);
void	move_forward(t_all *all);
void	counter_rotation(t_all *all, double c);
void	wise_rotation(t_all *all, double c);
void	pitchup(t_all *all);
void	pitchdw(t_all *all);
void	crouch(t_all *all);
void	jump(t_all *all);
void	jumpdw(t_all *all);

void	calcspr(t_list *it, t_spr *spt, t_img *img, t_param *data);
void	calcdistance(t_all *all);
t_list	*findmin(t_all *all, t_list *prec);
t_list	*sortsprite(t_all *all);

void	shoot(t_all *all);
int		ammodda(t_all *all);

int		mousevent(t_all *all);
int		mouse(int x, int y, t_all *all);

t_text	*get_text(char *path, t_win *img);
int		getcolor(int *color);
int		addshade(t_all *all, t_text **text, char c, t_list *it);
void	my_mlx_pixel_put(t_win *data, int x, int y, int color);

void	removeobj(t_all **all, int y, int x);
void	free_obj(t_all **all, t_list *tmp);
void	generic_error();
int		exitgame(t_all *all);
int		theend(t_all *all, char c);

#endif
