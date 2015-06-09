/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:33:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/09 22:00:28 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void	ft_move2(t_env *e)
{
	double	old_dir;
	double	old_plane;

	if (e->kb[RIGHT])
	{
		old_dir = e->dir.x;
		e->dir.x = e->dir.x * cos(-ROT_SPEED) - e->dir.y * sin(-ROT_SPEED);
		e->dir.y = old_dir * sin(-ROT_SPEED) + e->dir.y * cos(-ROT_SPEED);
		old_plane = e->plane.x;
		e->plane.x = e->plane.x * cos(-ROT_SPEED) - e->plane.y *
			cos(-ROT_SPEED);
		e->plane.y = old_plane * sin(-ROT_SPEED) + e->plane.y * cos(-ROT_SPEED);
	}
	else if (e->kb[LEFT])
	{
		old_dir = e->dir.x;
		e->dir.x = e->dir.x * cos(ROT_SPEED) - e->dir.y * sin(ROT_SPEED);
		e->dir.y = old_dir * sin(ROT_SPEED) + e->dir.y * cos(ROT_SPEED);
		old_plane = e->plane.x;
		e->plane.x = e->plane.x * cos(ROT_SPEED) - e->plane.y * sin(ROT_SPEED);
		e->plane.y = old_plane * sin(ROT_SPEED) + e->plane.y * cos(ROT_SPEED);
	}
}

void		ft_move(t_env *e)
{
	if (e->kb[UP])
	{
		if (W_LVL[(int)(e->pos.x + e->dir.x * MV_SPEED)][(int)e->pos.y] < 9)
			e->pos.x += e->dir.x * MV_SPEED;
		if (W_LVL[(int)(e->pos.x)][(int)(e->pos.y + e->dir.y * MV_SPEED)] < 9)
			e->pos.y += e->dir.y * MV_SPEED;
	}
	else if (e->kb[DOWN])
	{
		if (W_LVL[(int)(e->pos.x - e->dir.x * MV_SPEED)][(int)e->pos.y] < 9)
			e->pos.x -= e->dir.x * MV_SPEED;
		if (W_LVL[(int)(e->pos.x)][(int)(e->pos.y - e->dir.y * MV_SPEED)] < 9)
			e->pos.y -= e->dir.y * MV_SPEED;
	}
	ft_move2(e);
}
