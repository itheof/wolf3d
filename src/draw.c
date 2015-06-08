/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tvallee <tvallee@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/04 16:44:22 by tvallee           #+#    #+#             */
/*   Updated: 2015/06/08 18:21:12 by tvallee          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wolf3d.h"

void	draw_line(t_env *e, t_pnt start, t_pnt end, int color)
{
	
}

void	draw(t_env *e)
{
	size_t	x;
	t_ray	ray;

	mlx_clear_window(e->mlx_ptr, e->wdw_ptr);
	e->img_ptr = mlx_new_image(e->mlx_ptr, SIZE_L, SIZE_H);
	x = 0;
	while (x < SIZE_L)
	{
		raycast(x, &ray, e);
		x++;
	}
}
