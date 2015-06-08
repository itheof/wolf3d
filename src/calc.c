/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calc.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/08 16:28:03 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 18:22:21 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

static void		init_ray(t_pnt *delta_dist, t_pnt *side_dist, t_ray *ray, t_env *e)
{
	ray->ray_pos.x = e->pos.x;
	ray->ray_pos.y = e->pos.y;
	ray->ray_dir.x = e->dir.x + e->plane.x * (2 * ray->x / SIZE_L - 1);
	ray->ray_dir.y = e->dir.y + e->plane.y * (2 * ray->x / SIZE_L - 1);
	ray->map.x = (int)ray->ray_pos.x;
	ray->map.y = (int)ray->ray_pos.y;
	delta_dist->x = sqrt(1 + pow(ray->ray_dir.y, 2) / pow(ray->ray_dir.x, 2));
	delta_dist->y = sqrt(1 + pow(ray->ray_dir.x, 2) / pow(ray->ray_dir.y, 2));
	ray->hit = 0;
	ray->step.x = (ray->ray_dir.x < 0) ? -1 : 1;
	ray->step.y = (ray->ray_dir.y < 0) ? -1 : 1;
	side_dist->x = (ray->ray_dir.x < 0) ? (ray->ray_pos.x - ray->map.x) *
		delta_dist->x : (ray->map.x + 1.0 - ray->ray_pos.x) * delta_dist->x;
	side_dist->y = (ray->ray_dir.y < 0) ? (ray->ray_pos.y - ray->map.y) *
		delta_dist->y : (ray->map.y + 1.0 - ray->ray_pos.y) * delta_dist->y;
}

static double	proceed_dda(t_ray *ray, t_pnt *side_dist, t_pnt *delta_dist,
		t_env *e)
{
	while (!ray->hit)
	{
		if (side_dist->x < side_dist->y)
		{
			side_dist->x += delta_dist->x;
			ray->map.x += ray->step.x;
			ray->side = 0;
		}
		else
		{
			side_dist->y = delta_dist->y;
			ray->map.x += ray->step.y;
			ray->side = 1;
		}
		ray->hit = (W_LVL[(int)(ray->map.x)][(int)(ray->map.y)] < 9) ? 1 : 0;
	}
	if (ray->side)
		return (fabs((ray->map.y - ray->ray_pos.y + (1 - ray->step.y) / 2)
					/ ray->ray_dir.y));
	else
		return (fabs((ray->map.x - ray->ray_pos.x + (1 - ray->step.x) / 2)
					/ ray->ray_dir.x));
}

static int		get_ray_color(t_ray *ray, t_env *e)
{
	int color;

	

	if (ray->side)
		color = color / 2;
}

void			raycast(size_t x, t_ray *ray, t_env *e)
{
	t_pnt	side_dist;
	t_pnt	delta_dist;
	double	perp_walldist;

	ray->x = x;
	init_ray(&delta_dist, &side_dist, ray, e);
	perp_walldist = proceed_dda(ray, &side_dist, &delta_dist, e);
	ray->line_height = abs((int)(SIZE_H / perp_walldist));
	ray->draw_start = -ray->line_height / 2 + SIZE_H / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + SIZE_H / 2;
	if (ray->draw_end >= SIZE_H)
		ray->draw_end = SIZE_H - 1;
	ray->color = get_ray_color(ray, e);
}
