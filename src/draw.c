/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:44:22 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/04 18:24:37 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw(t_env *e)
{
	size_t	x;
	t_pnt	ray_pos;
	t_pnt	ray_dir;
	double	camera;

	mlx_clear_window(e->mlx_ptr, e->wdw_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, SIZE_L, SIZE_H);
	x = 0;
	while (x< SIZE_L)
	{
		camera = 2 * x / SIZE_L - 1;
		ray_pos.x = e->pos.x;
		ray_pos.y = e->pos.y;
		ray_dir.x = e->dir.x + e->plane.x * camera;
		ray_dir.y = e->dir.y + e->plane.y * camera;
		
		x++;
	}
}
