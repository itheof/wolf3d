/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:33:01 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/13 13:59:18 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		ft_move2(t_env *e, double frame_time)
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
			sin(-ROT_SPEED);
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

static double	ft_set_speed(t_env *e)
{
	if (e->time == 0)
		e->time = SDL_GetTicks();
	else
	{
		e->old_time = e->time;
		e->time = SDL_GetTicks();
		return ((e->time - e->old_time) / 1000.0);
	}
	return (0);
}

static void		ft_print_fps(t_env *e, double frame_time)
{
	char		*str;
	static int	i = 0;

	if (i == 20 && (i = 0) == 0)
	{
		asprintf(&str, (frame_time > 100) ? "Wolf3D: level %d/%d, %.1f" :
				"Wolf3D: level %d/%d, %.2ffps", e->current_lvl + 1,
				ft_lstlen(e->levels), 1.0 / frame_time);
		SDL_SetWindowTitle(e->sdl_wdw, str);
		free(str);
	}
	else
		i++;
}

void			ft_move(t_env *e)
{
	double	frame_time;

	frame_time = ft_set_speed(e);
	ft_print_fps(e, frame_time);
	if (e->kb[UP])
	{
		if (HELL1)
			e->pos.x += e->dir.x * MV_SPEED;
		if (HELL2)
			e->pos.y += e->dir.y * MV_SPEED;
	}
	else if (e->kb[DOWN])
	{
		if (HELL3)
			e->pos.x -= e->dir.x * MV_SPEED;
		if (HELL4)
			e->pos.y -= e->dir.y * MV_SPEED;
	}
	ft_move2(e, frame_time);
}
