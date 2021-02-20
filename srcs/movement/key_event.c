/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cromalde <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/04 16:29:07 by cromalde          #+#    #+#             */
/*   Updated: 2021/02/04 16:29:09 by cromalde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/main.h"

int			keypressed(int key, t_all *all)
{
	if (key == 53)
		all->keyn |= ESC;
	if (key == 124)
		all->keyn |= KRR;
	if (key == 123)
		all->keyn |= KLR;
	if (key == 13)
		all->keyn |= KW;
	if (key == 1)
		all->keyn |= KS;
	if (key == 0)
		all->keyn |= KA;
	if (key == 2)
		all->keyn |= KD;
	if (key == 126)
		all->keyb |= PUP;
	if (key == 125)
		all->keyb |= PDW;
	if (key == 257)
		all->keyb |= CRC;
	if (key == 49)
		all->keyb |= JMP;
	if (key == 12)
		all->keyb |= SHT;
	return (0);
}

int			keyreleased(int key, t_all *all)
{
	if (key == 124)
	{
		all->keyn ^= KRR;
		all->mom = pow(10, -25);
	}
	if (key == 123)
	{
		all->keyn ^= KLR;
		all->mom = pow(10, -25);
	}
	if (key == 13)
		all->keyn ^= KW;
	if (key == 1)
		all->keyn ^= KS;
	if (key == 0)
		all->keyn ^= KA;
	if (key == 2)
		all->keyn ^= KD;
	if (key == 126)
		all->keyb ^= PUP;
	if (key == 125)
		all->keyb ^= PDW;
	if (key == 12)
		all->gun->check = 1;
	return (0);
}

static void	move_loop(t_all *all)
{
	if (all->keyn & KRR)
		counter_rotation(all, 1);
	if (all->keyn & KLR)
		wise_rotation(all, 1);
	if (all->keyn & KW)
		move_forward(all);
	if (all->keyn & KS)
		move_back(all);
	if (all->keyn & KA)
		move_left(all);
	if (all->keyn & KD)
		move_right(all);
}

int			krend(t_all *all)
{
	move_loop(all);
	if (all->keyn & ESC)
		exitgame(all);
	if (all->keyb & PUP)
		pitchup(all);
	if (all->keyb & PDW)
		pitchdw(all);
	if (all->keyb & CRC)
		crouch(all);
	if (all->keyb & JMP)
		jump(all);
	if (all->keyb & SHT)
		shoot(all);
	startrend(all);
	return (1);
}
