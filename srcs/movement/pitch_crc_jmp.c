/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pitch_crc_jmp.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:33:07 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:33:09 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

void	pitchup(t_all *all)
{
	if (all->img->pitch + 100 * MOV < 360)
		all->img->pitch = all->img->pitch + 100 * MOV;
}

void	pitchdw(t_all *all)
{
	if (all->img->pitch - 100 * MOV > -360)
		all->img->pitch = all->img->pitch - 100 * MOV;
}

void	crouch(t_all *all)
{
	if (!(int)all->img->posz)
	{
		all->img->posz = -200 - 100 * MOV;
		all->crc = 0.015;
	}
	else if (all->img->posz)
	{
		all->img->posz = 0.5;
		all->crc = 150;
	}
	all->keyb ^= CRC;
}

void	jump(t_all *all)
{
	if (all->img->posz == -200 - 100 * MOV)
		all->img->posz = 0.5;
	if (all->img->posz < 360 && !all->c)
		all->img->posz += ((3200 / pow(all->img->posz, 0.34)) * MOV);
	else if (all->img->posz >= 360)
		all->c = 1;
	if (all->img->posz > 0 && all->c)
		all->img->posz -= (3200 / pow(all->img->posz, 0.34)) * MOV;
	else if (all->img->posz <= 0)
	{
		all->c = 0;
		all->keyb ^= JMP;
		all->img->posz = 0.5;
		all->crc = 150;
		system("afplay ./sound/wolf/Thud!.wav &");
	}
}
