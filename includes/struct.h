/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 17:11:32 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 17:11:34 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H

typedef	struct		s_sky_floor_texture
{
	float			raydirx0;
	float			raydiry0;
	float			raydiry1;
	float			raydirx1;
	float			camz;
	float			rowdis;
	float			flstpx;
	float			flstpy;
	float			floorx;
	float			floory;
	int				celx;
	int				cely;
	int				tx;
	int				ty;
}					t_sfl;

typedef struct		s_param
{
	int				resx;
	int				resy;
	void			*no;
	void			*so;
	void			*we;
	void			*ea;
	void			*spr;
	void			*skypth;
	void			*flpth;
	int				floor[3];
	int				sky[3];
	int				fd;
	char			spawn;
	double			spx;
	double			spy;
	char			**vmap;
	t_list			*lst;
}					t_param;

typedef	struct		s_window
{
	void			*mlx;
	void			*mlxwin;
	void			*img;
	char			*addr;
	int				endian;
	int				bits_per_pixel;
	int				line_length;
}					t_win;

typedef struct		s_img
{
	double			posx;
	double			posy;
	double			dirx;
	double			diry;
	double			planex;
	double			planey;
	double			pitch;
	double			posz;
	int				nspr;
}					t_img;

typedef struct		s_text
{
	void			*txt;
	char			*addr;
	int				width;
	int				height;
	int				endian;
	int				bpp;
	int				hline;
}					t_text;

typedef	struct		s_rend
{
	int				mapx;
	int				mapy;
	int				hline;
	int				dstart;
	int				dend;
	double			camx;
	double			rayx;
	double			rayy;
	double			sdx;
	double			sdy;
	double			deltax;
	double			deltay;
	double			waldist;
	double			wallx;
	int				stepx;
	int				stepy;
	char			hit;
	char			side;
	int				texx;
	int				texy;
	double			step;
	double			texpos;
}					t_rend;

typedef	struct		s_sprite
{
	double			spritex;
	double			spritey;
	double			invdet;
	double			trasfx;
	double			trasfy;
	int				screenx;
	int				vmscreen;
	int				spriteh;
	int				dstarty;
	int				dendy;
	int				dstartx;
	int				dendx;
	int				spritew;
	int				stripe;
	int				d;
}					t_spr;

typedef	struct		s_gun
{
	t_text			*tex[8];
	char			status;
	double			friction;
	double			tfric;
	char			check;
	int				gunx;
	int				guny;
}					t_gun;

typedef	struct		s_obst
{
	double			obx;
	double			oby;
	t_text			*obtxt[3];
	char			type;
	double			dist;
	int				count;
}					t_obst;

typedef struct		s_all
{
	t_img			*img;
	t_param			*data;
	t_win			*win;
	t_rend			*rnd;
	t_spr			*spt;
	t_sfl			*sfl;
	t_gun			*gun;
	t_list			*it;
	t_text			*hud[2];
	unsigned char	keyn;
	unsigned char	keyb;
	char			c;
	double			crc;
	char			save;
	double			mom;
	double			life;
	int				enemy;
	int				ammo;
}					t_all;

#endif
